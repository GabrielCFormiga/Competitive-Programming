/**
* @file G_Garlands.cpp
* @author GabrielCampelo
* Created on 2026-03-01 at 08:29:05
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
    string s;
    cin >> s;

    vector<int> cnt(30);
    for (char c : s) {
        cnt[c - 'A']++;
    }
    
    int ans = 0;
    int tap = min({cnt['T' - 'A'], cnt['A' - 'A'], cnt['P' - 'A']});
    ans += tap;
    cnt['T' - 'A'] -= tap;
    cnt['A' - 'A'] -= tap; 
    cnt['P' - 'A'] -= tap;
    int tup = min({cnt['T' - 'A'], cnt['U' - 'A'], cnt['P' - 'A']});
    ans += tup;
    cout << ans << endl;

    return 0;
}