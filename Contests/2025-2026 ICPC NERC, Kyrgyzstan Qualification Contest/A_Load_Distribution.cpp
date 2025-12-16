/**
* @file A_Load_Distribution.cpp
* @author GabrielCampelo
* Created on 2025-12-16 at 01:20:41
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
    
    int s;
    cin >> s;

    char c;
    cin >> c;

    if (c == 'L') {
        cout << (s + 1) / 2 << ' ';
        cout << (s + 1) / 2 << ' ';
        cout << n - s << endl;
    } else {
        cout << s - 1 << ' ';
        cout << (n - s + 2) / 2 << ' ';
        cout << (n - s + 2) / 2 << endl;
    }

    return 0;
}