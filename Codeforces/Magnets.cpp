/**
* @file Magnets.cpp
* https://codeforces.com/contest/344/problem/A
*
* Created on 2025-04-11 at 02:58:24
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
    int n;
    cin >> n;

    vector<int> vec(n);
    cin >> vec[0];
    int ans = 1;

    for (int i = 1; i < n; i++) {
        cin >> vec[i];
        if (vec[i] != vec[i - 1]) ans++;
    }

    cout << ans << endl;
    
    return 0;
}