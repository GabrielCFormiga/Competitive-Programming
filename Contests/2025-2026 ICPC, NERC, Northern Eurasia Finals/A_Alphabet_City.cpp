/**
* @file A_Alphabet_City.cpp
* @author GabrielCampelo
* Created on 2025-12-17 at 08:30:42
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

int n, m;
ll gcnt[30]; 
vector<vector<ll>> scnt;
vector<string> vec;

bool possible(int k, int ind) {
    vector<ll> cnt(26);

    for (int j = 0; j < 26; j++) {
        cnt[j] -= (m + 1) * scnt[ind][j];
        cnt[j] += m * gcnt[j];
    }

    for (int j = 0; j < 26; j++) {
        if ((gcnt[j] - scnt[ind][j]) * k > cnt[j]) return false;
        cnt[j] -= (gcnt[j] - scnt[ind][j]) * k;
    }

    return true;
}

int main() { _
    cin >> n >> m;
    
    vec.resize(n);
    scnt.assign(n, vector<ll>(26));

    for (int i = 0; i < n; i++) {
        cin >> vec[i];
        for (int j = 0; j < vec[i].size(); j++) {
            gcnt[vec[i][j] - 'A']++;
            scnt[i][vec[i][j] - 'A']++;
        }
    }

    for (int i = 0; i < n; i++) {
        int l = -1, r = m;
        int m;

        while (l < r) {
            m = l + (r - l + 1) / 2;

            if (possible(m, i)) l = m;
            else r = m - 1;
        }

        cout << (l == -1 ? -1 : l) << (i == n - 1 ? endl : ' ');
    }

    return 0;
}