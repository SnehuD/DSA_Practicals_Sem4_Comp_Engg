/*There are flight paths between cities. If there is a flight between city A and city B 
then there is an edge between the cities. The cost of the edge can be the time that 
flight take to reach city B from A, or t ..... */
#include <string.h>
#include <iostream>
using namespace std;
class flight {
 public:
  int am[10][10];
  char city_index[10][10];
  flight();
  int create();
  void display(int city_count);
};
flight::flight() {
  int i, j;
  for (i = 0; i < 10; i++) {
    strcpy(city_index[i], "xx");
  }
  for (i = 0; i < 10; i++) {
    for (j = 0; j < 10; j++) {
      am[i][j] = 0;
    }
  }
}
int flight::create() {
  int city_count = 0, j, si, di, wt;
  char s[10], d[10], c;
  do {
    cout << "\n\nEnter Source City : ";
    cin >> s;
    cout << "\nEnter Destination City : ";
    cin >> d;
    for (j = 0; j < 10; j++) {
      if (strcmp(city_index[j], s) == 0) break;
    }
    if (j == 10) {
      strcpy(city_index[city_count], s);
      city_count++;
    }
    for (j = 0; j < 10; j++) {
      if (strcmp(city_index[j], d) == 0) break;
    }
    if (j == 10) {
      strcpy(city_index[city_count], d);
      city_count++;
    }
    cout << "\nEnter Distance From " << s << " And " << d << " : ";
    cin >> wt;
    for (j = 0; j < 10; j++) {
      if (strcmp(city_index[j], s) == 0) si = j;
      if (strcmp(city_index[j], d) == 0) di = j;
    }
    am[si][di] = wt;
    cout << "\nDo you want to add more cities.....(y/n) : ";
    cin >> c;
  } while (c == 'y' || c == 'Y');
  return (city_count);
}
void flight::display(int city_count) {
  int i, j;
  cout << "\n\nDisplaying Adjacency Matrix : \n\n";
  cout << "\t\t " << city_index[0];
  for (i = 1; i < city_count; i++) cout << "\t " << city_index[i];
  cout << "\n\n";
  for (i = 0; i < city_count; i++) {
    cout << city_index[i];
    for (j = 0; j < city_count; j++) {
      cout << "\t\t" << am[i][j];
    }
    cout << "\n\n";
  }
}
int main() {
  flight f;
  int n, city_count;
  char c;
  do {
    cout << "\n***** Flight Main Menu *****";
    cout << "\n\n1.Create Graph\n2.Display Adjacency Matrix\n3.Exit";
    cout << "\n\nEnter your choice : ";
    cin >> n;
    switch (n) {
      case 1:
        city_count = f.create();
        break;
      case 2:
        f.display(city_count);
        break;
      case 3:
        return 0;
    }
    cout << "\nDo you Want to Continue in Main Menu....(y/n) : ";
    cin >> c;
  } while (c == 'y' || c == 'Y');
  return 0;
}
/* Graph:
A graph is a non-linear data structure that consists of a set of vertices (nodes) connected by edges. Graphs are used to represent relationships and connections between objects. They can be used to model real-world scenarios such as social networks, transportation networks, and computer networks.

Types of Graphs:
1. Directed Graph (Digraph): A graph in which edges have a specific direction.
2. Undirected Graph: A graph in which edges do not have a specific direction.
3. Weighted Graph: A graph in which edges have associated weights or costs.
4. Unweighted Graph: A graph in which edges do not have any weights.

Representation of Graph using Adjacency Matrix:
- An adjacency matrix is a 2D array of size V x V, where V is the number of vertices in the graph.
- The value at matrix[i][j] represents the presence or absence of an edge between vertices i and j.
- For an unweighted graph, the value can be 0 or 1.
- For a weighted graph, the value can be the weight of the edge or a special value (e.g., infinity) to represent the absence of an edge.

Representation of Graph using Adjacency List:
- An adjacency list is a collection of linked lists or arrays.
- Each vertex has a list of adjacent vertices, representing the edges in the graph.
- The space required to store an adjacency list is proportional to the number of edges in the graph.

Breadth-First Search (BFS):
- BFS is a graph traversal algorithm that explores all the vertices of a graph in breadth-first order.
- Starting from a given vertex, BFS visits all its neighbors before visiting their neighbors.
- BFS uses a queue data structure to keep track of the vertices to visit.
- It is used to find the shortest path in an unweighted graph.

Depth-First Search (DFS):
- DFS is a graph traversal algorithm that explores all the vertices of a graph in depth-first order.
- Starting from a given vertex, DFS visits one neighbor, then explores its neighbors recursively.
- DFS uses a stack data structure or recursive calls to keep track of the vertices to visit.
- It is used to detect cycles in a graph, find connected components, and perform topological sorting.

In summary, a graph is a data structure consisting of vertices and edges. 
It can be represented using an adjacency matrix or adjacency list. 
BFS and DFS are graph traversal algorithms used to visit all vertices in different orders. 
BFS is used for finding the shortest path, while DFS is used for detecting cycles and exploring connected components. */

//-----SnehuD-----
