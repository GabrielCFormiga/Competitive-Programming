/**
* @file  Madoka_and_Math_Dad.cpp
* https://codeforces.com/contest/1647/problem/A
*
* Created on 2024-11-20 at 00:57:59
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
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;

        int x;
        if (n % 3 == 0) {
            x = 2 * n / 3;
            x = x / 2;
            while (x--) cout << 2 << 1;
            cout << endl; 
        } else if ((2 * n + 1) % 3 == 0) {
            int x = (2 * n + 1) / 3;
            x = (x - 1) / 2;
            while (x--) cout << 1 << 2;
            cout << 1 << endl;
        } else {
            int x = (2 * n - 1) / 3;
            x = (x - 1) / 2;
            while (x--) cout << 2 << 1;
            cout << 2 << endl;
        }
    } 
    
    return 0;
}