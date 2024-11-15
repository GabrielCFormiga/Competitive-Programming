/**
* @file Bars.cpp
* https://vjudge.net/problem/UVA-12455
*
* Created on 2024-11-14 at 23:22:30
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
    int tt;
    cin >> tt;
    while (tt--) {
        int n, p;
        cin >> n >> p;

        vector<int> bars(p);
        for (int i = 0; i < p; i++) cin >> bars[i];

        bool possible = false;
        for (int mask = 0; mask < (1 << p); mask++) {
            int sum = 0;

            for (int j = 0; j < p; j++) {
                if (mask & (1 << j)) sum += bars[j];
            }

            if (sum == n) {
                possible = true;
                break;
            }
        }

        if (possible) cout << "YES" << endl;
        else cout << "NO" << endl;
    } 
    
    return 0;
}