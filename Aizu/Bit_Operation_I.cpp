/**
* @file Bit_Operation_I.cpp
* https://onlinejudge.u-aizu.ac.jp/problems/ITP2_10_A
*
* Created on 2024-10-06 at 23:10:54
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
    unsigned n;
    cin >> n;

    bitset<32> bs(n);

    cout << bs << endl;
    cout << ~bs << endl;
    cout << (bs << 1) << endl;
    cout << (bs >> 1) << endl;

    return 0;
}