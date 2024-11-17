/**
* @file March_Rain.cpp
* https://codeforces.com/problemset/gymProblem/101028/I
*
* Created on 2024-11-17 at 17:16:29
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

#define MAX_N 100100

int n, k;
int holes[MAX_N];

bool possible(int x) {
    int strips = 0;
    int bg = -INF;
    for (int i = 0; i < n; i++) {
        if (holes[i] - bg + 1 > x) {
            bg = holes[i];
            strips++;
        }
    }
    return strips <= k;
}

int main() { _
    int tt;
    cin >> tt;
    while (tt--) {
        cin >> n >> k;

        for (int i = 0; i < n; i++) cin >> holes[i];

        int l = 1, r = 1e9;
        int m;
        while (l < r) {
            m = l + (r - l) / 2;

            if (possible(m)) r = m;
            else l = m + 1;
        } 

        cout << l << endl;
    } 
    
    return 0;
}