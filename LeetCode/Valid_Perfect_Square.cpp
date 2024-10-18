/**
* @file Valid_Perfect_Square.cpp
* https://leetcode.com/problems/valid-perfect-square/
*
* Created on 2024-10-18 at 02:34:56
* @author GabrielCampelo
*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        long long l = 1, r = 1ll * num, m;
        bool ans = false;

        while (l <= r) {
            m = l + (r - l) / 2;
            if (m * m < num) l = m + 1;
            else if (m * m > num) r = m - 1;
            else {
                ans = true;
                break;
            }
        }

        return ans;
    }
};