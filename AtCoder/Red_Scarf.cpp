/**
* @file Red_Scarf.cpp
* https://atcoder.jp/contests/abc171/tasks/abc171_e
*
* Created on 2024-11-15 at 15:03:35
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
    int n;
    cin >> n;

    vector<int> vec(n);

    int M = 0;
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
        M ^= vec[i];
    }

    for (int i = 0; i < n; i++) {
        cout << (M ^ vec[i]) << (i == n - 1 ? '\n' : ' ');
    }

    return 0;
}