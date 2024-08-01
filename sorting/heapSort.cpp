// to learn more about heap sort, goto https://www.geeksforgeeks.org/heap-sort/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

class Solution {
private:
    // heapify method is called to convert the array to Max-Heap
    void heapify(ll i, ll n, vector<ll> &maxHeap) {

        ll leftNode = (2 * i) + 1;
        ll rightNode = (2 * i) + 2;

        ll largestI = i;

        if (leftNode < n && maxHeap[leftNode] > maxHeap[largestI])    // if the left child node is greater than parent node, choose them
            largestI = leftNode;

        if (rightNode < n && maxHeap[rightNode] > maxHeap[largestI])    // if the right child node is greater than parent node, choose them
            largestI = rightNode;

        if(largestI != i) {    // if we didn't swap any nodes, then we can stop the heapify process

            swap(maxHeap[i], maxHeap[largestI]);
            heapify(largestI, n, maxHeap);
        }
    }

public:
    // heapSort method is the main sorting method
    void heapSort(ll n, vector<ll> &maxHeap) {

        for(ll i = (n / 2) - 1; i >= 0; i--)    // build Max-Heap
            heapify(i, n, maxHeap);

        for(ll i = 0; i < n; i++) {

            swap(maxHeap[0], maxHeap[n - i - 1]);    // move the largest element to the end
            heapify(0, n - i - 1, maxHeap);    // heapify the array to move the largest element to the root
        }
    }

};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    vector<ll> elements(n);

    for (ll i = 0; i < n; i++)
        cin >> elements[i];

    cout << "\nBefore heap sort: " << endl;
    for (ll i = 0; i < n; i++) cout << elements[i] << " ";
    cout << endl;

    Solution sol;
    sol.heapSort(n, elements);

    cout << "\nAfter heap sort: " << endl;
    for (ll i = 0; i < n; i++) cout << elements[i] << " ";
    cout << endl;

    return 0;
}