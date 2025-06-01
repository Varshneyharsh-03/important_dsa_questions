#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Maxheap
{
  vector<int> heap;

public:
  Maxheap() {}

  void insert(int ele)
  {
    heap.push_back(ele);
    heapify(heap.size() - 1);
  }

  void heapify(int index)
  {
    while (index > 0)
    {
      int parent = (index - 1) / 2;
      if (heap[index] > heap[parent])
      {
        swap(heap[index], heap[parent]);
        index = parent;
      }
      else
      {
        break;
      }
    }
  }
  void print()
  {
    if (heap.size() == 0)
      cout << "Heap is empty" << endl;

    for (int i = 0; i < heap.size(); i++)
    {
      cout << heap[i] << " ";
    }
    cout << endl;
  }
};

int main()
{
  Maxheap h;
  h.insert(10);
  h.insert(20);
  h.insert(5);
  h.insert(30);
  h.insert(15);

  h.print();
}

// time complexity of insertion is O(log n) where n is the number of elements in the heap.
// space complexity of insertion is O(1) as we are using constant space for the operation.
// The code implements a max heap data structure with an insertion method.
// The insert method adds an element to the heap and maintains the max heap property by calling the heapify method.
// The heapify method ensures that the newly added element is placed in the correct position in the heap.
// The print method displays the elements of the heap.