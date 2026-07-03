#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 10

typedef struct {
    int vertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

void initGraph(Graph *g, int newVertices) {
    g->vertices = newVertices;

    for (int i = 0; i < newVertices; i++) {
        for (int j = 0; j < newVertices; j++) {
            g->adjacencyMatrix[i][j] = 0;
        }
    }
}

void addEdge(Graph *g, int source, int destination) {

    if (source == destination) {
        puts("El origrn y el destino no pueden ser iguales. \n");
        return;
    }
    if (source < g->vertices && destination < g->vertices) {
        g->adjacencyMatrix[source][destination] = 1;
        g->adjacencyMatrix[destination][source] = 1;
    } else {
        puts("El origen o destino no corresponden a los nodos definidos en el grafo");
        return;
    }
}

bool hasEdge(Graph *g, int source, int destination) {
    bool has = false;

    if (source < g->vertices && destination < g->vertices) {
        if (g->adjacencyMatrix[source][destination] == 1) {
            has = true;
        }
        
    } else {
        puts("El origen o el destino no corresponden a los nodos definidos en el grafo \n");
        return;
    }

    return has;
}

void removeEdge(Graph *g, int source, int destination) {
    if(hasEdge(g, source, destination)){
        g->adjacencyMatrix[source][destination] = 0;
        g->adjacencyMatrix[destination][source] = 0;
    } else {
        puts("No se puede eliminar la arista entre los nodos definidos. \n");
    }
}

Graph createGraph(int vertices) {
    Graph g;

    if (vertices <= 0 || vertices > MAX_VERTICES) {
        puts("Cantidad de vertices superior a la permitida");
        exit(EXIT_FAILURE);
    }

    initGraph(&g, vertices);

    return g;
}

int main() {
    int vertices;

    printf("Ingrese cantidad de vertices: ");
    scanf("%d", &vertices);

    Graph graph = createGraph(vertices);

    printf("Grafo creado con %d vertices\n", graph.vertices);

    return 0;
}