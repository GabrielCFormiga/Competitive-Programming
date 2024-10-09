/**
* @file XOR_World.cpp
* https://atcoder.jp/contests/abc121/tasks/abc121_d
*
* Created on 2024-10-08 at 16:07:48
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

ll g(ll x) {
    if (x == -1) return 0;
    
    int r = x % 4;
    if (r == 0) return x;
    if (r == 1) return 1;
    if (r == 2) return x + 1;
    if (r == 3) return 0;
}

int main() { _
    ll a, b;
    cin >> a >> b;
    cout << (g(b) ^ g(a - 1)) << endl;
    
    return 0;
}