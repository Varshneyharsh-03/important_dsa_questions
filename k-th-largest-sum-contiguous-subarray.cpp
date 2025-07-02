#include <iostream>       
#include <vector>         
#include <queue>
using namespace std;

// Function to calculate Kth largest element
// in contiguous subarray sum
int kthLargest(vector<int> &arr, int k) {
    
    int n = arr.size();

    // array to store prefix sums
    vector<int> sum(n + 1);
    sum[0] = 0;
    sum[1] = arr[0];
    for (int i = 2; i <= n; i++)
        sum[i] = sum[i - 1] + arr[i - 1];

    // min heap
    priority_queue<int, vector<int>, greater<int>> pq;

    // loop to calculate the contiguous subarray
    // sums position-wise
    for (int i = 1; i <= n; i++) {

        // loop to traverse all positions that
        // form contiguous subarray
        for (int j = i; j <= n; j++) {

            // calculates the contiguous subarray
            // sums from j to i index
            int x = sum[j] - sum[i - 1];

            // if queue has less than k elements,
            // then simply push it
            if (pq.size() < k)
                pq.push(x);

            else {

                // it the min heap has equal to
                // k elements then just check
                // if the largest kth element is
                // smaller than x then insert
                // else its of no use
                if (pq.top() < x) {
                    pq.pop();
                    pq.push(x);
                }
            }
        }
    }

    // the top element will be then kth
    // largest element
    return pq.top();
}

int main() {
    vector<int> arr = {20, -5, -1};
    int k = 3;
    cout << kthLargest(arr, k);
    return 0;
}
