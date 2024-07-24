#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
#define ll long long int;

    vector<int> nearestSmallerTower(vector<int> arr)
    {
        int n = arr.size();
        vector<int> forward(n, 0);
        vector<int> backward(n, 0);
        stack<int> st;
        st.push(-1);
        for (int i = 0; i < n; i++) {
            while(st.top() != -1 && arr[st.top()] >= arr[i]) st.pop();
            forward[i] = st.top();
            st.push(i);
        }
        // for (int i = 0; i < n; i++) {
        //     cout << forward[i] << " ";
        // }
        // cout << endl;
        stack<int> st2;
        st2.push(-1);
        for (int i = n-1; i >= 0; i--) {
            while(st2.top() != -1 && arr[st2.top()] >= arr[i]) st2.pop();
            backward[i] = st2.top();
            st2.push(i);
        }
        vector<int> ans(n);
        for (int i = 0; i < arr.size(); i++) {
            int forwardDist = forward[i];
            int backDist = backward[i];
            if (forwardDist == -1) {
                ans[i] = backDist;
                continue;
            }
            else if (backDist == -1) {
                ans[i] = forwardDist;
                continue;
            }
            else if (abs(forwardDist - i) > abs(backDist - i)) {
                ans[i] = backDist;
                continue;
            }
            else if (abs(forwardDist - i) < abs(backDist - i)) {
                ans[i] = forwardDist;
                continue;
            }
            else {
                if (arr[forwardDist] > arr[backDist]) ans[i] = backDist;
                else ans[i] = forwardDist;
            }
        }
        return ans;
    }

int main() {
    vector<int> arr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    vector<int> ans = nearestSmallerTower(arr);
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}