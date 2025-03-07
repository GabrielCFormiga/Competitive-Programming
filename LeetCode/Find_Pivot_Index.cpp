/**
* @file Find_Pivot_Index.cpp
* https://leetcode.com/problems/find-pivot-index/
*
* Created on 2025-03-07 at 08:54:00
* @author GabrielCampelo
*/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> prefix(nums.size() + 1);    
        
        for (int i = 0; i < nums.size(); i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        for (int i = 0; i < nums.size(); i++) {
            if (prefix[i] == prefix[nums.size()] - prefix[i + 1]) {
                return i;
            }
        }

        return -1;
    }
};