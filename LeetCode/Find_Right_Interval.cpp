/**
* @file Find_Right_Interval.cpp
*
* Created on 2024-10-18 at 04:24:51
* @author GabrielCampelo
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int, int>> start; // {start, index}
        
        for (int i = 0; i < n; i++) {
            int st = intervals[i][0];
            start.push_back(make_pair(st, i));
        }

        sort(start.begin(), start.end());

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int l = 0, r = n;
            int m, target = intervals[i][1];
            
            while (l < r) {
                m = l + (r - l) / 2;

                if (start[m].first < target) l = m + 1;
                else r = m;
            }

            if (r == n) ans.push_back(-1);
            else ans.push_back(start[r].second);
        }

        return ans;
    }
};