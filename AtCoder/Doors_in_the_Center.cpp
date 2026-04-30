/**
* @file Doors_in_the_Center .cpp
* https://atcoder.jp/contests/abc398/tasks/abc398_a
*
* Created on 2025-03-22 at 09:01:27
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

    if (n % 2 == 0) {
        for (int i = 1; i < n / 2; i++) cout << '-';
        cout << "==";
        for (int i = n / 2 + 2; i <= n; i++) cout << '-';
        cout << endl;
    } else {
        for (int i = 1; i < (n + 1) / 2; i++) cout << '-';
        cout << '=';
        for (int i = (n + 1) / 2 + 1; i <= n; i++) cout << '-';
        cout << endl;
    }
    
    return 0;
}