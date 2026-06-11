/**
* @file Static_Range_Sum_Queries.cpp
* @author GabrielCampelo
* Created on 2026-06-11 at 13:11:42
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
    int n, q;
    cin >> n >> q;
    vector<int> vec(n + 1);
    vector<ll> prefix(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> vec[i];
        prefix[i] = prefix[i - 1] + vec[i];
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << prefix[r] - prefix[l - 1] << endl;
    }
    return 0;
}