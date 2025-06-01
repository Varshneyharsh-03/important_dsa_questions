#include <iostream>
#include <vector>
#include <algorithm>
#include <initializer_list>

using namespace std;

void print(vector<int> &arr)
{
  for (int i = 0; i < arr.size(); i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void heapify(int n, int ind, vector<int> &arr)
{
  while (ind < n)
  {
    int left = 2 * ind + 1;
    int right = 2 * ind + 2;
    int largest = ind;
    if (left < n and arr[left] > arr[largest])
    {
      largest = left;
    }
    if (right < n and arr[right] > arr[largest])
    {
      largest = right;
    }

    if (largest != ind)
    {
      swap(arr[ind], arr[largest]);
      ind = largest;
    }
    else
      return;
  }
}

int main()
{
  vector<int> arr;
  arr.push_back(12);
  arr.push_back(11);
  arr.push_back(13);
  arr.push_back(5);
  arr.push_back(6);

  int n = arr.size();

  // Build heap (rearrange array)
  for (int i = n / 2; i >= 0; i--)
  {
    heapify(n, i, arr);
  }

  for (int i = n - 1; i >= 0; i--)
  {
    swap(arr[0], arr[i]);
    heapify(i, 0, arr);
  }

  cout << "Sorted array is \n";
  print(arr);

  return 0;
}