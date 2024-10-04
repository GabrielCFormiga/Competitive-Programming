/**
* @file Raising_Bacteria.cpp
* https://codeforces.com/problemset/problem/579/A

* Created on 2024-10-04 at 00:46:20
* @author GabrielCampelo
*/

#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

int main() { _
    int n, cnt = 0;
    cin >> n;

    while (n) {
        cnt++;
        n = n & (n - 1);
    }

    cout << cnt << endl;
    
    return 0;
}