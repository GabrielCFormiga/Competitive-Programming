/**
* @file Disjoint_Sets_Union.cpp
* https://codeforces.com/edu/course/2/lesson/7/1/practice
*
* Created on 2024-11-24 at 01:09:07
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

#define MAX_N 100100

int n, m;
int p[MAX_N];
int r[MAX_N];

int get(int u) {
    return p[u] = (p[u] == u ? u : get(p[u]));
}

void joint(int u, int v) {
    u = get(u);
    v = get(v);

    if (r[u] == r[v]) r[u]++;

    if (r[u] > r[v]) {
        p[v] = u;
    } else {
        p[u] = v;
    }
}

int main() { _
    cin >> n >> m;

    for (int i = 1; i <= n; i++) p[i] = i;

    string op;
    int u, v;

    while (m--) {
        cin >> op >> u >> v;

        if (op == "union") {
            joint(u, v);
        } else {
            cout << (get(u) == get(v) ? "YES" : "NO") << endl;
        } 
    }

    return 0;
}