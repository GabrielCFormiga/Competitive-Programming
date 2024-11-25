/**
* @file Aggressive_cows.cpp
* https://www.spoj.com/problems/AGGRCOW/cstart=50
* eh igual ao "Cows in Stalls" do cf EDU
*
* Created on 2024-11-25 at 00:05:30
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

int n, c;
int ar[MAX_N];

bool possible(int d) {
    int cows = 0;
    int pos = -INF;

    for (int i = 0; i < n; i++) {
        if (ar[i] - pos >= d) {
            cows++;
            pos = ar[i];
        }
    }

    return cows >= c;
}


int main() { _
    int tt;
    cin >> tt;
    while (tt--) {
        cin >> n >> c;
        for (int i = 0; i < n; i++) cin >> ar[i];
        sort(ar, ar + n);

        int l = 1, r = 1e9;
        int m;

        while (l < r) {
            m = l + (r - l + 1) / 2;

            if (possible(m)) l = m;
            else r = m - 1;
        } 
    
        cout << l << endl;
    } 

    return 0;
}