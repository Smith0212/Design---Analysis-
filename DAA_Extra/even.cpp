#include <iostream>
#include <vector>

using namespace std;

int maximize_impact(int n, int budget, vector<int>& c, vector<int>& q) {
    // Initialize the 2D array with zeros
    vector<vector<int>> dp(n+1, vector<int>(budget+1, 0));

    // Fill in the values using the dynamic programming approach
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= budget; j++) {
            if (c[i-1] > j) {
                // Cannot afford to advertise on this platform
                dp[i][j] = dp[i-1][j];
            }
            else {
                // Choose the platform that gives maximum impact
                dp[i][j] = max(dp[i-1][j], q[i-1] + dp[i-1][j-c[i-1]]);
            }
        }
    }

    // Return the maximum impact achievable with the given budget
    return dp[n][budget];
}

int main() {
    int n = 4;
    int budget = 10;
    vector<int> c = {1, 2, 3, 7};
    vector<int> q = {2, 4, 5, 3};
    int max_impact = maximize_impact(n, budget, c, q);
    cout << max_impact << endl;
    return 0;
}
