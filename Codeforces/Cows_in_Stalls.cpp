/**
* @file Cows_in_Stalls.cpp
* https://codeforces.com/edu/course/2/lesson/6/3/practice/contest/285083/problem/C
*
* Created on 2024-11-14 at 16:54:36
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

#define MAX_N 10100

int n, k;
int ar[MAX_N]; // cordenadas

bool possible(int d) {
    int curr = ar[0];
    int cnt = 1;

    for (int i = 1; i < n; i++) {
        if (ar[i] - curr >= d) {
            curr = ar[i];
            cnt++;
        }
    }

    // cout << "d = " << d << " cnt = " << cnt << endl;
    
    return cnt >= k;
}

int main() { _
    cin >> n >> k;
    
    for (int i = 0; i < n; i++) cin >> ar[i];

    int l = 0, r = 1e9;
    int m;

    while (l < r) {
        m = l + (r - l + 1) / 2;

        if (possible(m)) l = m;
        else r = m - 1;
    }

    cout << l << endl;

    return 0;
}