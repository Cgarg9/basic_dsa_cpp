// https://www.geeksforgeeks.org/problems/steps-by-knight5927/1?page=1&category=Graph&sortBy=submissions
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

class Solution
{
    int dx[8] = {1, -1, -2, -2, -1, 1, 2, 2};
    int dy[8] = {-2, -2, -1, 1, 2, 2, 1, -1};

public:
    // Function to find out minimum steps Knight needs to reach target position.
    int minStepToReachTarget(vector<int> &start, vector<int> &end, int N)
    {
        if (start == end)
            return 0;
        // x, y, moves
        queue<pair<pair<int, int>, int>> q;
        vector<vector<bool>> visited(N, vector<bool>(N, false));

        q.push({{start[0] - 1, start[1] - 1}, 0});
        visited[start[0] - 1][start[1] - 1] = true;
        while (!q.empty())
        {
            // cout << "hello";
            int x = q.front().first.first;
            int y = q.front().first.second;
            int move = q.front().second;
            q.pop();

            if (x == end[0] - 1 && y == end[1] - 1)
                return move;

            for (int i = 0; i < 8; i++)
            {
                int row = x + dx[i];
                int col = y + dy[i];
                if (row >= 0 && row < N && col >= 0 && col < N && visited[row][col] == false)
                {
                    q.push({{row, col}, move + 1});
                    visited[row][col] = true;
                }
            }
        }
        return -1;
    }
};

int main()
{
    int N;
    cin >> N;
    vector<int> start = {1, 1};
    vector<int> end = {N, N};
    Solution obj;
    cout << obj.minStepToReachTarget(start, end, N);
}