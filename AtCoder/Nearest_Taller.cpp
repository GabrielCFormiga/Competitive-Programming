/**
* @file Nearest Taller.cpp
* @author GabrielCampelo
* Created on 2025-11-25 at 00:44:38
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
    vector<int> vec(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> vec[i];
    }
    for (int i = 1; i <= n; i++) {
        int ans = -1;
        for (int j = i - 1; j >= 1; j--) {
            if (vec[j] > vec[i]) {
                ans = j;
                break;
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}