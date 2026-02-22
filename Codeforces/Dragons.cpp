/**
* @file Dragons.cpp
* @author GabrielCampelo
* Created on 2026-02-21 at 23:32:51
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
    int s, n;
    cin >> s >> n;

    vector<pair<int, int>> vec(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        vec[i] = {x, y};
    }

    sort(all(vec));

    int i = 0;
    for (i; i < n; i++) {
        if (s <= vec[i].first) break;
        s += vec[i].second;
    }

    cout << (i == n ? "YES" : "NO") << endl;

    return 0;
}