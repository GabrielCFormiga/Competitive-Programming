/**
* @file Madoka_and_Childish_Pranks.cpp
* https://codeforces.com/contest/1647/problem/C
*
* Created on 2024-11-20 at 01:34:46
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

struct Square {
    int itl, jtl, ibr, jbr;
    Square(int itl, int jtl, int ibr, int jbr) {
        this->itl = itl;
        this->jtl = jtl;
        this->ibr = ibr;
        this->jbr = jbr;
    }
};

int main() { _
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;

        vector<vector<char>> picture(n + 1, vector<char>(m + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> picture[i][j];
            }
        }

        bool possible = true;
        vector<Square> ans;
        for (int i = n; i >=  1; i--) {
            for (int j = m; j >= 1; j--) {
                if (picture[i][j] == '1') {
                    if (j > 1) {
                        ans.pb(Square(i, j - 1, i, j));
                    } else if (i > 1) {
                        ans.pb(Square(i - 1, j, i, j));
                    } else {
                        possible = false;
                        break;
                    }
                }
            }
        }

        if (!possible) cout << -1 << endl;
        else {
            cout << ans.size() << endl;
            for (auto &s : ans) {
                cout << s.itl << ' ' << s.jtl << ' ' << s.ibr << ' ' << s.jbr << endl;
            }
        }
    } 
    
    return 0;
}