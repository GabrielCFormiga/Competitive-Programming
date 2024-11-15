/**
* @file XORwice.cpp
* https://codeforces.com/problemset/problem/1421/A
*
* Created on 2024-11-14 at 23:06:42
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


/* 
    6  = 00000110
    12 = 00001100

    x  = 00000100 
 */

int main() { _
    int tt;
    cin >> tt;
    while (tt--) {
        int a, b;
        cin >> a >> b;

        int x = 0;

        for (int i = 0; i < 32; i++) {
            if ((a & (1 << i)) && (b & (1 << i))) x += (1 << i);
        }

        cout << (x^a) + (x^b) << endl;
    } 
    
    return 0;
}