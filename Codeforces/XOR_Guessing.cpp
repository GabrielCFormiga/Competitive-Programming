/**
* @file XOR_Guessing.cpp
* https://codeforces.com/problemset/problem/1207/E
*
* Created on 2024-10-08 at 16:59:51
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

/* 
    temos 14 bits para x
    podemos divir x em l + r
    r equivale aos bits 0th até 6th
    l equivale ao resto de x 
 */

int main() { _
    // mandar numeros menores que (1 << 7)
    cout << "?";
    for (int i = 0; i < 100; i++) {
        cout << " " << i;
    }
    cout << endl;
    cout.flush();
    
    // l é a parte esquerda da resposta
    int l;
    cin >> l;
    // remove os bits da direita de l
    l >>= 7;
    l <<= 7;

    // mandar numeros com os bits 0th até 6th iguais a zero
    cout << "?";
    for (int i = 1; i <= 100; i++) {
        cout << " " << i * (1 << 7);
    }
    cout << endl;
    cout.flush();
    
    int r;
    cin >> r;
    // remove os bits da esquerda de r
    r = r & ((1 << 7) - 1);

    cout << "! " << r + l << endl;
    cout.flush();
    
    return 0;
}