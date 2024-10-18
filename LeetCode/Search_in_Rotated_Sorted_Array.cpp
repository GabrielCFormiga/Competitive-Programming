/**
* @file Search_in_Rotated_Sorted_Array.cpp
* https://leetcode.com/problems/search-in-rotated-sorted-array/description/
*
* Created on 2024-10-18 at 02:57:41
* @author GabrielCampelo
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        int mid;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (nums[mid] == target) return mid;

            if (nums[mid] < target && nums[mid] >= nums[lo]) lo = mid + 1;
            else if (nums[mid] < target && target >= nums[lo]) hi = mid - 1;  
            else if (nums[mid] < target) lo = mid + 1; 

            else if (nums[mid] > target && nums[mid] > nums[lo] && target >= nums[lo]) hi = mid - 1;
            else if (nums[mid] > target && nums[mid] <= nums[hi]) hi = mid - 1;
            else if (nums[mid] > target) lo = mid + 1; 
        }

        return -1;
    }
};