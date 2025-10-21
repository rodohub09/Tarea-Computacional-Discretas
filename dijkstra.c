#include <stdio.h>
#include <ctype.h>
#include <glib.h>
#include "utilidades.h"

char* dijkstra(int first, int last, char *input, int *largo){
  typedef struct{
    char anterior;
    int distancia;
  } Vertice;

  int tamaño;
  char **matriz = leerGrafo(input, &tamaño);
  Vertice vertices[15];
  Vertice vertice;

  if(first < 0 || first >= tamaño || last < 0 || last >= tamaño)
    return (char *)-1;
    
  for(int i = 0; i < tamaño; i++){
    if(i == first){
      vertice.anterior = first;
      vertice.distancia = 0;
    }
    else{
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
	if(matriz[actual][i] == '1' && vertices[actual].distancia + 1 < vertices[i].distancia){
	  if(i == last){
	    vertices[i].distancia = vertices[actual].distancia + 1;
	    vertices[i].anterior = actual;
	    g_queue_clear(cola);
	    break;
	  }
	  else{
	    vertices[i].distancia = vertices[actual].distancia + 1;
	    vertices[i].anterior = actual;
	    g_queue_push_tail(cola,GINT_TO_POINTER(i));
	  }
	}
      }
      if(g_queue_is_empty(cola))
	break;
    }
  }

  char *recorrido = malloc((vertices[last].distancia)* sizeof(char));
  int ind = 1;
  *largo = vertices[last].distancia;
  
  if(vertices[last].distancia == INT_MAX)
    return NULL;
  else{
    actual = last;
    recorrido[0] = last + 65;
    while(actual != first){
      recorrido[ind] = vertices[actual].anterior + 65;
      ind++;
      actual = vertices[actual].anterior;
    }
  }
 
  limpiar_matriz(matriz);
  g_queue_free(cola);
  
  return recorrido;
}
