/**
* @file B_Period_Search.cpp
* @author GabrielCampelo
* Created on 2026-03-01 at 08:34:11
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
    int n;
    cin >> n;

    vector<int> divs;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int tmp = n / i;
            divs.pb(i);
            if (i != tmp) divs.pb(tmp);
        }
    }

    sort(all(divs));

    vector<pair<int, int>> ans;
    vector<bool> used(divs.size(), false);

    for (int i = divs.size() - 1; i >= 0; i--) {
        if (used[i]) continue;
        ans.pb({1, divs[i]});
        for (int j = i; j >= 0; j--) {
            if (divs[i] % divs[j] == 0) used[j] = true;
        }
    }

    if (ans.size() == 0) {
        cout << 1 << endl;
        cout << 1 << ' ' << 1 << endl;
        return 0;
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << ' ' << ans[i].second << endl;
    }

    return 0;
}