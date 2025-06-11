/**
* @file g.cpp
*
* Created on 2025-06-10 at 13:52:01
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
    
    string x; cin >> x;

    if (x[3] == 'S' && x[4] == 'P') cout << "S" << endl;
    else if (x[3] == 'S' && x[4] == '?') cout << "T" << endl;
    else if (x[3] == '?' && x[4] == 'P') cout << "T" << endl;
    else cout << "N" << endl;

    return 0;
}