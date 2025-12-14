/**
* @file Coronavirus_Spread.cpp
* @author GabrielCampelo
* Created on 2025-12-13 at 21:31:16
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

int n;
int x[10];
bool vis[10];
int mx, mn;

void bfs(int v) {
    for (int i = 0; i < n; i++) vis[i] = false;

    int cnt = 1;
    vis[v] = true;
    queue<int> q;
    q.push(v);

    while (!q.empty()) {
        v = q.front();
        q.pop();

        for (int u = 0; u < n; u++) {
            if (vis[u]) continue;

            if (abs(x[u] - x[v]) <= 2) {
                cnt++;
                vis[u] = true;
                q.push(u);
            }
        }
    }

    mx = max(cnt, mx);
    mn = min(cnt, mn);
}


int main() { _
    int tt;
    cin >> tt;
    while (tt--) {
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }

        mx = 0;
        mn = INF;

        for (int i = 0; i < n; i++) {
            bfs(i);
        }

        cout << mn << ' ' << mx << endl;
    } 
    
    return 0;
}