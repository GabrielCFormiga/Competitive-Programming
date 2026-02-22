/**
* @file Printing_Divisors.cpp
* @author GabrielCampelo
* Created on 2026-02-19 at 14:55:59
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
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) {
        cout << "Case " << t << ":" << endl; 
        
        ll n;
        cin >> n;
        
        vector<ll> ans;
        ans.pb(1);
        
        for (ll p = 2; p * p <=  n; p++) {
            int len = ans.size();
            while (n % p == 0) {
                n /= p;
                int lim = ans.size();
                for (int i = 1; i <= len; i++) {
                    ans.pb(ans[lim - i] * p);
                }
            }
        }

        if (n > 1) {
            for (int i = ans.size() - 1; i >= 0; i--) {
                ans.pb(ans[i] * n);
            }
        }

        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << (i == ans.size() - 1 ? endl : ' ');
        }
    } 
    
    return 0;
}