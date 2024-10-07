/**
* @file Bit_Flag.cpp
* https://onlinejudge.u-aizu.ac.jp/problems/ITP2_10_C
*
* Created on 2024-10-07 at 00:19:52
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
    
const llu MASK_64 = (1ULL << 64) - 1;
    
int main() { _
    llu x = 0;
    int q, op, i;
    
    cin >> q;
    while (q--) {
        cin >> op;
    
        switch (op) {
            case 0:
                cin >> i;
                cout << ((x & (1ULL << i)) > 0) << endl;
                break;
            case 1:
                cin >> i;
                x = x | (1ULL << i);
                break;
            case 2:
                cin >> i;
                x = x & (~(1ULL << i));
                break;
            case 3:
                cin >> i;
                x = x ^ (1ULL << i);
                break;
            case 4:
                cout << ((x & MASK_64) == MASK_64) << endl;
                break;
            case 5:
                cout << (x != 0) << endl;
                break;
            case 6:
                cout << (x == 0) << endl;
                break;
            case 7: {
                /* int cnt = 0;
                llu aux = x;
                
                while (aux) {
                    cnt++;
                    aux = (aux - 1ULL) & aux;
                }
    
                cout << cnt << endl; */
                cout << __builtin_popcountll(x) << endl;
                break;
            }
            case 8:
                cout << x << endl;
                break;
        }
    }
    
    return 0;
}