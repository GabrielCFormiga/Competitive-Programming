/**
* @file Div_Game.cpp
* @author GabrielCampelo
* Created on 2026-02-19 at 13:03:52
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
    ll n;
    cin >> n;

    int ans = 0;

    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int pot = 0;
            while (n % i == 0) {
                n /= i;
                pot++;
            }
            
            // // debbug
            // cout << "i: " << i << " pot: " << pot << endl;

            int fat = 1;
            while (pot >= fat) {
                pot -= fat;
                ans++;
                fat++;
            }
            // cout << ans << endl;
        }
    }

    if (n > 1) ans++;

    cout << ans << endl;
    
    return 0;
}