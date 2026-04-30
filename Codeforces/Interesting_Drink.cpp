/**
* @file Interesting_drink.cpp
*
* Created on 2025-07-21 at 20:02:16
* @author GabrielCampelo
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
    
    vector<int> shops(n);

    for (int i = 0; i < n; i++) cin >> shops[i];

    sort(all(shops));

    int q;
    cin >> q;

    while (q--) {
        int coins;
        cin >> coins;

        int l = -1, r = n - 1;
        int m;

        while (l < r) {
            m = l + (r - l + 1) / 2;

            if (coins < shops[m]) r = m - 1;
            else l = m;
        }

        cout << l + 1 << endl;
    }

    return 0;
}