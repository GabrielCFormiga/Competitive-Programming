/**
* @file Fast_Search.cpp
* https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/D
*
* Created on 2024-10-14 at 14:30:46
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

int n, k, x, y;
int ar[MAX_N];

int main() { _
    cin >> n;
    for (int i = 0; i < n; i++) cin >> ar[i];
    sort(ar, ar + n);

    cin >> k;
    while (k--) {
        cin >> x >> y;
        if (x > y) swap(x, y);

        int i, j;
        int l = 0, r = n;
        // primeiro elemento >= x
        while (l < r) {
            int m = l + (r - l) / 2;
            if (ar[m] < x) l = m + 1;
            else r = m;
        }
        i = l;

        l = -1, r = n - 1;
        // primero elemento <= y
        while (l < r) {
            int m = l  + (r - l + 1) / 2;
            if (ar[m] > y) r = m - 1;
            else l = m;
        }
        j = l;

        if (i > j) cout << 0;
        else cout << j - i + 1;

        if (k == 0) cout << endl;
        else cout << ' ';
    }

    
    return 0;
}