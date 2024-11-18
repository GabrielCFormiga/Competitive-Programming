/**
* @file Qualifying_Contest.cpp
* https://codeforces.com/problemset/problem/659/B
*
* Created on 2024-11-17 at 23:23:29
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
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, string>>> vec(m + 1);

    string surname;
    int region, score;
    for (int i = 0; i < n; i++) {
        cin >> surname >> region >> score;
        vec[region].pb({score, surname});
    }

    for (int i = 1; i <= m; i++) {
        sort(all(vec[i]), [](pair<int, string> a, pair<int, string> b){
            return a.first > b.first;
        });
        if (vec[i].size() > 2 && vec[i][2].first == vec[i][1].first) cout << '?' << endl;
        else cout << vec[i][0].second << ' ' << vec[i][1].second << endl;
    }
    
    return 0;
}