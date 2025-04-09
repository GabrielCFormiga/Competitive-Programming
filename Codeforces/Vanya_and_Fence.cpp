/**
* @file Vanya_and_Fence.cpp
* https://codeforces.com/contest/677/problem/A
*
* Created on 2025-04-09 at 16:31:25
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
    int n, h;
    cin >> n >> h;
    
    int sum = 0;
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        sum += (a <= h ? 1 : 2);
    }

    cout << sum << endl;

    return 0;
}