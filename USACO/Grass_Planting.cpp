#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size() 

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

int main(){ _
    freopen("planting.in", "r", stdin);
	freopen("planting.out", "w", stdout);
    
    int n;
    cin >> n;
    int mx = 0;
    vector<vector<int>> adj(n + 1);
    vector<int> color(n + 1, 0);
    for(int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
        mx = max(mx, (int)adj[x].size());
        mx = max(mx, (int)adj[y].size());
    }

    cout << mx + 1 << endl;

    return 0;
}
