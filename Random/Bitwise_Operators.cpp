/**
* @file Bitwise_Operators.cpp
* https://vjudge.net/contest/671605#problem/K
*
* Created on 2024-11-14 at 23:52:02
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
        int n;
        cin >> n;

        int b = n & (n - 1);
        int a = n & -n;

        if (b == 0) cout  << -1 << endl;
        else cout << a << ' ' << b << endl;
    } 
    
    return 0;
}