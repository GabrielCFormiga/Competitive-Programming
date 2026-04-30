/**
* @file Truck Driver.cpp
* @author GabrielCampelo
* Created on 2025-11-13 at 00:12:31
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
    int n, a, b;
    cin >> n >> a >> b;

    string s;
    cin >> s;

    vector<int> prefixb(n + 1);
    vector<int> prefixa(n + 1);
    for (int i = 0; i < n; i++) {
        prefixb[i + 1] = prefixb[i] + (s[i] == 'b' ? 1 : 0); 
        prefixa[i + 1] = prefixa[i] + (s[i] == 'a' ? 1 : 0); 
    }

    ll ans = 0;

    for (int i = 1; i <= n; i++) {
        // A condition
        int l = i, r = n + 1, m;
        while (l < r) {
            m = l + (r - l) / 2;
            if (prefixa[m] - prefixa[i - 1] >= a) r = m;
            else l = m + 1;
        }
        if (r == n + 1) break; // A condition not possible anymore

        // B condition
        int j = r;
        l = j - 1, r = n;
        while (l < r) {
            m = l + (r - l + 1) / 2;
            if (prefixb[m] - prefixb[i - 1] >= b) r = m - 1;
            else l = m;
        }

        ans += l - j + 1;
    }

    cout << ans << endl;

    return 0;
}