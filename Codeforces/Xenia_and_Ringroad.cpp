/**
* @file Xenia_and_Ringroad.cpp
* @author GabrielCampelo
* Created on 2026-02-21 at 23:37:05
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
    int n, m;
    cin >> n >> m;

    int curr = 1;

    vector<int> vec(m);
    ll ans = 0;
    for (int i = 0; i < m; i++) {
        cin >> vec[i];
        if (vec[i] == curr) continue;
        if (vec[i] > curr) ans += vec[i] - curr;
        else ans += n + 1 - curr + vec[i] - 1; 
        curr = vec[i];
    }
    
    cout << ans << endl;
    
    return 0;
}