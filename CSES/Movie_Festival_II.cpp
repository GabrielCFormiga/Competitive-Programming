/**
* @file Movie_Festival_II.cpp
* @author GabrielCampelo
* Created on 2026-03-01 at 19:00:33
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
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> vec(n);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        vec[i] = {l, r};
    }

    sort(all(vec), [](pair<int, int> &a, pair<int, int> &b){
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return a.second < b.second;
    });

    int ans = 0;
    multiset<int> ms;
    for (int i = 0; i < k; i++) {
        ms.insert(0);
    }

    for (int i = 0; i < n; i++) {
        int l = vec[i].first;
        int r = vec[i].second;
        auto it = ms.upper_bound(l);
        if (it == ms.begin()) continue;
        it--;
        ans++;
        ms.erase(it);
        ms.insert(r);
    }

    cout << ans << endl;

    return 0;
}