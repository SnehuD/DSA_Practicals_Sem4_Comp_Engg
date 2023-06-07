/*  Givensequencek=k1<k2<… withasearchprobabilitypiforeach key ki . Build the 
Binary search tree that has the least search cost given the access probability for each 
key? */
#include <iostream>
using namespace std;
void con_obst(void);
void print(int, int);
float a[20], b[20], wt[20][20], c[20][20];
int r[20][20], n;
int main() {
  int i;
  cout << "\n**** PROGRAM FOR OBST ******\n";
  cout << "\nEnter the no. of nodes : ";
  cin >> n;
  cout << "\nEnter the probability for successful search :: ";
  cout<<"\n \n"; 
   for (i = 1; i <= n; i++) {
    cout << "p[" << i << "]";
    cin >> a[i];
  }
  cout << "\nEnter the probability for unsuccessful search :: ";
  cout << "\n \n";
   for (i = 0; i <= n; i++) {
    cout << "q[" << i << "]";
    cin >> b[i];
  }
  con_obst();
  print(0, n);
  cout << endl;
}
void con_obst(void) {
  int i, j, k, l, min;
  for (i = 0; i < n; i++) {
    c[i][i] = 0.0;
    r[i][i] = 0;
    wt[i][i] = b[i];
    wt[i][i + 1] = b[i] + b[i + 1] + a[i + 1];
    c[i][i + 1] = b[i] + b[i + 1] + a[i + 1];
    r[i][i + 1] = i + 1;
  }
  c[n][n] = 0.0;
  r[n][n] = 0;
  wt[n][n] = b[n];
  for (i = 2; i <= n; i++) {
    for (j = 0; j <= n - i; j++) {
      wt[j][j + i] = b[j + i] + a[j + i] + wt[j][j + i - 1];
      c[j][j + i] = 9999;
      for (l = j + 1; l <= j + i; l++) {
        if (c[j][j + i] > (c[j][l - 1] + c[l][j + i])) {
          c[j][j + i] = c[j][l - 1] + c[l][j + i];
          r[j][j + i] = l;
        }
      }
      c[j][j + i] += wt[j][j + i];
    }
    cout << endl;
  }
  cout << "\n\nOptimal BST is :: ";
  cout << "\nw[0][" << n << "] :: " << wt[0][n];
  cout << "\nc[0][" << n << "] :: " << c[0][n];
  cout << "\nr[0][" << n << "] :: " << r[0][n];
}
void print(int l1, int r1) {
  if (l1 >= r1) return;
  if (r[l1][r[l1][r1] - 1] != 0)
    cout << "\n Left child of " << r[l1][r1] << " :: " << r[l1][r[l1][r1] - 1];
  if (r[r[l1][r1]][r1] != 0)
    cout << "\n Right child of " << r[l1][r1] << " :: " << r[r[l1][r1]][r1];
  print(l1, r[l1][r1] - 1);
  print(r[l1][r1], r1);
  return;
}
/* Optimal Binary Search Tree (OBST):
An Optimal Binary Search Tree, also known as a Weighted Binary Search Tree, is a binary search tree that minimizes the average search time for a given set of keys. In an OBST, frequently accessed keys are placed near the root, reducing the average search time.

Algorithm for constructing an OBST:
1. Sort the keys in increasing order of their probabilities or frequencies.
2. Initialize an n x n matrix, where n is the number of keys.
3. Compute the cumulative probabilities of the keys and store them in a separate array.
4. Iterate over the matrix diagonally and fill in the values as follows:
   - For each sub-tree size, calculate the optimal cost of constructing a tree rooted at each possible key.
   - The optimal cost is determined by considering all possible roots and their corresponding left and right sub-trees.
   - Store the minimum cost and the corresponding root for each sub-tree size and position in the matrix.
5. Repeat step 4 until the entire matrix is filled.
6. The top-right cell of the matrix will contain the optimal cost of constructing the OBST.
7. Backtrack through the matrix to construct the OBST recursively based on the stored root values.

Complexity Analysis:
The time complexity of constructing an OBST using the above algorithm is O(n^3), where n is the number of keys. This is because we need to fill an n x n matrix, and for each cell, we consider all possible sub-tree sizes.

The space complexity is O(n^2) since we need to store the matrix of size n x n.

The algorithm's efficiency can be improved by using memoization techniques or dynamic programming, which allow us to avoid redundant calculations and reduce the time complexity to O(n^2).

Overall, constructing an OBST involves dynamic programming principles and can efficiently optimize search time for a given set of keys with their associated probabilities or frequencies. */

//-----SnehuD-----
