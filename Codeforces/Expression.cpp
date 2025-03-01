/**
* @file Expression.cpp
* https://codeforces.com/problemset/problem/479/A
*
* Created on 2025-03-01 at 02:36:14
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
    int a, b, c;
    cin >> a >> b >> c;

    int mx = 0;

    mx = max(mx, a * b * c);
    mx = max(mx, (a + b) * c);
    mx = max(mx, a * (b + c));
    mx = max(mx, a + b + c);

    cout << mx << endl;
    
    return 0;
}