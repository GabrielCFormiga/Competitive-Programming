/**
* @file Investigating Quadradômeda.cpp
* @author GabrielCampelo
* Created on 2025-11-17 at 20:48:57
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

    vector<pair<int, int>> points;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points.pb({x, y});
    }
    
    vector<int> dists(n - 1);

    for (int i = 0; i < n - 1; i++) {
        dists[i] = abs(points[i].first - points[i + 1].first) + abs(points[i].second - points[i + 1].second);
    }

    ll lb = 1, ub = dists[0] - 1;
    ll D = 0;
    int sig = 1;

    for (int i = 0; i < dists.size() - 1; i++) {
        D = dists[i] - D;
        sig *= -1;

        if (sig == -1) {
            lb = max(lb, D - dists[i + 1] + 1);
            ub = min(ub, D - 1);
        } else {
            lb = max(lb, -D + 1);
            ub = min(ub, -D + dists[i + 1] - 1);
        }

        if (lb > ub) break;
    }

    if (lb <= ub) {
        cout << ub << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}