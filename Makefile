GLIB_FLGS = $(shell pkg-config --cflags --libs glib-2.0)

main:
	gcc main.c utilidades.c dijkstra.c $(GLIB_FLGS) -o path

.PHONY: clean

clean:
	rm -f algoritmo_dijkstra
