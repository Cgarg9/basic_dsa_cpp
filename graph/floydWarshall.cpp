// https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1


class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int n = matrix.size();
	    for (int i = 0; i < n; i++) {
	        for (int j = 0; j < n; j++) {
	            if (matrix[i][j] == -1) {
	                    matrix[i][j] = INT_MAX;
	                }
	        }
	    }
	    for (int i = 0; i < n; i++) {
	        for (int j = 0; j < n; j++) {
	            for (int k = 0; k < n; k++) {
	                if (matrix[j][k] > (matrix[j][i] + matrix[i][k]) && (matrix[j][i] != INT_MAX)
	                    && (matrix[i][k] != INT_MAX)) {
	                    matrix[j][k] = matrix[j][i] + matrix[i][k];
	                }
	            }
	        }
	    }
	   // for (int i = 0; i < n; i++) {
	   //    if (matrix[i][i] < 0) {
	   //        cout << "negative cycle"
	   //    }
	   //}
	    for (int i = 0; i < n; i++) {
	        for (int j = 0; j < n; j++) {
	            if (matrix[i][j] == INT_MAX) {
	                    matrix[i][j] = -1;
	                }
	        }
	    }
	}
};
