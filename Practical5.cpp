/* Construct an expression tree from the given prefix expression eg. +--a*bc/def and 
traverse it using post order traversal (non recursive) and then delete the entire tree.  */
#include <string.h>
#include <iostream>
using namespace std;
struct node {
  char data;
  node *left;
  node *right;
};
class tree {
  char prefix[20];

 public:
  node *top;
  void expression(char[]);
  void display(node *);
  void non_rec_postorder(node *);
  void del(node *);
};
class stack1 {
  node *data[30];
  int top;

 public:
  stack1() { top = -1; }
  int empty() {
    if (top == -1) return 1;
    return 0;
  }
  void push(node *p) { data[++top] = p; }
  node *pop() { return (data[top--]); }
};
void tree::expression(char prefix[]) {
  char c;
  stack1 s;
  node *t1, *t2;
  int len, i;
  len = strlen(prefix);
  for (i = len - 1; i >= 0; i--) {
    top = new node;
    top->left = NULL;
    top->right = NULL;
    if (isalpha(prefix[i])) {
      top->data = prefix[i];
      s.push(top);
    } else if (prefix[i] == '+' || prefix[i] == '*' || prefix[i] == '-' ||
               prefix[i] == '/') {
      t2 = s.pop();
      t1 = s.pop();
      top->data = prefix[i];
      top->left = t2;
      top->right = t1;
      s.push(top);
    }
  }
  top = s.pop();
}
void tree::display(node *root) {
  if (root != NULL) {
    cout << root->data;
    display(root->left);
    display(root->right);
  }
}
void tree::non_rec_postorder(node *top) {
  stack1 s1, s2;
  node *T = top;
  cout << "\n";
  s1.push(T);
  while (!s1.empty()) {
    T = s1.pop();
    s2.push(T);
    if (T->left != NULL) s1.push(T->left);
    if (T->right != NULL) s1.push(T->right);
  }
  while (!s2.empty()) {
    top = s2.pop();
    cout << top->data;
  }
}
void tree::del(node *node) {
  if (node == NULL) return;

  del(node->left);
  del(node->right);

  cout << endl << "Deleting node : " << node->data << endl;
}
int main() {
  char expr[20];
  tree t;
  cout << "Enter prefix Expression : ";
  cin >> expr;
  cout << expr;
  t.expression(expr);

  t.non_rec_postorder(t.top);
  t.del(t.top);
}

/* Threaded Binary Tree:
A threaded binary tree is a binary tree in which every node contains either a thread 
or a link to its predecessor or successor. The threads provide an efficient way to traverse 
the tree without using recursion or stacks. The threads represent the next and previous nodes 
in the in-order traversal sequence.

Types of Threaded Binary Trees:
1. Single Threaded Binary Tree: 
	In a single threaded binary tree, each node is threaded towards either its in-order 
	predecessor or successor.
2. Double Threaded Binary Tree: 
	In a double threaded binary tree, each node is threaded towards both its in-order 
	predecessor and successor.

Advantages of Threaded Binary Trees:
1. Efficient In-order Traversal: 
	Threaded binary trees provide a way to traverse the tree in in-order sequence 
	without using recursion or stacks, resulting in better efficiency and reduced memory consumption.
2. Simplified Tree Operations: 
	Threaded binary trees simplify operations like searching for the next or previous node, 
	as the threads provide direct links to these nodes.
3. Space Efficiency: 
	Threaded binary trees save space by utilizing the null pointers to store thread information 
	instead of explicit left and right child pointers.

Disadvantages of Threaded Binary Trees:
1. Complexity of Construction: 
	Constructing a threaded binary tree requires additional steps compared to a regular binary tree, 
	which adds complexity to the implementation.
2. Increased Complexity of Modifications: 
	Modifying a threaded binary tree, such as inserting or deleting nodes, 
	requires updating the thread information correctly, which can be more intricate than in a 
	regular binary tree.
3. Increased Memory Overhead: 
	Threaded binary trees may require additional memory space to store thread information 
	alongside the node data, which can increase memory overhead compared to a regular binary tree.

Overall, threaded binary trees offer advantages in terms of efficient in-order traversal 
and simplified tree operations. However, they also introduce complexities in construction and modifications, 
as well as potential memory overhead. 
The decision to use a threaded binary tree depends on the specific requirements and 
trade-offs of the application. */

//-----SnehuD-----
