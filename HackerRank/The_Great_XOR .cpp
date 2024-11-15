/**
* @file The_Great_XOR .cpp
* https://www.hackerrank.com/challenges/the-great-xor/problem
*
* Created on 2024-11-15 at 16:25:21
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

#define MAX_BIT 40

/* 
    1 < x < 1e10

    a ^ x > x
    0 < a < x

    qnts a's ?

 */
int main() { _
    int q;
    ll x;

    cin >> q;
    while (q--) {
        cin >> x;

        int mx = 0; // posicao do bit 1 mais significativo

        for (int j = 0; j < MAX_BIT; j++) {
            if (x & (1LL << j)) mx = j;
        } 

        ll ans = 0;
        for (int j = mx; j >= 0; j--) {
            if ((x & (1LL << j)) == 0) ans += pow(2, j);
        }

        cout << ans << endl;
    }
    
    return 0;
}