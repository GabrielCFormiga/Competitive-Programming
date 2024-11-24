/**
* @file Disjoint_Sets_Union_2.cpp
* https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/B
*
* Created on 2024-11-24 at 01:19:47
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

#define MAX_N 300100

int n, m;
int qtd[MAX_N];
int mn[MAX_N];
int mx[MAX_N];
int p[MAX_N];
int r[MAX_N];

int get(int u) {
    return p[u] = (p[u] == u ? u : get(p[u]));
}

void joint(int u, int v) {
    u = get(u);
    v = get(v);

    if (u == v) return;

    if (r[u] == r[v]) r[u]++;

    if (r[u] > r[v]) {
        p[v] = u;
        qtd[u] += qtd[v];
        mn[u] = min(mn[u], mn[v]);
        mx[u] = max(mx[u], mx[v]);
    } else {
        p[u] = v;
        qtd[v] += qtd[u];
        mn[v] = min(mn[u], mn[v]);
        mx[v] = max(mx[u], mx[v]);
    }
}

int main() { _
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        mn[i] = mx[i] = p[i] = i;
        qtd[i] = 1;
    }

    string op;
    int u, v;

    while (m--) {
        cin >> op;

        if (op == "union") {
            cin >> u >> v;
            joint(u, v);
        } else {
            cin >> u;
            u = get(u);
            cout << mn[u] << ' ' << mx[u] << ' ' << qtd[u] << endl;
        } 
    }

    return 0;
}