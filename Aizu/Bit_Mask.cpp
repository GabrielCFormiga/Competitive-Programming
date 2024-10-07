/**
* @file Bit_Mask.cpp
* https://onlinejudge.u-aizu.ac.jp/problems/ITP2_10_D
*
* Created on 2024-10-07 at 00:53:41
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
    // Leitura das mascaras
    int n;
    cin >> n;

    vector<llu> masks(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        while (k--) {
            int j;
            cin >> j;
            masks[i] |= (1ULL << j);
        }
    }

    // Queries
    llu x = 0;
    int q, op, i;
    
    cin >> q;
    while (q--) {
        cin >> op >> i;
    
        switch (op) {
            case 0:
                cout << ((x & (1ULL << i)) > 0) << endl;
                break;
            case 1:
                x = x | masks[i];
                break;
            case 2:
                x = x & (~masks[i]);
                break;
            case 3:
                x = x ^ (masks[i]);
                break;
            case 4:
                cout << ((x & masks[i]) == masks[i]) << endl;
                break;
            case 5:
                cout << ((x & masks[i]) != 0) << endl;
                break;
            case 6:
                cout << ((x & masks[i]) == 0) << endl;
                break;
            case 7: 
                cout << __builtin_popcountll((x & masks[i])) << endl;
                break;
            case 8:
                cout << (x & masks[i]) << endl;
                break;
        }
    }
    
    return 0;
}