/**
* @file And_Then_There_Were_K.cpp
* https://codeforces.com/problemset/problem/1527/A

* Created on 2024-10-04 at 01:14:00
* @author GabrielCampelo
*/

#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

/* 
    n = n & (n - 1) limpa o bit 1 menos significativo

    basta ir removendo os bits 1 menos significativos
    ateh que n seja uma potencia de 2
    nesse momento, a resposta serah n - 1
*/

int main() { _
    int tt, n;
    cin >> tt;
    while (tt--) {
        cin >> n;
        
        int ans = n;
        while (n) {
            ans = n - 1;
            n = n & n - 1;
        }

        cout << ans << endl;
    } 
    
    return 0;
}