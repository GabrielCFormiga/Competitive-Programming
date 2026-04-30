/**
* @file Be Together.cpp
*
* Created on 2025-11-12 at 13:22:43
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
    
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    int ans = INF;

    for (int x = -100; x <= 100; x++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += (vec[j] - x) * (vec[j] - x);
        }
        ans = min(ans, sum);
    }

    cout << ans << endl;

    return 0;
}