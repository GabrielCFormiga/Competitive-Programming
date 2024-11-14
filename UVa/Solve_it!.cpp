/**
* @file Solve_it!.cpp
* https://vjudge.net/problem/UVA-10341
*
* Created on 2024-11-13 at 17:19:51
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

int p, q, r, s, t, u;

double f(double x) {
    return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

int main() { _
    while (cin >> p >> q >> r >> s >> t >> u) {

        // para 0 <= x <= 1 (1 quadrante)
        // pe^-xD + rcosxD + u + qsinxD + stanxD + tx^2D = 0

        double l = 0, r = 1;

        for (int i = 0; i < 1000; i++) {
            double m = (l + r) / 2;
            
            if (f(m) > 0) l = m;
            else r = m;
        }

        if (abs(f(r)) > 1e-4) cout << "No solution" << endl;
        else cout << fixed << setprecision(4) << r << endl;
    }
    
    return 0;
}