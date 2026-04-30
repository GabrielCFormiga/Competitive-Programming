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
    freopen("lineup.in", "r", stdin);
	freopen("lineup.out", "w", stdout);
    vector<string> cows = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
    sort(all(cows));
    map<string, int> cow_index;
    for(int i = 0; i < cows.size(); i++) {
        cow_index[cows[i]] = i;
    }
    
    // read edges and update adj list
    int n;
    cin >> n;
    vector<vector<int>> adj(cows.size());
    while(n--) {
        string x, y, trash;
        cin >> x;
        cin >> trash >> trash >> trash >> trash;
        cin >> y;

        adj[cow_index[x]].pb(cow_index[y]);
        adj[cow_index[y]].pb(cow_index[x]);
    }

    vector<int> order;
    vector<bool> added(cows.size());
    for(int i = 0; i < cows.size(); i++) {
        if(!added[i] && adj[i].size() <= 1) {
            added[i] = true;
            order.pb(i);

            if(adj[i].size() == 1) {
                int prev = i;
                int at = adj[i][0];
                while(adj[at].size() == 2) {
                    added[at] = true;
                    order.pb(at);

                    int a = adj[at][0];
                    int b = adj[at][1];
                    int temp_at = (a == prev ? b : a);
                    prev = at;
                    at = temp_at;
                }

                added[at] = true;
                order.pb(at);
            }
        } 
    }

    for(int i = 0; i < order.size(); i++) {
        cout << cows[order[i]] << endl;
    }

    return 0;
}
