/**
* @file Anansi's_Cobweb.cpp
* https://acm.timus.ru/problem.aspx?space=1&num=1671
*
* Created on 2025-03-07 at 23:30:12
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

#define MAX_M 100100
#define MAX_N 100100

int n, m;
pair<int, int> edges[MAX_M];
int p[MAX_N];
int r[MAX_N];
int pieces;

int get(int u) {
    return p[u] = (p[u] == u ? u : get(p[u]));
}

void unionn(int u, int v) {
    u = get(u);
    v = get(v);

    if (u == v) return;

    if (r[u] == r[v]) r[u]++;

    if (r[u] > r[v]) {
        p[v] = u;
    } else {
        p[u] = v;
    }

    pieces--;
}

int main() { _
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) p[i] = i;
    pieces = n;

    for (int i = 1; i <= m; i++) {
        cin >> edges[i].first >> edges[i].second;
    }

    vector<pair<int, int>> tear;
    int q, pos;
    cin >> q;

    for (int i = 0; i < q; i++) {
        cin >> pos;
        tear.pb(edges[pos]);
        edges[pos].first = -1;
    }

    for (int i = 1; i <= m; i++) {
        if (edges[i].first == -1) continue;
        unionn(edges[i].first, edges[i].second);
    }

    vector<int> ans;

    for (int i = tear.size() - 1; i >= 0; i--) {
        ans.pb(pieces);
        unionn(tear[i].first, tear[i].second);
    }

    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << (i == 0 ? endl : ' ');
    }
    
    return 0;
}