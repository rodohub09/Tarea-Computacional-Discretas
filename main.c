#include <stdio.h>
#include <ctype.h>
#include "dijkstra.h"

int main(int argc, char *argv[]){
  int first = toupper(argv[1][0]) - 65;
  int last = toupper(argv[2][0]) - 65;
  char *input = argv[3];
  int largo;
  char *recorrido = dijkstra(first, last, input, &largo);
  
  // Se verifica algún posible caso error
  if(recorrido == (char *)-1)
    printf("Uno de los vértices ingresados es inválido");
  else if(recorrido == NULL)
    printf("No existe camino entre los vértices ingresados");
  else{
    //Se printea el camino al revés para mostrarlo de inicio a fin
    for(int i = largo; i >= 0; i--)
      printf("%c ", recorrido[i]);
  }
  printf("\n");
  return 0;
}
