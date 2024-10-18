/**
* @file Find_First_and_Last_Position_of_Element_in_Sorted_Array.cpp
* https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
*
* Created on 2024-10-17 at 17:41:43
* @author GabrielCampelo
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // find left
        int lo = 0, hi = nums.size() - 1;
        int left = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (nums[mid] < target) lo = mid + 1;
            else if (nums[mid] > target) hi = mid -1;
            else {
                left = mid;
                hi = mid - 1;
            }
        }

        // find right
        lo = 0, hi = nums.size() - 1;
        int right = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (nums[mid] < target) lo = mid + 1;
            else if (nums[mid] > target) hi = mid -1;
            else {
                right = mid;
                lo = mid + 1;
            }
        }

        return {left, right};
    }
};