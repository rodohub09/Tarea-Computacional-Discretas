#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int leerGrafo(int argc, char *argv[]){

  char direccion[8+strlen(argv[argc-1])];
  strcpy(direccion, "Grafos/");
  strcat(direccion, argv[argc - 1]);
  printf("%s",direccion);
  FILE *fp = fopen(direccion,"r");
  if (fp == NULL) {
    perror("Error al abrir el archivo");
    return 1;
  }
  int cantVectores;
  fscanf(fp,"%d",&cantVectores);

  char **grafo = malloc(cantVectores*sizeof(char *));
  for(int i=0;i<cantVectores;i++){
    grafo[i] = (char *)malloc(cantVectores*sizeof(char));
    for(int j=0;j<cantVectores;j++){
      fscanf(fp," %c",&grafo[i][j]);
      printf("%c ",grafo[i][j]);
    }
    printf("\n");
  }


  limpiar_matriz(grafo);
  fclose(fp);

  return 0;
}

