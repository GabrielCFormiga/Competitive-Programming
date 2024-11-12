/**
* @file Greatest_Common_Divisor.cpp
* https://csacademy.com/contest/archive/task/gcd
*
* Created on 2024-11-10 at 01:24:17
* @author GabrielCampelo
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

typedef long long ll;

ll recursive_gcd(ll a, ll b) {
    if (b == 0) return a;
    else return recursive_gcd(b, a % b);
}

ll gcd(ll a, ll b) {
    while(b){
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() { _
    ll a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;

    return 0;
}