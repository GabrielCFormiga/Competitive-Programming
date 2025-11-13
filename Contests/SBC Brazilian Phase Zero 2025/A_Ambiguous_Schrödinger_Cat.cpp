/**
* @file a.cpp
*
* Created on 2025-05-24 at 14:00:17
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
    int c, g;
    cin >> c >> g;

    if (c == 1) cout << "vivo e morto" << endl;
    else if (g == 1) cout << "vivo" << endl;
    else cout << "morto" << endl;
    
    return 0;
}