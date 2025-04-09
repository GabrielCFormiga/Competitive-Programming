/**
* @file Bear_and_Big_Brother.cpp
* https://codeforces.com/contest/791/problem/A
*
* Created on 2025-04-09 at 16:49:07
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
    int a, b;
    cin >> a >> b;

    int cnt = 0;
    while (a <= b) {
        cnt++;
        a *= 3;
        b *= 2;
    }

    cout << cnt << endl;
    
    return 0;
}