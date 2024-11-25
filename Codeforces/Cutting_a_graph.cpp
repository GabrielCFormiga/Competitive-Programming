/**
* @file Cutting_a_graph.cpp
* https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/D
*
* Created on 2024-11-24 at 02:24:43
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

#define MAX_N 50100

int r[MAX_N];
int p[MAX_N];

int n, m, k;

int get(int v) {
    return p[v] = (p[v] == v ? v : get(p[v]));
}

void joint(int u, int v) {
    u = get(u);
    v = get(v);

    if (u == v) return;

    if (r[u] == r[v]) r[u]++;

    if (r[u] > r[v]) {
        p[v] = u;
    } else {
        p[u] = v;
    }
}

int main() { _
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) p[i] = i;

    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
    }

    vector<string> op(k);
    vector<pair<int, int>> args(k);

    for (int i = 0; i < k; i++) {
        cin >> op[i] >> args[i].first >> args[i].second;
    }
    
    vector<string> ans;

    for (int i = k - 1; i >= 0; i--) {
        if (op[i] == "cut") joint(args[i].first, args[i].second);
        else ans.pb((get(args[i].first) == get(args[i].second) ? "YES" : "NO"));
    }

    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << endl;
    }

    return 0;
}