/**
* @file First_Bad_Version.cpp
* https://leetcode.com/problems/first-bad-version/
*
* Created on 2024-10-18 at 02:26:37
* @author GabrielCampelo
*/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int lo = 1, hi = n;
        int mid;
        while (lo < hi) {
            mid = lo + (hi - lo) / 2;
            if (!isBadVersion(mid)) lo = mid + 1;
            else hi = mid;
        } 

        return hi;
    }
};