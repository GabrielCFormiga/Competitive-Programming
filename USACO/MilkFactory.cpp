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
    freopen("factory.in", "r", stdin);
	freopen("factory.out", "w", stdout);

    int n;
    cin >> n;
    vector<vector<int>> sair(n + 1);
    vector<vector<int>> entrar(n + 1);
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        sair[a].pb(b);
        entrar[b].pb(a);
    }

    // verifica se tem mais de um nó sem saída
    int count = 0;
    int index;
    for(int i = 1; i <= n; i++) {
        if(sair[i].size() == 0) {
            index = i;
            count++;
        }
        if(count == 2) {
            cout << -1 << endl;
            return 0;
        }
    }
    
    count == 0 ? cout << -1 << endl : cout << index << endl;

    return 0;
}
