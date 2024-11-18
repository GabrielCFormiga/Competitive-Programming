/**
* @file Minimum_maximum_on_the_Path.cpp
* https://codeforces.com/edu/course/2/lesson/6/3/practice/contest/285083/problem/D
*
* Created on 2024-11-14 at 17:11:34
* @author GabrielCampelo
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define mk make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n, m, d;
vector<vector<pair<int, int>>> adj; // {destino, peso}

bool possible(vector<int> &parent) {
    for (int i = 1; i <= n; i++) parent[i] = 0;
    vector<ll> dist(n + 1, LINF); 
    queue<int> q;
    int v = 1;
    q.push(v);
    parent[v] = v;
    dist[v] = 0;    

    while (!q.empty()) {
        v = q.front();
        q.pop();

        for (auto& [u, c] : adj[v]) {
            if (dist[v] + 1 < dist[u] && dist[v] + 1 <= d && c <= m) {
                parent[u] = v;
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }

    return dist[n] < LINF;
}

int main() {
    cin >> n >> m >> d;

    int mx = 0;
    
    adj.resize(n + 1);
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        mx = max(mx, c);
        adj[a].pb({b, c});
    }

    vector<int> parent(n + 1);
    int l = 0, r = mx + 1; 
    while (l < r) {
        m = l + (r - l) / 2;
        if (possible(parent)) r = m;
        else l = m + 1;
    }

    if (l == mx + 1) cout << -1 << endl;
    else {
        m = l;
        possible(parent);
        stack<int> path;
        int v = n;
        while (parent[v] != v) {
            path.push(v);
            v = parent[v];
        }
        cout << path.size() << endl;
        cout << 1;
        while (!path.empty()) {
            cout << ' ' << path.top();
            path.pop(); 
        }
        cout << endl;
    }

    return 0;
}