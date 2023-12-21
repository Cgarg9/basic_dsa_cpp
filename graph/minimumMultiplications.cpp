// https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // mod 1e5 so 1e5 nodes possible
        vector<int> steps(100000, INT_MAX);
        steps[start] = 0;
        queue<pair<int, int>> q;
        q.push({0, start});
        while (!q.empty()) {
            int step = q.front().first;
            int node = q.front().second;
            if (node == end) {
                return step;
            }
            q.pop();
            for (int i = 0; i < arr.size(); i++) {
                int temp = node*arr[i];
                temp %= 100000;
                if (steps[temp] > step + 1) {
                    steps[temp] = step + 1;
                    q.push({step+1, temp});
                }
            }
        }
        return -1;
    }
};
