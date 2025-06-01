#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Maxheap
{
  vector<int> heap;

public:
  void insert(int ele)
  {
    heap.push_back(ele);
    heapifyUp(heap.size() - 1);
  }

  void heapifyUp(int index)
  {
    while (index > 0)
    {
      int parent = (index - 1) / 2;
      if (heap[index] > heap[parent])
      {
        swap(heap[parent], heap[index]);
        index = parent;
      }
      else
        break;
    }
  }

  void heapifyDown(int ind)
  {
    int size = heap.size();
    while (ind < size)
    {
      int left = 2 * ind + 1;
      int right = 2 * ind + 2;
      int largest = ind;

      if (left < size && heap[left] > heap[largest])
      {
        largest = left;
      }
      if (right < size && heap[right] > heap[largest])
      {
        largest = right;
      }
      if (largest != ind)
      {
        swap(heap[ind], heap[largest]);
        ind = largest;
      }
      else
        return;
    }
  }

  void deletion()
  {
    if (heap.empty())
    {
      cout << "Heap is empty" << endl;
      return;
    }
    swap(heap[0], heap[heap.size() - 1]);
    heap.pop_back();
    heapifyDown(0);
  }

  void print()
  {
    if (heap.empty())
    {
      cout << "Heap is empty" << endl;
      return;
    }

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

  cout << "Heap before deletion: ";
  h.print();

  h.deletion();

  cout << "Heap after deletion: ";
  h.print();

  return 0;
}
// Time complexity of deletion is O(log n) where n is the number of elements in the heap.