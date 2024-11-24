/**
* @file The_Legend_of_Freya_the_Frog.cpp
* https://codeforces.com/contest/2009/problem/C
*
* Created on 2024-11-24 at 03:19:45
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

const ll INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
    ll tt;
    cin >> tt;
    while (tt--) {
        ll x, y, k;
        cin >> x >> y >> k;
        
        ll mov_x, mov_y;
        
        if (x % k == 0) mov_x = x / k;
        else mov_x = x / k + 1;

        if (y % k == 0) mov_y = y / k;
        else mov_y = y / k + 1;

        if (mov_x == mov_y) cout << 2 * mov_x << endl;
        else if (mov_y > mov_x) cout << 2 * mov_y << endl;
        else cout << 2 * mov_x - 1 << endl;
    } 
    
    return 0;
}