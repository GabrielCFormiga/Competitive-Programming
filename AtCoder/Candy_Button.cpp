/**
* @file Candy_Button.cpp
*
* Created on 2024-11-15 at 13:23:18
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
    int n, c;
    cin >> n >> c;

    vector<int> vec(n);
    for (int i = 0; i < n; i++) cin >> vec[i];

    int cnt = 0;
    int curr = -INF;

    for (int i = 0; i < n; i++) {
        if (vec[i] - curr >= c) {
            curr = vec[i];
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}