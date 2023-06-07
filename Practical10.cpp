/*  Read the marks obtained by students of second year in an online examination of 
particular subject. Find out maximum and minimum marks obtained in that subject. 
Use heap data structure. Analyze the algorithm.  */
#include <iostream>
using namespace std;
#define max 20
class stud {
  int mks[max];

 public:
  stud() {
    for (int i = 0; i < max; i++) mks[i] = 0;
  }
  void insertheap(int tot);
  void displayheap(int tot);
  void showmax(int tot);
  void showmin();
};
void stud::insertheap(int tot) {
  for (int i = 1; i <= tot; i++) {
    cout << "enter marks";
    cin >> mks[i];
    int j = i;
    int par = j / 2;
    while (mks[j] <= mks[par] && j != 0) {
      int tmp = mks[j];
      mks[j] = mks[par];
      mks[par] = tmp;
      j = par;
      par = j / 2;
    }
  }
}
void stud::displayheap(int tot) {
  int i = 1, space = 6;
  cout << endl;
  while (i <= tot) {
    if (i == 1 || i == 2 || i == 4 || i == 8 || i == 16) {
      cout << endl << endl;
      for (int j = 0; j < space; j++) cout << " ";
      space -= 2;
    }
    cout << " " << mks[i];
    i++;
  }
}
void stud::showmax(int tot) {
  int max1 = mks[1];
  for (int i = 2; i <= tot; i++) {
    if (max1 < mks[i]) max1 = mks[i];
  }
  cout << "Max marks:" << max1;
}
void stud::showmin() { cout << "Min marks:" << mks[1]; }
int main() {
  int ch, cont, total, tmp;
  int n;
  stud s1;
  do {
    cout << endl << "Menu";
    cout << endl << "1.Read marks of the student ";
    cout << endl << "2.Display Min heap";
    cout << endl << "3.Find Max Marks";
    cout << endl << "4.Find Min Marks";
    cout << endl << "Enter Choice";
    cin >> ch;
    switch (ch) {
      case 1:
        cout << "how many students";
        cin >> total;
        s1.insertheap(total);
        break;
      case 2:
        s1.displayheap(total);
        break;
      case 3:
        s1.showmax(total);
        break;
      case 4:
        s1.showmin();
        break;
    }
    cout << endl << "do u want to continue?(1 for continue)";
    cin >> cont;
  } while (cont == 1);
  return 0;
}
/* Binary Heap:
A binary heap is a complete binary tree that satisfies the heap property. In a min heap, for any given node, the value of the node is smaller than or equal to the values of its children. In a max heap, the value of the node is greater than or equal to the values of its children. Binary heaps are commonly used to implement priority queues.

Operations on Heap:
1. Insertion: To insert a new element in the heap, it is placed at the next available position in the bottom level and then "bubbled up" by swapping it with its parent until the heap property is satisfied.

2. Deletion: The deletion operation removes the root element from the heap. The last element in the bottom level is moved to the root position, and then it is "bubbled down" by swapping it with the smaller (in a min heap) or larger (in a max heap) child until the heap property is satisfied.

3. Peek: The peek operation returns the value of the root element without removing it from the heap.

Heap Sort:
Heap sort is a comparison-based sorting algorithm that uses a binary heap data structure. It sorts an array by building a max heap or min heap from the elements and then repeatedly extracting the root element, which is the maximum or minimum, depending on the type of heap. The extracted element is placed at the end of the sorted portion of the array.

Algorithm for Heap Sort:
1. Build a max heap or min heap from the given array.
2. Repeat the following steps until the heap is empty:
   - Swap the root element with the last element in the heap.
   - Reduce the heap size by one.
   - Restore the heap property by performing heapify on the root element.
3. The array is now sorted in ascending or descending order, depending on the type of heap.

Complexity Analysis:
- Building a heap takes O(n) time, where n is the number of elements.
- Extracting the root and restoring the heap property takes O(log n) time, and since it is performed n times, the overall time complexity is O(n log n).
- The space complexity is O(1) since the sorting is performed in-place.

Heap sort has a good average and worst-case time complexity, making it an efficient sorting algorithm. 
However, it is not a stable sort and may not be suitable for sorting elements with equal keys. */

//-----SnehuD-----
