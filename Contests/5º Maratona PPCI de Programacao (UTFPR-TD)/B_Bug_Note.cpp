/**
* @file B_Bug_Note.cpp
* @author GabrielCampelo
* Created on 2026-07-25 at 10:04:15
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;

using ll = long long;
using llu = unsigned long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
    int n, q;
    cin >> n >> q;

    vector<pair<string, int>> vec(n); // {name, lines}
    map<string, int> mpid;
    vector<int> cnt(n);
    vector<bool> bug(n, false);

    for (int i = 0; i < n; i++) {
        cin >> vec[i].first >> vec[i].second;
        mpid[vec[i].first] = i;
    }

    int k = 0;
    while (q--) {
        string s;
        int l;
        cin >> s >> l;

        if (mpid.find(s) == mpid.end()) continue;
        
        int id = mpid[s];
        if (cnt[id] >= 3) continue;
        
        if (l > vec[id].second) {
            cnt[id]++;
            continue;
        }

        cnt[id]++;
        if (bug[id] == false) k++;
        bug[id] = true;
    }
    
    if (k == 0) {
        cout << -1 << endl;
    } else {
        cout << k << endl;
        for (int i = 0; i < n; i++) {
            if (bug[i]) {
                cout << vec[i].first << endl;
            }
        }
    }

    return 0;
}