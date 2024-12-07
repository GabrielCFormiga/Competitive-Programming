/**
* @file Two_City_Scheduling.cpp
* https://leetcode.com/problems/two-city-scheduling/description/
*
* Created on 2024-12-06 at 10:10:56
* @author GabrielCampelo
*/

#

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int ret = 0;
        vector<int> to_a(costs.size());
        
        for (int i = 0; i < costs.size(), i++) {
            ret += costs[i][1];
            to_a[i] = costs[i][1] - costs[i][0];
        }

        sort(to_a.rbegin(), to_a.rend());

        for (int i = 0; i < costs.size() / 2; i++) ret -= to_a[i];
    
        return ret;
    }
};