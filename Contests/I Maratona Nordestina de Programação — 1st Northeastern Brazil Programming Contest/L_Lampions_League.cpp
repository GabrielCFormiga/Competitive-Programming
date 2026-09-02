/**
* @file L_Lampions_League.cpp
* @author GabrielCampelo
* Created on 2026-08-24 at 14:50:08
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
    cin >> n;
    
    if (n % 4 == 1 || n % 4 == 2) {
        cout << "IMPAR" << endl;
    } else {
        cout << "PAR" << endl;
    }

    return 0;
}