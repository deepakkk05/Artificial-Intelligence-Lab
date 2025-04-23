#include <stdio.h>
#include <stdlib.h>
struct node {
    struct node *next;
    int vertex;
};
typedef struct node *GNODE;
GNODE graph[20];
int visited[20];
void DFS(int i) {
    GNODE p;
    printf("\n%d", i);
    visited[i] = 1;
    p = graph[i];
    while (p != NULL) {
        i = p->vertex;
        if (!visited[i]) {
            DFS(i);
        }
        p = p->next;
    }
}
int main() {
    int N, E, i, s, d;
    GNODE q, p;
    printf("Enter no of vertices: ");
    scanf("%d", &N);
    printf("Enter no of edges: ");
    scanf("%d", &E);
    for (i = 1; i <= N; i++) {
        graph[i] = NULL; 
    for (i = 1; i <= E; i++) {
        printf("Enter source: ");
        scanf("%d", &s);
        printf("Enter destination: ");
        scanf("%d", &d);
        q = (GNODE)malloc(sizeof(struct node));
        q->vertex = d;
        q->next = NULL;
        if (graph[s] == NULL) {
            graph[s] = q;
        } else {
            p = graph[s];
            while (p->next != NULL) {
                p = p->next;
            }
            p->next = q;
        }
    }
    for (i = 1; i <= N; i++) {
        visited[i] = 0;
    }
    int start_vertex;
    printf("Enter Start Vertex for DFS: ");
    scanf("%d", &start_vertex);
    printf("DFS of graph: \n");
    DFS(start_vertex);
    printf("\n");
    return 0;
    }
}


