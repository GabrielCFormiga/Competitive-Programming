/**
* @file Ringo's_Favorite_Numbers_3.cpp
* https://atcoder.jp/contests/abc400/tasks/abc400_e
*
* Created on 2025-04-08 at 19:50:55
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

#define K_LIMIT 1000001

int main() { _
    vector<int> num_distinct_factors(K_LIMIT);

    for (int i = 2; i < K_LIMIT; i++) {
        if (num_distinct_factors[i] == 0) {
            for (int j = i; j < K_LIMIT; j += i) {
                num_distinct_factors[j]++;
            }
        }
    }

    // k[i]^2 is a 400 number
    vector<int> k;

    for (int i = 2; i < K_LIMIT; i++) {
        if (num_distinct_factors[i] == 2) k.pb(i);
    }

    int tt;
    cin >> tt;
    
    while (tt--) {
        ll a;
        cin >> a;

        int l = 0, r = k.size() - 1, m;

        while (l < r) {
            m = l + (r - l + 1) / 2;

            if ((ll) k[m] * k[m] > a) r = m - 1;
            else l = m;
        }

        cout << (ll) k[l] * k[l] << endl;
    } 
    
    return 0;
}