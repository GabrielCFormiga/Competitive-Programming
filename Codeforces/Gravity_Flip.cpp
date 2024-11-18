/**
* @file Gravity_Flip.cpp
* https://codeforces.com/problemset/problem/405/A
*
* Created on 2024-11-17 at 23:17:12
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
    for (int i = 0; i < n; i++) cin >> vec[i];

    sort (all(vec));

    for (int i = 0; i < n; i++) {
        cout << vec[i] << (i == n - 1  ? endl : ' ');
    }
    
    return 0;
}