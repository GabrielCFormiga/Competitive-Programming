/**
* @file F_Formação_da_dupla_perfeita.cpp
* @author GabrielCampelo
* Created on 2026-07-25 at 10:20:39
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
    int n, f;
    cin >> n >> f;

    int PERFECT = (1 << f) - 1;
    
    vector<int> vec(n);

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        int MASK = 0;
        for (int j = 0; j < f; j++) {
            if (s[j] == 'S') {
                MASK |= (1 << j);
            }
        }

        vec[i] = MASK;
    }

    ll ans = 0; 
    vector<ll> cnt((1 << f) + 1); // 0000 -> 1111

    for (int MASK : vec) {
        int COMP = PERFECT ^ MASK;
        ans += cnt[COMP];

        for (int s = MASK; s; s= (s-1) & MASK) {
            cnt[s]++;
        }

        cnt[0]++;
    }

    cout << ans << endl;

    return 0;
}