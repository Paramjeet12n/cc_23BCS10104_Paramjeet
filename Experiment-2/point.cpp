//Leetcode Question 149

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;

        int ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<string, int> mp;
            int same = 0;
            int maxPoints = 0;

            for (int j = i + 1; j < n; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if (dx == 0 && dy == 0) {
                    same++;
                    continue;
                }

                int g = __gcd(dx, dy);
                dx /= g;
                dy /= g;

                string slope = to_string(dy) + "/" + to_string(dx);
                mp[slope]++;
                maxPoints = max(maxPoints, mp[slope]);
            }

            ans = max(ans, maxPoints + same + 1);
        }

        return ans;
    }
};