
# Campus Route Finder Using Graphs

## Project Overview
Campus Route Finder is a Data Structures and Algorithms mini project developed using C programming.

It represents campus locations as vertices and paths between locations as edges. It helps users find the shortest route and explore connected locations.

## Technologies Used
- Programming Language: C
- Data Structure: Graph
- Graph Representation: Adjacency List
- Algorithms: Breadth First Search (BFS) and Depth First Search (DFS)
- Compiler: GCC
- Editor: Visual Studio Code

## Campus Locations
The graph contains 8 campus locations:

1. Main Gate
2. Library
3. Block 1
4. Block 2
5. Cafeteria
6. Auditorium
7. Parking
8. Lab

## Features
- Display all campus locations.
- Display graph using adjacency list.
- Find the shortest route using BFS.
- Explore reachable locations using DFS.
- Identify disconnected locations.
- Interactive menu-driven interface.

## Algorithms Used

### 1. Breadth First Search (BFS)
BFS explores the graph level by level using a queue. It finds a route containing the minimum number of edges in an unweighted graph.

Time Complexity: O(V + E)

### 2. Depth First Search (DFS)
DFS explores a graph by visiting a vertex and recursively exploring its unvisited adjacent vertices.

Time Complexity: O(V + E)

## Space Complexity
- BFS: O(V)
- DFS: O(V) auxiliary space for visited array and recursion stack.
- Adjacency List: O(V + E)

Here, V represents vertices and E represents edges.

## How to Run

1. Clone or download this repository.
2. Open the folder in VS Code.
3. Open the terminal.
4. Compile the program:

```bash
gcc campus_route_finder.c -o campus
```

5. Execute:

```bash
./campus
```

## Test Cases

| Test | Input | Expected Output |
|---|---|---|
| 1 | Main Gate to Library | Direct route |
| 2 | Main Gate to Auditorium | Shortest route with 3 edges |
| 3 | Main Gate to Parking | No route exists |


## Sample Output
<img width="1054" height="1280" alt="image" src="https://github.com/user-attachments/assets/12adad27-3804-49ad-9238-ef24d6d6af92" />
<img width="960" height="1280" alt="image" src="https://github.com/user-attachments/assets/0d152e61-0d49-4aa6-b93e-1e002e4f6cc4" />
<img width="1112" height="1280" alt="image" src="https://github.com/user-attachments/assets/43822ec4-5b15-4efc-8098-9022dcdad249" />
<img width="960" height="1280" alt="image" src="https://github.com/user-attachments/assets/05f42e35-8a48-4b34-9f1c-87d7cca36786" />




## Project Objective
The objective is to understand graph representation, BFS, DFS, queues, recursion, shortest paths, and reachability.

## Author
Nancy Kumari

## Conclusion
This project demonstrates how graph data structures and traversal algorithms can be used to solve real-life campus navigation problems.
