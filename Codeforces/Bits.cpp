/**
* @file Bits.cpp
* https://codeforces.com/problemset/problem/484/A
*
* Created on 2024-10-07 at 02:30:39
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

llu solve(llu l, llu r) {
    if (l == r) return l;
    
    llu mxpot2, aux = r;
    while (aux > 0) {
        mxpot2 = aux;
        aux = aux & (aux - 1);
    }

    if (mxpot2 <= l) return solve(l - mxpot2, r - mxpot2) + mxpot2;
    if (mxpot2 * 2 - 1 == r) return mxpot2 * 2 - 1;
    return mxpot2 - 1;
} 

int main() { _
    int q;
    llu l, r;
    
    cin >> q;
    while (q--) {
        cin >> l >> r;
        llu ans = solve(l, r);
        cout << ans << endl;
    }
    
    return 0;
}