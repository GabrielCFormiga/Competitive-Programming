/**
* @file Soldier_and_Number_Game.cpp
* https://codeforces.com/contest/546/problem/D
*
* Created on 2025-04-06 at 12:23:50
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

#define MAX_N 5000001

int main() { _
    vector<int> sp(MAX_N);
    for (int i = 2; i < MAX_N; i += 2) sp[i] = 2;
    for (ll i = 3; i < MAX_N; i += 2) {
        if (sp[i] == 0) {
            sp[i] = i;
            for (ll j = i * i; j < MAX_N; j += i) if (sp[j] == 0) sp[j] = i;
        }
    }

    // vector<int> score(MAX_N);
    vector<int> prefix(MAX_N);
    for (int i = 2; i < MAX_N; i++) {
        int cnt = 0;
        int n = i;
        while (1) {
            cnt++;
            if (sp[n] == n) break;
            else n /= sp[n];
        }
        prefix[i] = cnt + prefix[i - 1];
    }


    int tt;
    cin >> tt;

    while (tt--) {
        int a, b;
        cin >> a >> b;

        cout << prefix[a] - prefix[b] << endl;
    } 
    
    return 0;
}