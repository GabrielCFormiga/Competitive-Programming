/**
* @file Dreamoon_and_WiFi.cpp
* https://codeforces.com/problemset/problem/476/B
*
* Created on 2024-11-15 at 14:23:40
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

string s1, s2;

ll n;
ll posicao_final = 0;
ll respostas_corretas = 0;

void solve(ll posicao, ll index) {
    if (index == n) {
        if (posicao == posicao_final) respostas_corretas++;
        return;
    }

    if (s2[index] == '+') solve(posicao + 1, index + 1);
    else if (s2[index] == '-') solve(posicao - 1, index + 1);
    else {
        solve(posicao + 1, index + 1);
        solve(posicao - 1, index + 1);
    }
}


int main() { _
    cin >> s1 >> s2;

    n = s1.size();

    for (ll i = 0; i < n; i++) {
        if (s1[i] == '+') posicao_final++;
        else posicao_final--;
    }

    int cnt = 0; // contas as ?
    for (int i = 0; i < n; i++) if (s2[i] == '?') cnt++;

    solve(0, 0);

    cout << fixed << setprecision(12) << (double) respostas_corretas / (1 << cnt) << endl;

    return 0;
}