// https://www.geeksforgeeks.org/problems/chocolates-pickup/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=chocolates-pickup

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int

class Solution{
private:
    int help(vector<vector<int>>& matrix, int row, int col1, int col2) {
        if (col1 < 0 || col1 >= matrix[0].size() || col2 < 0 || col2 >= matrix[0].size()) return -1e8;
        if (row == matrix.size() - 1) {
            if (col1 == col2) return matrix[row][col1];
            else return matrix[row][col1] + matrix[row][col2];
        }
        
        int maxi = -1e8;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (col1 == col2) maxi = max(maxi, matrix[row][col1] + help(matrix, row+1, col1 + i, col2 + j));
                else maxi = max(maxi, matrix[row][col1] + matrix[row][col2] + help(matrix, row+1, col1 + i, col2 + j)); 
            }
        }
        return maxi;
    }
    int helpMemo(vector<vector<int>>& matrix, int row, int col1, int col2, vector<vector<vector<int>>>& dp) {
        if (col1 < 0 || col1 >= matrix[0].size() || col2 < 0 || col2 >= matrix[0].size()) return -1e8;
        if (row == matrix.size() - 1) {
            if (col1 == col2) return matrix[row][col1];
            else return matrix[row][col1] + matrix[row][col2];
        }
        if (dp[row][col1][col2] != -1) return dp[row][col1][col2];
        int maxi = -1e8;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (col1 == col2) maxi = max(maxi, matrix[row][col1] + helpMemo(matrix, row+1, col1 + i, col2 + j, dp));
                else maxi = max(maxi, matrix[row][col1] + matrix[row][col2] + helpMemo(matrix, row+1, col1 + i, col2 + j, dp)); 
            }
        }
        return dp[row][col1][col2] = maxi;
    }
    int helpTabulation(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> temp(m+1, vector<int>(m+1, -1));
        vector<vector<vector<int>>> dp(n+1, temp);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (i == j) dp[n-1][i][j] = matrix[n-1][i];
                else dp[n-1][i][j] = matrix[n-1][i] + matrix[n-1][j];
            }
        }
        for (int i = n-2; i >= 0; i--) {
            for (int j = m-1; j >= 0; j--) {
                for (int k = m-1; k >= 0; k--) {
                    int maxi = -1e8;
                    for (int x = -1; x <= 1; x++) {
                        for (int y = -1; y <= 1; y++) {
                            if (j == k) {
                                if (j + x >= 0 && j + x <=  m-1 && k + y >= 0 && k + y <= m-1)
                                    maxi = max(maxi, matrix[i][j] + dp[i+1][j+x][k+y]);
                                }
                            else {
                                if (j + x >= 0 && j + x <=  m-1 && k + y >= 0 && k + y <= m-1)
                                    maxi = max(maxi, matrix[i][j] + matrix[i][k] + dp[i+1][j+x][k+y]); 
                                }
                        }
                    }
                    dp[i][j][k] = maxi;
                }
            }
        }
        return dp[0][0][m-1];
    }
public:
    int chocolatePickup(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        // return help(matrix, 0, 0, m-1);

        // vector<vector<int>> temp(m+1, vector<int>(m+1, -1));
        // vector<vector<vector<int>>> dp(n+1, temp);
        // return helpMemo(matrix, 0, 0, m-1, dp);

        return helpTabulation(matrix);
    }
};

int main() {
    int n, m;
    cin >> n >> m;;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> matrix[i][j];
    }
    Solution obj;
    cout << obj.chocolatePickup(matrix) << endl;
    return 0;
}