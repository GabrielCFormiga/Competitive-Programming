/**
* @file nn.cpp
*
* Created on 2025-06-10 at 16:14:23
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
#define MAX_D 1000100

int fat[MAX_D]; // Conta quantas vezes esse fator apareceu
int qtd[MAX_N]; // qtd[i] := o numeros de fatores diferentes que aparecem i vezes
bool estado[MAX_D]; // Guarda o estado da luz i

int main() { _
    int n;
    cin >> n;

    int mx = 0;
    qtd[0] = INF;

    while (n--) {
        int x;
        cin >> x;

        if (estado[x] == false) {
            estado[x] = true;
            // Ligou!!

            for (ll i = 2; i * i <= x; i++) {
                if (x % i == 0) {
                    qtd[fat[i]]--;
                    fat[i]++;
                    qtd[fat[i]]++;
                    mx = max(mx, fat[i]);
                    while (x % i == 0) x /= i;
                }
            }

            if (x > 1) {
                qtd[fat[x]]--;
                fat[x]++;
                qtd[fat[x]]++;
                mx = max(mx, fat[x]);
            }
        } else {
            estado[x] = false;
            // Desligou!!

            for (ll i = 2; i * i <= x; i++) {
                if (x % i == 0) {
                    if (fat[i] == mx && qtd[mx] == 1) mx--;
                    qtd[fat[i]]--;
                    fat[i]--;
                    qtd[fat[i]]++;
                    // mx = max(mx, fat[i]);
                    while (x % i == 0) x /= i;
                }
            }

            if (x > 1) {
                if (fat[x] == mx && qtd[mx] == 1) mx--;
                qtd[fat[x]]--;
                fat[x]--;
                qtd[fat[x]]++;
                // mx = max(mx, fat[x]);
            }
        } 

        cout << mx << endl;
    }
    
    return 0;
}