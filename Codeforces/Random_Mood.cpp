/**
* @file Random_Mood.cpp
* @author GabrielCampelo
* Created on 2026-02-23 at 18:54:27
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;

using ll = long long;
using llu = unsigned long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
    int n;
    double p;
    cin >> n >> p;

    double phap = 1.0;

    while (n) {
        if (n % 2 == 1) {
            phap = phap * (1 - p) + (1 - phap) * p;
        }   
        p = 2 * p * (1 - p);
        n /= 2;     
    }

    cout << fixed << setprecision(9) << phap << endl;

    return 0;
}