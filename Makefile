GLIB_FLGS = $(shell pkg-config --cflags --libs glib-2.0)

main:
	gcc main.c utilidades.c dijkstra.c $(GLIB_FLGS) -o algoritmo_dijsktra

.PHONY: clean

clean:
	rm -f algoritmo_dijsktra
