/* You have a business with several offices; you want to lease phone lines to connect 
them up with each other; and the phone company charges different amounts of money 
to connect different pairs of cities..... */
#include <iostream>
using namespace std;
class tree {
  int a[20][20], l, u, w, i, j, v, e, visited[20];

 public:
  void input();
  void display();
  void minimum();
};
void tree::input() {
  cout << "Enter the no. of branches: ";
  cin >> v;
  for (i = 0; i < v; i++) {
    visited[i] = 0;
    for (j = 0; j < v; j++) {
      a[i][j] = 999;
    }
  }
  cout << "\nEnter the no. of connections: ";
  cin >> e;
  for (i = 0; i < e; i++) {
    cout << "Enter the end branches of connections: " << endl;
    cin >> l >> u;
    cout << "Enter the phone company charges for this connection: ";
    cin >> w;
    a[l - 1][u - 1] = a[u - 1][l - 1] = w;
  }
}
void tree::display() {
  cout << "\nAdjacency matrix:";
  for (i = 0; i < v; i++) {
    cout << endl;
    for (j = 0; j < v; j++) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
}
void tree::minimum() {
  int p = 0, q = 0, total = 0, min;
  visited[0] = 1;
  for (int count = 0; count < (v - 1); count++) {
    min = 999;
    for (i = 0; i < v; i++) {
      if (visited[i] == 1) {
        for (j = 0; j < v; j++) {
          if (visited[j] != 1) {
            if (min > a[i][j]) {
              min = a[i][j];
              p = i;
              q = j;
            }
          }
        }
      }
    }
    visited[p] = 1;
    visited[q] = 1;
    total = total + min;
    cout << "Minimum cost connection is" << (p + 1) << " -> " << (q + 1) << " with  charge : "<<min<< endl;
  }
  cout << "The minimum total cost of connections of all branches is: "<<total<<endl;
}
int main() {
  int ch;
  tree t;
  do {
    cout << "==========PRIM'S ALGORITHM=================" << endl;
    cout << "\n1.INPUT\n \n2.DISPLAY\n \n3.MINIMUM\n" << endl;
    cout << "Enter your choice :" << endl;
    cin >> ch;
    switch (ch) {
      case 1:
        cout << "*******INPUT YOUR VALUES*******" << endl;
        t.input();
        break;
      case 2:
        cout << "*******DISPLAY THE CONTENTS********" << endl;
        t.display();
        break;
      case 3:
        cout << "*********MINIMUM************" << endl;
        t.minimum();
        break;
    }
  } while (ch != 4);
  return 0;
}
/* Minimum Spanning Tree (MST):
A Minimum Spanning Tree is a subgraph of a connected, weighted graph that connects 
all the vertices with the minimum possible total edge weight. 
In other words, it is a tree that spans all the vertices of the graph while minimizing the 
sum of the edge weights.

Finding the Minimum Spanning Tree:
There are two commonly used algorithms to find the Minimum Spanning Tree: 
Kruskal's algorithm and Prim's algorithm.

Kruskal's Algorithm:
1. Sort all the edges of the graph in non-decreasing order of their weights.
2. Start with an empty graph and add edges to it in increasing order of weights.
3. Add an edge to the graph if it does not create a cycle.
4. Repeat step 3 until there are V-1 edges in the graph (V is the number of vertices).
5. The resulting graph is the Minimum Spanning Tree.

Prim's Algorithm:
1. Start with an arbitrary vertex and mark it as visited.
2. Repeat the following steps until all vertices are visited:
   - Choose the minimum weight edge that connects a visited vertex to an unvisited vertex.
   - Mark the unvisited vertex as visited and add the edge to the Minimum Spanning Tree.
3. The resulting graph is the Minimum Spanning Tree.

Kruskal's vs. Prim's Algorithm:
- Kruskal's algorithm is based on sorting the edges and adding them one by one, 
considering whether they create a cycle or not. It works well for sparse graphs.
- Prim's algorithm is based on selecting the minimum weight edges from a starting vertex and 
growing the tree until all vertices are visited. It works well for dense graphs.

Both algorithms guarantee the construction of a Minimum Spanning Tree. 
The choice between Kruskal's and Prim's algorithm depends on factors such as the graph's density, 
implementation constraints, and edge weight distribution.

//-----SnehuD-----
