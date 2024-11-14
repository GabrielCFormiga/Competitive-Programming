/**
* @file Buy_a_Pen.cpp
* https://atcoder.jp/contests/abc362
*
* Created on 2024-11-13 at 23:59:18
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
    int r, g, b;
    string color;

    cin >> r >> g >> b >> color;

    int ans;

    if (color == "Blue") b = INF;
    else if (color == "Red") r = INF;
    else g = INF;

    ans = min(r, min(g, b));
    
    cout << ans << endl;

    return 0;
}