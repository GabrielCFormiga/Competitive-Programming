#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    vector<vector<int>> g(n);
    for (int i = 0; i < n-1; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<bool> foi(n);
    vector<int> dist(n, INF);
    dist[0] = 0;

    queue<int> q;
    q.push(0);
    
    vector<int> ans;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        ans.push_back(u);
        foi[u] = true;
        dist[u] = 0;
        
        // dfs na dist? 
        auto dfs = [&](auto &&self, int v) -> void {
            for (auto viz : g[v]){
                if (!foi[viz]){
                    if (dist[v] + 1 < dist[viz] && dist[v] + 1 <= k){
                        pq.push(viz);
                        dist[viz] = dist[v] + 1;
                        self(self, viz);
                    }
                }
            }
        };  

        dfs(dfs, u);

        if (!pq.empty()){
            int aux = pq.top();
            q.push(aux);
            pq.pop();
            while(!pq.empty()){
                if (pq.top() == aux) pq.pop();
                else break;
            }
        }
    }

    for (int i = 0; i < n; i++){
        cout << ans[i] + 1 << " \n"[i == n-1];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}