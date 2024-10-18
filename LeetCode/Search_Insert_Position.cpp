/**
* @file Search_Insert_Position.cpp
* https://leetcode.com/problems/search-insert-position/
*
* Created on 2024-10-18 at 02:16:55
* @author GabrielCampelo
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // achar primeiro >=
        // se nao tiver ninguem >= retorna n
        int lo = 0, hi = nums.size();
        int mid;
        while (lo < hi) {
            mid = lo + (hi - lo) / 2;
            if (nums[mid] < target) lo = mid + 1;
            else hi = mid;
        }

        return hi;
    }
};