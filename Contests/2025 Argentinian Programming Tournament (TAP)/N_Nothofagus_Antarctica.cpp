/**
* @file N_Nothofagus_antarctica.cpp
* @author GabrielCampelo
* Created on 2026-02-08 at 08:44:27
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

    int mn = INF, mx = 0;
    map<int, pair<int, int>> mp; // {x, {lo, up}}

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        mn = min(mn, y);
        mx = max(mx, y);
        if (mp.find(x) != mp.end()) {
            mp[x].first = min(mp[x].first, y - 1);
            mp[x].second = max(mp[x].second, y + 1);            
        } else {
            mp[x] = {y - 1, y + 1};
        }
    }

    vector<int> seq;

    for (auto p : mp) {
        seq.push_back(p.first);
    }

    int ans = seq[seq.size() - 1] - seq[0] + 2 + (mx - mn) + 2;
    cout << 2 * ans << endl;

    return 0;
}