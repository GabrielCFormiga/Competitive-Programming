/**
* @file A.CPP
*
* Created on 2025-06-10 at 13:50:21
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
    int w, a, b, c;
    cin >> w >> a >> b >> c;
    if (w >= a + b + c) cout << 'S' << endl;
    else cout << 'N' << endl;
    return 0;
}