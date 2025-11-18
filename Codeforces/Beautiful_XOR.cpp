/**
* @file C_Beautiful_XOR.cpp
* @author GabrielCampelo
* Created on 2025-11-18 at 01:18:31
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
    int tt;
    cin >> tt;
    while (tt--) {
        int a, b;
        cin >> a >> b;

        int pot = 1;
        int ind = 0;
        while (pot * 2 <= a) {
            pot *= 2;
            ind++;
        }

        int x = 0;
        for (int j = ind - 1; j >= 0; j--) {
            if ((a & (1 << j)) == 0) {
                x |= (1 << j);
            }        
        }

        if (b > (a | x)) {
            cout << -1 << endl;
            continue;
        } else if (b == (a | x)) {
            cout << 1 << endl;
            cout << x << endl;
        } else {
            cout << 2 << endl;
            cout << x << ' ';
            cout << ((a | x) ^ b) << endl;
        }
    } 
    
    return 0;
}