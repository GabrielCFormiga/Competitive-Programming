/**
* @file Forest_Queries.cpp
* https://cses.fi/problemset/task/1652
*
* Created on 2025-03-07 at 09:19:12
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
    int n, q;
    cin >> n >> q;

    vector<vector<int>> prefix(n + 1, vector<int>(n + 1));

    char c;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c;
            prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + (c == '*');
        }
    }

    int itl, jtl, ibr, jbr;
    while (q--) {
        cin >> itl >> jtl >> ibr >> jbr;
        cout << prefix[ibr][jbr] - prefix[ibr][jtl - 1] - prefix[itl - 1][jbr] + prefix[itl - 1][jtl - 1] << endl;
    }
    
    return 0;
}