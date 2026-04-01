#include <bits/stdc++.h>
using namespace std;

int triangularSum(vector<int>& nums) {
    int n = nums.size();
    int res = 0;
    int comb = 1; // nCr

    for(int i = 0; i < n; i++){
        res = (res + comb * nums[i]) % 10;
        comb = comb * (n - 1 - i) / (i + 1);
    }

    return res;
}

int main(){
    int n;
    cout << "Enter size: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    int result = triangularSum(nums);

    cout << "Triangular Sum: " << result << endl;

    return 0;
}