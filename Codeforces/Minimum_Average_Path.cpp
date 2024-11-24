/**
* @file Minimum_Average_Path.cpp
* https://codeforces.com/edu/course/2/lesson/6/4/practice/contest/285069/problem/B
*
* Created on 2024-11-23 at 22:59:40
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
vector<vector<pair<int, int>>> adj(MAX_N + 1);
vector<double> avg(MAX_N + 1);
vector<bool> vis(MAX_N + 1);
queue<int> q;

bool bfs(double &x, vector<int> &parent) {
    fill(avg.begin() + 1, avg.begin() + 1 + n, 0);
    fill(vis.begin() + 1, vis.begin() + 1 + n, false);
    int v = 1;
    vis[v] = true;
    q.push(v);
    parent[v] = v;
    

    while (!q.empty()) {
        v = q.front();
        q.pop();

        for (auto& [u, c] : adj[v]) {
            if (!vis[u] || avg[v] + c - x < avg[u]) {
                parent[u] = v;
                vis[u] = true;
                avg[u] = avg[v] + c - x;
                q.push(u);
            }
        }
    }

    return avg[n] <= 0;
}

int main() { _
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].pb({v, c});
    }

    double l = 0, r = 100;
    double mid;
    vector<int> parent(n + 1);
    for (int i = 0; i < 30; i++) {
        mid = (l + r) / 2;

        if (bfs(mid, parent)) r = mid;
        else l = mid;
    }
    
    
    bfs(l, parent);
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

    return 0;
}