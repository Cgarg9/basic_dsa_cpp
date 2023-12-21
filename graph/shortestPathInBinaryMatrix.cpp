// https://practice.geeksforgeeks.org/problems/shortest-source-to-destination-path3544/1

class Solution {
    private:
        bool check(int row, int col, int N, int M) {
            if (row >= 0 && row < N && col >= 0 && col < M) {
                return true;
            }
            return false;
        }
    public:
        int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {

             queue<pair<int, int>> q;
            vector<vector<int>> distance(N, vector<int>(M, INT_MAX));
            if (X == 0 && Y == 0) {
                return 0;
            }
            if (A[0][0] == 0) return -1;
            q.push({0, 0});
            distance[0][0] = 0;
            int dx[4] = {-1, 0, 1, 0};
            int dy[4] = {0, -1, 0, 1};
            while (!q.empty()) {
                int x = q.front().first;
                int y = q.front().second;
                if (x == X && y == Y) {
                    return distance[x][y];
                }
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int row = x + dx[i];
                    int col = y + dy[i];
                    if (check(row, col, N, M) && A[row][col] == 1 && distance[x][y] + 1 < distance[row][col]) {
                        distance[row][col] = distance[x][y] + 1;
                        q.push({row, col});
                    }
                    // if (row == X && col == Y) {
                    //     return distance[x][y] + 1;
                    // }
                }
            }
            return -1;
        }
};
