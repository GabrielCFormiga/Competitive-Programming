/**
* @file Flipping_bits.cpp
* https://www.hackerrank.com/challenges/flipping-bits/problem
*
* Created on 2024-11-15 at 00:32:31
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
        unsigned n;
        cin >> n;

        for (int j = 0; j < 32; j++) {
            n ^= (1 << j);
        } 

        cout << n << endl;
    } 
    
    return 0;
}