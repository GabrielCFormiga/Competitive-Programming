/**
* @file C_Chromatic.cpp
* @author GabrielCampelo
* Created on 2026-03-08 at 08:38:01
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

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    sort(all(a));
    sort(all(b));

    ll mn = LINF, mx = -1, curr = 0;
    int la = 0, ra = n - 1, lb = 0, rb = n - 1;
    for (int i = 0; i < n; i++) {
        if (a[la] + b[rb] <= b[lb] + a[ra]) {
            curr = a[la++] + b[rb--];
        } else {
            curr = b[lb++] + a[ra--];
        }
        mn = min(mn, curr);
        mx = max(mx, curr);
    }

    cout << mx - mn << endl;
    
    return 0;
}