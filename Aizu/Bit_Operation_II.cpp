/**
* @file Bit_Operation_II.cpp
* https://onlinejudge.u-aizu.ac.jp/problems/ITP2_10_B
*
* Created on 2024-10-07 at 00:06:55
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
    unsigned a, b;
    cin >> a >> b;

    bitset<32> bs;
    bs = a&b;
    cout << bs << endl;
    bs = a|b;
    cout << bs << endl;    
    bs = a^b;
    cout << bs << endl;
    
    return 0;
}