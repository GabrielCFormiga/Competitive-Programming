/**
* @file Find_Peak_Element.cpp
* https://leetcode.com/problems/find-peak-element/description/
*
* Created on 2024-10-18 at 02:43:21
* @author GabrielCampelo
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        if (nums[0] > nums[1]) return 0;
        if (nums[nums.size() - 1] > nums[nums.size() - 2]) return nums.size() - 1;

        int lo = 1, hi = nums.size() - 2;
        int mid;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (nums[mid] > nums[mid - 1]) {
                // mid - 1 < mid
                if (nums[mid] > nums[mid + 1]) {
                    // mid - 1 < mid > mid + 1
                    return mid;
                } else {
                    // mid - 1 < mid < mid + 1
                    lo = mid + 1;
                }
            } else {
                // mid - 1 > mid
                hi = mid - 1;
            }
        }

        return -1;
    }
};