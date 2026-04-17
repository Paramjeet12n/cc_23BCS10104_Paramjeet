#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            int maxVal = 0;
            int best = 0;

            for (int j = i; j < min(i + k, n); j++) {
                maxVal = max(maxVal, arr[j]);
                int len = j - i + 1;

                int sum = maxVal * len + dp[j + 1];
                best = max(best, sum);
            }

            dp[i] = best;
        }

        return dp[0];
    }
};

int main() {
    Solution obj;

    vector<int> arr = {1, 15, 7, 9, 2, 5, 10};
    int k = 3;

    cout << "Maximum Sum: " << obj.maxSumAfterPartitioning(arr, k);

    return 0;
}