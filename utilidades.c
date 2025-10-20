#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char **leerGrafo(char *input, int *tamaño){

  char direccion[8+strlen(input)];
  strcpy(direccion, "Grafos/");
  strcat(direccion, input);
  
  FILE *fp = fopen(direccion,"r");
  if (fp == NULL) {
    perror("Error al abrir el archivo");
    return 1;
  }
  int cantVectores;
  fscanf(fp,"%d",&cantVectores);
  *tamaño = cantVectores;
  
  char **grafo = malloc(cantVectores*sizeof(char *));
  for(int i=0;i<cantVectores;i++){
    grafo[i] = (char *)malloc(cantVectores*sizeof(char));
    for(int j=0;j<cantVectores;j++){
      fscanf(fp," %c",&grafo[i][j]);
    }
  }
  
  fclose(fp);

  return grafo;
}

void limpiar_matriz(char **input){
  for (int i = 0; input[i] != NULL; i++) {
    free(input[i]);
  }
  free(input);
}
