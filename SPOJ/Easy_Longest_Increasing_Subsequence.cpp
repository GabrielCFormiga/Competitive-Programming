/**
* @file Easy_Longest_Increasing_Subsequence.cpp
* https://www.spoj.com/problems/ELIS/en/
*
* Created on 2024-11-15 at 14:11:07
* @author GabrielCampelo
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
    int n;
    cin >> n;

    vector<int> vec(n);
    for (int i = 0; i < n; i++) cin >> vec[i];

    int ans = 0;

    for (int mask = 0; mask < (1 << n); mask++) {
        int prev = -1;
        bool possible = true;

        for (int j = 0; j < n; j++) {
            if (mask & (1 << j)) {
                if (vec[j] <= prev) {
                    possible = false;
                    break;
                } else {
                    prev = vec[j];
                }
            }
        }

        if (possible) ans = max(ans, __builtin_popcount(mask));
    }

    cout << ans << endl;

    return 0;
}