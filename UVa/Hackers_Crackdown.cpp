/**
* @file Hackers_Crackdown.cpp
* https://vjudge.net/problem/UVA-11825
*
* Created on 2024-10-06 at 20:30:34
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

#define MAX_MASK (1 << 16)

int n, m;

// é basicamente força bruta
// não testa todas as combinações por conta
// do "if (alc[s] == (1 << n) - 1)"
int solve(int mask, vector<int> &alc, vector<int> &dp) {
    if (dp[mask] == -1) {
        int ans = 0;

        for (int s = mask; s > 0; s = (s - 1) & mask) {
            if (alc[s] == (1 << n) - 1) {
                ans = max(ans, 1 + solve((mask ^ s), alc, dp));
            }
        }

        dp[mask] = ans;
    }
    return dp[mask];
}

int main() { _
    int teste = 1;

    while (cin >> n && n != 0) {
        cout << "Case " << teste++ << ": ";
        
        // guarda o alcance se executado o virus na mascara de computadores
        // alc[mascara] = mascara de alcance
        vector<int> alc((1 << n));

        for (int i = 0; i < n; i++) {
            alc[(1 << i)] = (1 << i); // executar o virus no computador i alcanca ele mesmo

            cin >> m;
            while (m--) {
                int v;
                cin >> v;
                alc[(1 << i)] |= (1 << v); // adiciona o vizinho de i no seu alcance
            }
        }

        vector<int> dp((1 << n), -1);

        // para cada mascara de computadores calcula o seu alcance
        for (int m = 0; m < (1 << n); m++) {
            int aux = 0;
            
            for (int i = 0; i < n; i++) {
                if (m & (1 << i)) aux |= alc[(1 << i)];
            }

            alc[m] = aux;            
        }

        cout << solve((1 << n) - 1, alc, dp) << endl;
    }
    
    return 0;}