/**
* @file Enumeration_of_Subsets_I.cpp
* https://onlinejudge.u-aizu.ac.jp/problems/ITP2_11_A
*
* Created on 2024-10-07 at 01:25:15
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

    int limit = (1 << n);
    cout << "0:\n";
    for (int i = 1; i < limit; i++) {
        cout << i << ": ";
        
        int len = __builtin_popcount(i);
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                cout << j;
                cout << (++cnt == len ? '\n' : ' ');
            }
        }
    }
    
    return 0;
}