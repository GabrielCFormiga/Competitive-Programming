/**
* @file Preparing_Olympiad .cpp
* https://codeforces.com/problemset/problem/550/B
*
* Created on 2024-11-14 at 23:34:28
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
    int n, l, r, x;
    cin >> n >> l >> r >> x;

    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];

    int cnt = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
        if ((mask & (mask - 1)) == 0) continue; // apenas 1 problema

        int mn = INF, mx = 0;
        int sum = 0;

        for (int j = 0; j < n; j++) {
            if (mask & (1 << j)) {
                sum += c[j];
                mn = min(mn, c[j]);
                mx = max(mx, c[j]);
            }
        }

        if (sum >= l && sum <= r && mx - mn >= x) cnt++;
    } 
    
    cout << cnt << endl;

    return 0;
}