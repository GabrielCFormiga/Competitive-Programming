/**
* @file String_Game.cpp
* https://codeforces.com/problemset/problem/778/A
*
* Created on 2024-11-14 at 01:27:48
* @author GabrielCampelo
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;

string t, // original
       p; // alvo

bool possible(string s) {
    int j = 0;
    
    for (int i = 0; i < t.size(); i++) {
        if (j == p.size()) break;
        if (s[i] == p[j]) j++;
    }

    return j == p.size();
}

int main() { _
    cin >> t >> p;

    vector<int> perms(t.size() + 1);
    perms[0] = 0;
    for (int i = 1; i < perms.size(); i++) cin >> perms[i];

    /* vector<string> vec(t.size() + 1);
    vec[0] = t;

    int pos;
    for (int i = 1; i <= t.size(); i++) {
        vec[i] = vec[i - 1];
        cin >> pos;
        vec[i][pos - 1] = '*';
    } */

    // for (int i = 0; i < vec.size(); i++) cout << vec[i] << endl;

    int l = 0, r = t.size(); 
    int m;

    int ans = 0;
    while (l <= r) {
        m = l + (r - l) / 2;
        
        string aux = t;
        for (int i = 1; i <= m; i++) {
            aux[perms[i] - 1] = '*';
        }

        if (possible(aux)) {
            ans = m;
            l = m + 1;    
        }
        else r = m - 1; 
    }

    cout << ans << endl;

    return 0;
}