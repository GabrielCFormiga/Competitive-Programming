/**
* @file Madoka_and_the_Elegant_Gift.cpp
* https://codeforces.com/contest/1647/problem/B
*
* Created on 2024-11-20 at 01:17:28
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
        int n, m;
        cin >> n >> m;

        vector<vector<char>> table(n, vector<char>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> table[i][j];
            }
        }

        bool elegant = true;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < m - 1; j++) {
                int sum = table[i][j] - '0' + table[i + 1][j] - '0' + table[i][j + 1] - '0' + table[i + 1][j + 1] - '0';
                if (sum == 3) {
                    elegant = false;
                    break;
                }
            }
            if (!elegant) break;
        }

        if (!elegant) cout << "NO" << endl;
        else cout << "YES" << endl;
    } 
    
    return 0;
}