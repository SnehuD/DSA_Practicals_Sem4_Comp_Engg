/*  A book consists of chapters, chapters consist of sections and sections consist of 
subsections. Construct a tree and print the nodes. Find the time and space 
requirements of your method.  */
#include <string.h>
#include <iostream>
using namespace std;
struct node  // Node Declaration
{
  string label;
  // char label[10];
  int ch_count;
  struct node *child[10];
} * root;
class GT  // Class Declaration
{
 public:
  void create_tree();
  void display(node *r1);
  GT() { root = NULL; }
};
void GT::create_tree() {
  int tbooks, tchapters, i, j, k;
  root = new node;
  cout << "Enter name of book : ";
  cin.get();
  getline(cin, root->label);
  cout << "Enter number of chapters in book : ";
  cin >> tchapters;
  root->ch_count = tchapters;
  for (i = 0; i < tchapters; i++) {
    root->child[i] = new node;
    cout << "Enter the name of Chapter " << i + 1 << " : ";
    cin.get();
    getline(cin, root->child[i]->label);
    cout << "Enter number of sections in Chapter : " << root->child[i]->label
         << " : ";
    cin >> root->child[i]->ch_count;
    for (j = 0; j < root->child[i]->ch_count; j++) {
      root->child[i]->child[j] = new node;
      cout << "Enter Name of Section " << j + 1 << " : ";
      cin.get();
      getline(cin, root->child[i]->child[j]->label);
    }
  }
}
void GT::display(node *r1) {
  int i, j, k, tchapters;
  if (r1 != NULL) {
    cout << "\n-----Book Hierarchy---";
    cout << "\n Book title : " << r1->label;
    tchapters = r1->ch_count;
    for (i = 0; i < tchapters; i++) {
      cout << "\nChapter " << i + 1;
      cout << " : " << r1->child[i]->label;
      cout << "\nSections : ";
      for (j = 0; j < r1->child[i]->ch_count; j++) {
        cout << "\n" << r1->child[i]->child[j]->label;
      }
    }
  }
  cout << endl;
}
int main() {
  int choice;
  GT gt;
  while (1) {
    cout << "-----------------" << endl;
    cout << "Book Tree Creation" << endl;
    cout << "-----------------" << endl;
    cout << "1.Create" << endl;
    cout << "2.Display" << endl;
    cout << "3.Quit" << endl;
    cout << "Enter your choice : ";
    cin >> choice;
    switch (choice) {
      case 1:
        gt.create_tree();
      case 2:
        gt.display(root);
        break;
      case 3:
        cout << "Thanks for using this program!!!";
        exit(1);
      default:
        cout << "Wrong choice!!!" << endl;
    }
  }
  return 0;
}
/* Theory on Trees:
- A tree is a hierarchical data structure that consists of nodes connected by edges.
- Each node can have zero or more child nodes.
- The topmost node is called the root, and nodes without children are called leaves.

Types of Trees:
1. Binary Tree: A tree where each node can have at most two children.
2. Binary Search Tree (BST): A binary tree with a specific ordering property:
   - The left child of a node contains values less than the node.
   - The right child of a node contains values greater than the node.

Types of Binary Trees:
1. Full Binary Tree: A binary tree where every node has either 0 or 2 children.
2. Complete Binary Tree: A binary tree where all levels except the last are completely filled, and nodes are left-aligned.
3. Perfect Binary Tree: A binary tree where all internal nodes have two children, and all leaf nodes are at the same level.
4. Balanced Binary Tree: A binary tree where the height of the left and right subtrees of any node differs by at most one.

Tree Traversal:
- Tree traversal is the process of visiting all nodes in a tree.
- Inorder Traversal: Visits the left subtree, current node, and then the right subtree.
  - Used to retrieve elements from a binary search tree in sorted order.
- Preorder Traversal: Visits the current node, left subtree, and then the right subtree.
- Postorder Traversal: Visits the left subtree, right subtree, and then the current node.
  - Used to delete a tree or evaluate postfix expressions.

Inorder Traversal:
- Follows the left subtree, current node, and right subtree order.
- Useful for retrieving elements from a binary search tree in sorted order.
- Implemented using recursion or iteration (e.g., using a stack).
- Time complexity: O(n), where n is the number of nodes in the tree. */

//-----SnehuD-----
