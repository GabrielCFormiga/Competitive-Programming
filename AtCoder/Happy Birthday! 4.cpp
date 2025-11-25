/**
* @file Happy Birthday! 4.cpp
* @author GabrielCampelo
* Created on 2025-11-25 at 00:38:13
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
    int x, y, z;
    cin >> x >> y >> z;
    // x + k = z(y + k) para algum k
    // x + k = zy + zk
    // x - zy = k(z - 1)
    // (x - zy) / (z - 1) = k
    bool possible = true;
    if (x < z * y) possible = false;
    else if ((x - z * y) % (z - 1) != 0) possible = false;
    if (possible) cout << "Yes" << endl;
    else cout << "No" << endl;  
    return 0;
}