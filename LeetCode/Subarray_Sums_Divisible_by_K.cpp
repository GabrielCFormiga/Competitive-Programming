/**
* @file Subarray_Sums_Divisible_by_K.cpp
* https://leetcode.com/problems/subarray-sums-divisible-by-k/description/
* CSES Subarray Divisibility
*
* Created on 2025-03-07 at 23:16:37
* @author GabrielCampelo
*/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> cnt(k);
        cnt[0] = 1;

        int curr = 0;
        int ans = 0;

        for (int x : nums) {
            // x = (x + 10000*k) % k;
            curr = (curr + x % k + k) % k;
            ans += cnt[curr];
            cnt[curr]++;
        }

        return ans;
    }
};