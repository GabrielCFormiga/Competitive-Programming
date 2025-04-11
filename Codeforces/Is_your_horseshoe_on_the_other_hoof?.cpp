/**
* @file Is_your_horseshoe_on_the_other_hoof?.cpp
* https://codeforces.com/contest/228/problem/A
*
* Created on 2025-04-11 at 13:36:29
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
    int n = 4;
    vector<int> color(n);
    for (int i = 0; i < n; i++) cin >> color[i];
    set<int> s(all(color));
    cout << 4 - s.size() << endl;
    return 0;
}