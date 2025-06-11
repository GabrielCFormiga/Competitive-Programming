/**
* @file h.cpp
*
* Created on 2025-05-24 at 14:53:45
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
    llu x;
    cin >> x;

    int qtd_bits = 1;
    llu ans = 1;

    while (1) {
        if ((1LLU << qtd_bits) + 1 > x) break;
        qtd_bits++;
    }

    if (qtd_bits == 1) {
        cout << 1 << endl;
        return 0;
    }

    ans = (1LLU << (qtd_bits - 1)) + 1;

    int l = 2, r = qtd_bits - 1;

    while (l <= r) {
        llu aux = ans;
        
        if (l == r) aux += (1LLU << (l - 1));
        else aux += (1LLU << (l - 1)) + (1LLU << (r - 1));
        
        if (aux <= x) ans = aux; 
        
        l++;
        r--;
    }
    
    cout << ans << endl;

    return 0;
}