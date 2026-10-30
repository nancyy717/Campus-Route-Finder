
#include <stdio.h>
#include <stdlib.h>

#define V 8

// Structure for adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Campus location names
char* locations[V] = {
    "Main Gate",
    "Library",
    "Block 1",
    "Block 2",
    "Cafeteria",
    "Auditorium",
    "Parking",
    "Lab"
};

// Graph adjacency list
struct Node* adj[V];

// Create a new node
struct Node* createNode(int v) {
    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->vertex = v;
    newNode->next = NULL;

    return newNode;
}

// Add an edge between two locations
void addEdge(int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = adj[src];
    adj[src] = newNode;

    newNode = createNode(src);
    newNode->next = adj[dest];
    adj[dest] = newNode;
}

// Display all campus locations
void displayLocations() {
    printf("\n----- CAMPUS LOCATIONS -----\n");

    for (int i = 0; i < V; i++) {
        printf("%d. %s\n", i, locations[i]);
    }
}

// Display graph using adjacency list
void displayGraph() {
    printf("\n----- CAMPUS GRAPH -----\n");

    for (int i = 0; i < V; i++) {
        struct Node* temp = adj[i];

        printf("%s -> ", locations[i]);

        while (temp != NULL) {
            printf("%s -> ", locations[temp->vertex]);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

// Breadth First Search - shortest route
void BFS(int source, int destination) {
    int visited[V] = {0};
    int parent[V];

    int queue[V];
    int front = 0, rear = 0;

    for (int i = 0; i < V; i++)
        parent[i] = -1;

    visited[source] = 1;
    queue[rear++] = source;

    while (front < rear) {
        int current = queue[front++];

        if (current == destination)
            break;

        struct Node* temp = adj[current];

        while (temp != NULL) {
            int next = temp->vertex;

            if (!visited[next]) {
                visited[next] = 1;
                parent[next] = current;
                queue[rear++] = next;
            }

            temp = temp->next;
        }
    }

    if (!visited[destination]) {
        printf("\nNo route exists between %s and %s.\n",
               locations[source], locations[destination]);
        return;
    }

    // Reconstruct shortest path
    int path[V], count = 0;
    int current = destination;

    while (current != -1) {
        path[count++] = current;
        current = parent[current];
    }

    printf("\nShortest route using BFS:\n");

    for (int i = count - 1; i >= 0; i--) {
        printf("%s", locations[path[i]]);

        if (i > 0)
            printf(" -> ");
    }

    printf("\nTotal edges: %d\n", count - 1);
}

// Depth First Search
void DFS(int vertex, int visited[]) {
    visited[vertex] = 1;

    printf("%s ", locations[vertex]);

    struct Node* temp = adj[vertex];

    while (temp != NULL) {
        int next = temp->vertex;

        if (!visited[next]) {
            DFS(next, visited);
        }

        temp = temp->next;
    }
}

// Display reachable and disconnected locations
void showReachable(int source) {
    int visited[V] = {0};

    printf("\nDFS Traversal:\n");
    DFS(source, visited);

    printf("\n\nReachable locations from %s:\n",
           locations[source]);

    for (int i = 0; i < V; i++) {
        if (visited[i])
            printf("%s\n", locations[i]);
    }

    printf("\nDisconnected locations:\n");

    int found = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            printf("%s\n", locations[i]);
            found = 1;
        }
    }

    if (!found)
        printf("None\n");
}

// Main function
int main() {
    int choice, source, destination;

    // Initialize adjacency list
    for (int i = 0; i < V; i++)
        adj[i] = NULL;

    // Add campus connections
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(2, 4);
    addEdge(3, 5);
    addEdge(4, 5);

    // Separate connected component
    addEdge(6, 7);

    printf("====================================\n");
    printf("       CAMPUS ROUTE FINDER\n");
    printf("====================================\n");

    do {
        printf("\n1. Display Campus Locations");
        printf("\n2. Display Graph");
        printf("\n3. Find Shortest Route (BFS)");
        printf("\n4. Explore Locations (DFS)");
        printf("\n5. Exit");

        printf("\n\nEnter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            break;
        }

        switch (choice) {

            case 1:
                displayLocations();
                break;

            case 2:
                displayGraph();
                break;

            case 3:
                displayLocations();

                printf("\nEnter source location number: ");
                scanf("%d", &source);

                printf("Enter destination location number: ");
                scanf("%d", &destination);

                if (source < 0 || source >= V ||
                    destination < 0 || destination >= V) {
                    printf("Invalid location number!\n");
                } else {
                    BFS(source, destination);
                }
                break;

            case 4:
                displayLocations();

                printf("\nEnter starting location number: ");
                scanf("%d", &source);

                if (source < 0 || source >= V) {
                    printf("Invalid location number!\n");
                } else {
                    showReachable(source);
                }
                break;

            case 5:
                printf("\nThank you for using Campus Route Finder!\n");
                break;

            default:
                printf("\nInvalid choice! Try again.\n");
        }

    } while (choice != 5);

    return 0;
}
