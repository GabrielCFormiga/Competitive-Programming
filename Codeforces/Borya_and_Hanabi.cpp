/**
* @file Borya_and_Hanabi.cpp
* https://codeforces.com/problemset/problem/442/A
*
* Created on 2024-10-11 at 23:34:41
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

int main() { _    
    map<char,int> mp;
    string CORES = "RGBYW";
    for (int i = 0; i < 5; i++) mp[CORES[i]] = i;
    
    int n;
    cin >> n;

    // salva as cartas de Borya
    vector<string> cards(n);
    for (int i = 0; i < n; i++) cin >> cards[i];

    int mn = INF;
    int ans;
    // existem 10 dicas possiveis
    for (int mask = 0; mask < (1 << 10); mask++) {
        // armazenam se foi possivel diferenciar
        vector<bool> cor(5);
        vector<bool> valor(5);   

        // verifica as dicas de cor
        for (int j = 0; j < 5; j++) {
            if (mask & (1 << j)) {
                cor[j] = true; 
            }
        }

        // verifica as dicas de valor
        for (int j = 0; j < 5; j++) {
            if (mask & (1 << (j + 5))) {
                valor[j] = true;
            }
        }

        // verifica se sempre eh possivel diferenciar um par de cartas
        bool candidato = true;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (cards[i] == cards[j]) continue;
 
                bool diff_cor = false;
                bool diff_valor = false;
                if ((cor[mp[cards[i][0]]] || cor[mp[cards[j][0]]]) && cards[i][0] != cards[j][0]) diff_cor = true;
                if ((valor[cards[i][1] - '1'] || valor[cards[j][1] - '1']) && cards[i][1] != cards[j][1]) diff_valor = true;
                if (!diff_cor && !diff_valor) {
                    candidato = false;
                    break;
                }
            }
            if (!candidato) break;
        }

        if (candidato && mn > __builtin_popcount(mask)) {
            ans = mask;
            mn = __builtin_popcount(mask);
        }
    }

    cout << mn << endl;
    // cout << ans << endl;
    
    return 0;
}

