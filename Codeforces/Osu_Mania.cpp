/**
* @file osu!mania.cpp
* https://codeforces.com/contest/2009/problem/B
*
* Created on 2024-11-24 at 03:15:14
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

#define MAX_N 550

int n;
char ar[MAX_N][4];

int main() { _
    int tt;
    cin >> tt;
    while (tt--) {
        vector<int> ans;
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 4; j++) {
                cin >> ar[i][j];
                if (ar[i][j] == '#') ans.pb(j + 1);
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            cout << ans[i] << (i == 0 ? endl : ' ');
        }
    } 
    
    return 0;
}