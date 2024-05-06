#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define V 5 // Number of vertices

// Queue node structure
struct Node {
  int data;
  struct Node* next;
};

// Function prototypes
void BFSUtil(int graph[V][V], int v, bool visited[]);
struct Node* newNode(int data);
void enqueue(struct Node** front, int data);
void dequeue(struct Node** front);

int main() {
  /* Let us create the following graph
          0
      /     \
     1       2
    |         \
   3   ----   4 */
  int graph[V][V] = {{0, 1, 0, 0, 1},
                     {1, 0, 1, 1, 0},
                     {0, 1, 0, 0, 0},
                     {0, 1, 0, 0, 1},
                     {1, 0, 0, 1, 0}};

  bool visited[V];
  for (int i = 0; i < V; i++)
    visited[i] = false;

  // Call BFS traversal starting from vertex 0
  BFSUtil(graph, 0, visited);

  return 0;
}

// Function to create a new queue node
struct Node* newNode(int data) {
  struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
  temp->data = data;
  temp->next = NULL;
  return temp;
}

// Enqueue a new node in front of the queue
void enqueue(struct Node** front, int data) {
  struct Node* new_node = newNode(data);
  new_node->next = (*front);
  (*front) = new_node;
}

// Dequeue a node from the queue front
void dequeue(struct Node** front) {
  if (*front == NULL)
    return;

  struct Node* temp = (*front);
  (*front) = (*front)->next;
  free(temp);
}

// BFSUtil: A function to do BFS traversal of a graph from a given vertex v.
// visited[] keeps track of visited vertices
void BFSUtil(int graph[V][V], int v, bool visited[]) {
  struct Node* queue = NULL; // Queue to store the unvisited nodes

  visited[v] = true;
  enqueue(&queue, v);

  while (queue != NULL) {
    v = queue->data;
    printf("%d ", v);
    queue->data = queue->data; // (For some compilers to avoid warnings)
    dequeue(&queue);

    // Get all adjacent vertices of the dequeued vertex v
    // If a adjacent has not been visited, then mark it visited and enqueue it
    for (int i = 0; i < V; i++)
      if (graph[v][i] && !visited[i]) {
        visited[i] = true;
        enqueue(&queue, i);
      }
  }
}
