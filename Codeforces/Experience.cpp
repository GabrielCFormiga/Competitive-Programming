/**
* @file xperience.cpp
* https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/C
*
* Created on 2024-11-24 at 01:33:24
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

#define MAX_N 200100

int n, m;
int xp[MAX_N];
int p[MAX_N];
int r[MAX_N];
int extra[MAX_N];

int get(int u) {
    while (u != p[u]) u = p[u];
    return u;
}

void joint(int u, int v) {
    u = get(u);
    v = get(v);

    if (u == v) return;

    if (r[u] == r[v]) r[u]++;

    if (r[u] > r[v]) {
        extra[v] += xp[u];
        p[v] = u;
    } else {
        extra[u] += xp[v];
        p[u] = v;
    }
}

void add(int u, int v) {
    u = get(u);
    xp[u] += v;
}

int main() { _
    cin >> n >> m;

    for (int i = 1; i <= n; i++) p[i] = i;
    
    string op;
    int u, v;

    while (m--) {
        cin >> op;

        if (op == "join") {
            cin >> u >> v;
            joint(u, v);
        } else if (op == "add") {
            cin >> u >> v;
            add(u, v);
        } else {
            cin >> u;
            int ans = 0;
            while (p[u] != u) {
                ans += xp[u] - extra[u];
                u = p[u];
            }
            ans += xp[u] - extra[u];
            cout << ans << endl;
        } 
    }

    return 0;
}