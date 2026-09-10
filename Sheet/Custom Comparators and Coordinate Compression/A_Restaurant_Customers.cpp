/**
* @file A_Restaurant_Customers.cpp
* @author GabrielCampelo
* Created on 2026-09-10 at 01:09:57
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

    vector<pair<int, int>> vec(2 * n);
    
    for (int i = 0; i < 2 * n; i += 2) {
        int a, b;
        cin >> a >> b;
        vec[i] = {a, i};
        vec[i + 1] = {b, i + 1};
    }

    sort(all(vec));
    
    vector<int> cc(2 * n);
    int nxt = 0;
    cc[vec[0].second] = nxt;

    for (int i = 1; i < 2 * n; i++) {
        if (vec[i].first > vec[i - 1].first) nxt++;
        cc[vec[i].second] = nxt;
    }
    
    vector<int> l(nxt), r(nxt);

    for (int i = 0; i < 2 * n; i += 2) {
        l[cc[i]]++;
        r[cc[i + 1]]++;
    }

    int ans = 0;
    int curr = 0;
    for (int i = 0; i < nxt; i++) {
        curr += l[i] - r[i];
        ans = max(ans, curr);
    }

    cout << ans << endl;

    return 0;
}