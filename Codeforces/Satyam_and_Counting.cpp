/**
* @file Satyam_and_Counting.cpp
* https://codeforces.com/contest/2009/problem/D
*
* Created on 2024-11-24 at 03:33:52
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

#define MAX_N 200100

int n;

// pair<int, int> points[MAX_N];

int main() { _
    int tt;
    cin >> tt;
    while (tt--) {
        cin >> n;

        vector<int> p1, p2;
        vector<bool> b1(n + 1), b2(n + 1);
        int x, y;
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            if (y == 0) {
                p1.pb(x);
                b1[x] = true;
            } else {
                p2.pb(x);
                b2[x] = true;
            }
        }

        ll ans = 0;
        for (auto &x : p1) {
            if (x >= 1 && x < n && b2[x + 1] && b2[x - 1]) ans++; 
            if (b2[x]) {
                ans += p1.size() - 1 + p2.size() - 1;
            }
        }

        for (auto &x : p2) {
            if (x >= 1 && x < n && b1[x + 1] && b1[x - 1]) ans++; 
        }

        // faltam os que n tem ang reto na vertical
        cout << ans << endl;
    } 
    
    return 0;
}