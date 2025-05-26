#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size() 

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

/*Return Value Suppression: The (void) cast before the expression is used to 
explicitly indicate to the compiler that the return value is intentionally ignored. 
This can be done to avoid compiler warnings when a return value is not used, 
especially when it's intended behavior (as in the case of freopen).*/
void setIO(string name = "") {
    if(sz(name)) {
        (void)freopen((name + ".in").c_str(), "r", stdin);
        (void)freopen((name + ".out").c_str(), "w", stdout);
    }
}


int main(){ _
    setIO("revegetate");
    int nodes, cows;
    cin >> nodes >> cows;
    vector<vector<int>> adj(nodes + 1);
    vector<int> color(nodes + 1, 0);

    for(int i = 0; i < cows; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    for(int i = 1; i <= nodes; i++) {
        // verificar cores de vizinhos
        vector<int> adj_colors(5, 0);
        for(int j = 0; j < adj[i].size(); j++) {
            adj_colors[color[adj[i][j]]] = 1;
        }

        for(int j = 1; j <= 4; j++) {
            if(adj_colors[j] == 0) {
                color[i] = j;
                break;
            }
        }
    }

    for(int i = 1; i <= nodes; i++) {
        cout << color[i];
    }
    cout << endl;



    return 0;
}
