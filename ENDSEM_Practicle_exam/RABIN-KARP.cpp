class Solution {
  public:
    const int base = 256;
    const int mod = 1e9 + 7;

    long long createHash(string &s, int len) {
        long long h = 0;
        for (int i = 0; i < len; i++)
            h = (h * base + s[i]) % mod;
        return h;
    }

    long long recalcHash(long long oldHash, char oldChar, char newChar, long long power) {
        oldHash = (oldHash - oldChar * power % mod + mod) % mod;
        oldHash = (oldHash * base + newChar) % mod;
        return oldHash;
    }

    vector<int> rabinKarp(string &text, string &pattern) {
        int n = text.size(), m = pattern.size();
        vector<int> res;
        if (m > n) return res;

        long long power = 1;
        for (int i = 0; i < m - 1; i++)
            power = (power * base) % mod;

        long long hashP = createHash(pattern, m);
        long long hashT = createHash(text, m);

        for (int i = 0; i <= n - m; i++) {
            if (hashP == hashT) {
                bool match = true;
                for (int j = 0; j < m; j++) {
                    if (text[i + j] != pattern[j]) {
                        match = false;
                        break;
                    }
                }
                if (match) res.push_back(i);
            }

            if (i < n - m)
                hashT = recalcHash(hashT, text[i], text[i + m], power);
        }

        return res;
    }
};