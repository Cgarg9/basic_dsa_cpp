#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int

class minStackPairs {
    stack<pair<int, int>> st;
public: 
    void push(int x) {
        if (st.empty()) {
            st.push({x, x});
        }
        else {
            int mini = st.top().second;
            st.push({x, min(mini, x)});
        }
    }
    void pop() {
        if (st.empty()) {
            cout << "stack empty" << endl;
        }
        else {
            st.pop();
        }
    }
    void getMin() {
        if (st.empty()) {
            cout << "stack empty" << endl;
        }
        else {
            cout << "Min element is " << st.top().second << endl;
        }
    }
    void top() {
        if (st.empty()) {
            cout << "stack empty" << endl;
        }
        else {
            cout << "top element is " << st.top().first << endl;
        }
    }
};

int main() {
    minStackPairs obj;
    obj.push(4);
    obj.push(-1);
    obj.push(2);
    obj.getMin();
    obj.push(-3);
    obj.getMin();
    return 0;
}