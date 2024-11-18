/**
* @file Splitting_an_Array.cpp
*
* Created on 2024-11-14 at 16:22:09
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

int n, k;
ll ar[MAX_N];

bool possible(ll m) {
    ll sum = 0, segs = 0;

    for (int i = 0; i < n; i++) {
        if (sum + ar[i] <= m) {
            sum += ar[i];
            if (i == n - 1) segs++; // fecha o segmento que termina na ultima posicao do array
        } else {
            segs++; // fecha o segmento atual
            sum = ar[i]; // cria um novo segmento
            if (i == n - 1) segs++; // ultimo elemento sozinho é um segmento
        }
    }

    return segs <= k;
}

int main() { _
    cin >> n >> k;
    
    ll l = 0, r = 0;

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        l = max(l, ar[i]);
        r += ar[i];
    }

    ll m;

    while (l < r) {
        m = l + (r - l) / 2;

        if (possible(m)) r = m;
        else l = m + 1;
    }
    
    cout << l << endl;

    return 0;
}