#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <glib.h>
#include <stdbool.h>
#include "utilidades.h"

int main(int argc, char *argv[]){
  int first = toupper(argv[1][0]) - 65;
  int last = toupper(argv[2][0]) - 65;
  char *input = argv[3];

  dijkstra(first, last, input);

}

void dijkstra(int first, int last, char *input){
  typedef struct{
    char anterior;
    bool visitado;
    int distancia;
  } Vertice;

  int tamaño;
  char **matriz = leerGrafo(input, &tamaño);
  Vertice vertices[15];
  Vertice vertice;
  
  for(int i = 0; i < tamaño; i++){
    if(i == first){
      vertice.anterior = first;
      vertice.visitado = true;
      vertice.distancia = 0;
    }
    else{
      vertice.visitado = false;
      vertice.distancia = INT_MAX;
    }
    
    vertices[i] = vertice;
  }
  
  GQueue *cola = g_queue_new();
  int actual;
  int tamañoCola;
  g_queue_push_tail(cola, GINT_TO_POINTER(first));
    
  while(!g_queue_is_empty(cola)){
    tamañoCola = g_queue_get_length(cola);
    
    for(int _ = 0; _ < tamañoCola; _++){
      actual = GPOINTER_TO_INT(g_queue_pop_head(cola));
      
      for(int i = 0; i < tamaño; i++){
	if(matriz[actual][i] == '1' && vertices[vertices[actual].anterior].distancia + 1 < vertices[i].distancia && !vertices[i].visitado){
	  if(i == last){
	    vertices[i].distancia = vertices[vertices[actual].anterior].distancia + 1;
	    vertices[i].anterior = actual;
	    g_queue_clear(cola);
	    break;
	  }
	  else{
	    vertices[i].distancia = vertices[vertices[actual].anterior].distancia + 1;
	    vertices[i].anterior = actual;
	    g_queue_push_tail(cola,GINT_TO_POINTER(i));
	  }
	}
      }
      vertices[actual].visitado = true;
      if(g_queue_is_empty(cola))
	break;
    }
  }

  if(vertices[last].distancia == INT_MAX)
    printf("No existe camino entre %c y %c", first+65,last+65);
  else{
    actual = last;
    printf("%c ", last + 65);
    while(actual != first){
      printf("%c ", vertices[actual].anterior + 65);
      actual = vertices[actual].anterior;
    }
    printf("\n");
  }

  limpiar_matriz(matriz);
  g_queue_free(cola);
  
}
