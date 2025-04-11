/**
* @file Sereja_and_Dima.cpp
* https://codeforces.com/contest/381/problem/A
*
* Created on 2025-04-11 at 03:11:33
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
    
    int ans[2];
    ans[0] = ans[1] = 0;

    vector<int> vec(n);
    for (int i = 0; i < n; i++) cin >> vec[i];
    
    int l = 0, r = n - 1;

    for (int i = 0; i < n; i++) {
        if (vec[l] > vec[r]) ans[i % 2] += vec[l++];
        else ans[i % 2] += vec[r--];
    }

    cout << ans[0] << ' ' << ans[1] << endl;

    return 0;
}