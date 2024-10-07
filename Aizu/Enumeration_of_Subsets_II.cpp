/**
* @file Enumeration_of_Subsets_II.cpp
* https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_11_B
*
* Created on 2024-10-07 at 01:50:36
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
    int n, k;
    cin >> n >> k;

    int mask = 0;
    while (k--) {
        int x;
        cin >> x;
        mask |= (1 << x);
    }

    for (int i = 0; i < (1 << n); i++) {
        if ((i & mask) == mask) {
            cout << i << ':';

            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) 
                    cout << " " << j;
            }

            cout << endl;
        } 
    }

    return 0;
}