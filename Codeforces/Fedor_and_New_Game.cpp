/**
* @file Fedor_and_New_Game.cpp
* https://codeforces.com/problemset/problem/467/B

* Created on 2024-10-04 at 00:55:19
* @author GabrielCampelo
*/

#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

/* 
    0^0 = 0
    0^1 = 1 <- diff
    1^0 = 1 <- diff
    1^1 = 0
*/

int main() { _
    int n, m, k, fedor;
    cin >> n >> m >> k;
    
    vector<int> players(m);
    for (int i = 0; i < m; i++) cin >> players[i];
    cin >> fedor;

    int ans = 0, diff, cnt;
    for (int i = 0; i < m; i++) {
        diff = fedor ^ players[i];

        cnt = 0;
        while (diff) {
            cnt++;
            diff = diff & (diff - 1);
        }

        if (cnt <= k) ans++;
    }

    cout << ans << endl;

    return 0;
}