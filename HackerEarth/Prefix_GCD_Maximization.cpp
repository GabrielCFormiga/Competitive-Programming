/**
* @file Prefix_GCD_Maximization.cpp
* https://www.hackerearth.com/practice/algorithms/dynamic-programming/bit-masking/practice-problems/algorithm/prefix-gcd-maximization-932aa648/
*
* Created on 2024-10-12 at 01:49:53
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
    
#define MAX_MASK (1 << 20)
#define MAX_N 20
    
int n;
ll dp[MAX_MASK];     // calcula a maior soma de gcd para a mascara
ll dp_gcd[MAX_MASK]; // guarda o gcd entre os elementos da mascara
ll ar[MAX_N];     // elementos
    
int main() { _
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        dp[(1 << i)] = ar[i];
    }
    
    // calcula dp_gcd
    for (int m = 0; m < (1 << n); m++) {
        ll aux = 0;
        bool first = true;
    
        for (int i = 0; i < n; i++) {
            if (m & (1 << i)) {
                if (first) {
                    aux = ar[i];
                    first = false;
                } else aux = __gcd(aux, ar[i]);
            }
        }
    
        dp_gcd[m] = aux;
    }
    
    // calcula dp
    for (int m = 0; m < (1 << n); m++) {
        for (int i = 0; i < n; i++) {
            if (m & (1 << i)) {
                dp[m] = max(dp[m], dp[m ^ (1 << i)] + dp_gcd[m]);
            }
        }
    }
    
    cout << dp[(1 << n) - 1] << endl;
    
    return 0;
}