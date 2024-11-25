/**
* @file People_are_leaving.cpp
* https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/A
*
* Created on 2024-11-25 at 02:09:02
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

#define MAX_N 1000100

int n, m;
int p[MAX_N];
int mx[MAX_N];
int r[MAX_N];

int get(int v) {
    return p[v] = (p[v] == v ? v : get(p[v]));
}

void joint(int u, int v) {
    u = get(u);
    v = get(v);

    if (u == v) return;

    if (r[u] == r[v]) r[u]++;

    if (r[u] > r[v]) {
        mx[u] = max(mx[u], mx[v]);
        p[v] = u;
    } else {
        mx[v] = max(mx[v], mx[u]);
        p[u] = v;
    }
}

int main() { _
    cin >> n >> m;
    
    for (int i = 1; i <= n + 1; i++) {
        p[i] = mx[i] = i;
    }

    char op;
    int x;
    while (m--) {
        cin >> op >> x;

        if (op == '?') {
            int res = mx[get(x)];
            cout << (res == n + 1 ? -1 : res) << endl;
        } else {
            joint(x, x + 1);
        }
    }

    return 0;
}