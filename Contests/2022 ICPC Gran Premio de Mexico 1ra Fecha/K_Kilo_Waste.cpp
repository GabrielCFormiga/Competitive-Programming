/**
* @file K_Kilo_Waste.cpp
* @author GabrielCampelo
* Created on 2026-03-15 at 08:48:27
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;

using ll = long long;
using llu = unsigned long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
    int k, p;
    cin >> k >> p;

    vector<int> vec(p);
    for (int i = 0; i < p; i++) {
        cin >> vec[i];
    }

    vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
    p = vec.size();

    // // DEBUGG
    // for (int i = 0; i < p; i++) {
    //     cout << vec[i] << ' ';
    // }
    // cout << endl;

    vector<bool> dp(100100);
    dp[0] = true;
    for (int x : vec) {
        for (int i = x; i <= 100000; i++) {
            if (dp[i - x] == true) dp[i] = true;
        }
    }

    // // DEBUGG
    // for (int i = 0; i < 20; i++) {
    //     cout << "dp[" << i << "] = " << dp[i] << endl;
    // }

    vector<int> left(100100);
    for (int i = 1; i <= 100000; i++) {
        if (dp[i]) left[i] = i;
        else left[i] = left[i - 1]; 
    }

    vector<int> right(100100);
    for (int i = 100000; i >= 1; i--) {
        if (dp[i]) right[i] = i;
        else right[i] = right[i + 1]; 
    }

    while (k--) {
        int x;
        cin >> x;
        // cout << min(right[x] - x, x - left[x]) << endl;
        cout << right[x] - x << endl;
    }
    
    return 0;
}