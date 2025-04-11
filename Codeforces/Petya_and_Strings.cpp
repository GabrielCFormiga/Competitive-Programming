/**
* @file Petya_and_Strings.cpp
* https://codeforces.com/contest/112/problem/A
*
* Created on 2025-04-11 at 00:50:16
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
    string a, b;
    cin >> a >> b;

    for (int i = 0; i < a.size(); i++) {
        if (a[i] >= 'A' && a[i] <= 'Z') a[i] = a[i] - 'A' + 'a';
        if (b[i] >= 'A' && b[i] <= 'Z') b[i] = b[i] - 'A' + 'a';

        if (a[i] > b[i]) {
            cout << 1 << endl;
            return 0;
        } else if (a[i] < b[i]) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << 0 << endl;

    return 0;
}