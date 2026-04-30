/**
* @file Mahmoud and Ehab and the message.cpp
*
* Created on 2025-11-04 at 04:31:05
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

int n, k, m;
int p[MAX_N];
int c[MAX_N];
int r[MAX_N];
vector<string> words;

int get(int u) {
    return p[u] = (p[u] == u ? u : get(p[u]));
}

void union_set(int u, int v) {
    u = get(u);
    v = get(v);

    if (u == v) return;

    if (r[u] == r[v]) r[u]++;

    if (r[u] > r[v]) {
        p[v] = u;
        c[u] = min(c[u], c[v]);
    } else {
        p[u] = v;
        c[v] = min(c[u], c[v]);
    }
}

int main() { _
    cin >> n >> k >> m;
    words.resize(n + 1);
    map<string, int> string_to_index;

    for (int i = 1; i <= n; i++) {
        cin >> words[i];
        string_to_index[words[i]] = i;
        p[i] = i;
    }

    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    while (k--) {
        int len;
        cin >> len;

        int u, v;

        cin >> u;
        len--;

        while (len--) {
            cin >> v;
            union_set(u, v);
        }
    }

    ll ans = 0;

    while (m--) {
        string s;
        cin >> s;

        int idx = string_to_index[s];

        ans += c[get(idx)];
    }

    cout << ans << endl;

    return 0;
}