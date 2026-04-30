/**
* @file 2^a b^2.cpp
* https://atcoder.jp/contests/abc400/tasks/abc400_c
*
* Created on 2025-04-09 at 14:09:18
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
    ll n;
    cin >> n;
    cout << (ll)sqrtl(n/2) + (ll)sqrtl(n/4) << endl;
    
    return 0;
}