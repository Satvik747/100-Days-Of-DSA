/*
Problem Statement:
Find shortest distances from source vertex in a weighted graph with non-negative weights.

Input Format:
n m
u v w
source

Output Format:
Distances to all vertices.

Sample Input:
5 6
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1
1

Sample Output:
0 2 3 9 6

Explanation:
Shortest distances computed via priority queue.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

struct Node* createNode(int v, int w) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->vertex = v;
    node->weight = w;
    node->next = NULL;
    return node;
}

// Min Heap structure
struct MinHeap {
    int* dist;
    int* vertex;
    int size;
};

void swap(struct MinHeap* heap, int i, int j) {
    int tempDist = heap->dist[i];
    int tempV = heap->vertex[i];
    heap->dist[i] = heap->dist[j];
    heap->vertex[i] = heap->vertex[j];
    heap->dist[j] = tempDist;
    heap->vertex[j] = tempV;
}

void heapifyUp(struct MinHeap* heap, int idx) {
    while (idx && heap->dist[idx] < heap->dist[(idx - 1) / 2]) {
        swap(heap, idx, (idx - 1) / 2);
        idx = (idx - 1) / 2;
    }
}

void heapifyDown(struct MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size && heap->dist[left] < heap->dist[smallest])
        smallest = left;

    if (right < heap->size && heap->dist[right] < heap->dist[smallest])
        smallest = right;

    if (smallest != idx) {
        swap(heap, idx, smallest);
        heapifyDown(heap, smallest);
    }
}

void insertHeap(struct MinHeap* heap, int v, int d) {
    heap->vertex[heap->size] = v;
    heap->dist[heap->size] = d;
    heapifyUp(heap, heap->size);
    heap->size++;
}

int extractMin(struct MinHeap* heap, int* d) {
    int v = heap->vertex[0];
    *d = heap->dist[0];

    heap->vertex[0] = heap->vertex[heap->size - 1];
    heap->dist[0] = heap->dist[heap->size - 1];
    heap->size--;

    heapifyDown(heap, 0);
    return v;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node** adj = (struct Node**)malloc((n + 1) * sizeof(struct Node*));
    for (int i = 1; i <= n; i++)
        adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        struct Node* newNode = createNode(v, w);
        newNode->next = adj[u];
        adj[u] = newNode;
    }

    int src;
    scanf("%d", &src);

    int* dist = (int*)malloc((n + 1) * sizeof(int));
    int* visited = (int*)calloc(n + 1, sizeof(int));

    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    struct MinHeap* heap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    heap->dist = (int*)malloc(n * sizeof(int));
    heap->vertex = (int*)malloc(n * sizeof(int));
    heap->size = 0;

    insertHeap(heap, src, 0);

    while (heap->size > 0) {
        int currentDist;
        int u = extractMin(heap, &currentDist);

        if (visited[u]) continue;
        visited[u] = 1;

        struct Node* temp = adj[u];
        while (temp) {
            int v = temp->vertex;
            int w = temp->weight;

            if (!visited[v] && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                insertHeap(heap, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }

    for (int i = 1; i <= n; i++) {
        struct Node* temp = adj[i];
        while (temp) {
            struct Node* next = temp->next;
            free(temp);
            temp = next;
        }
    }

    free(adj);
    free(dist);
    free(visited);
    free(heap->dist);
    free(heap->vertex);
    free(heap);

    return 0;
}