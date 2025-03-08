/**
* @file Subarray_Sum_Equals_K.cpp
* https://leetcode.com/problems/subarray-sum-equals-k/
* CSES Subarray Sums II
*
* Created on 2025-03-07 at 11:15:51
* @author GabrielCampelo
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> sums;
        sums[0] = 1;

        int prefix = 0;
        int ans = 0;
        for (int x : nums) {
            prefix += x;
            ans += sums[prefix - k];
            sums[prefix]++;
        }

        return ans;
    }
};