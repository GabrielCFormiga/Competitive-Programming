/**
* @file Closest_to_the_right.cpp
* https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/C
*
* Created on 2024-10-14 at 09:32:17
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

#define MAX_N 1000000

int n;
int ar[MAX_N];

int busca(int x, int l, int r, int mn) {
    if (l > r) return mn + 1;
    if (l == r && ar[l] >= x) return l + 1;

    int m = (l + r) / 2;
    if (ar[m] < x) return busca(x, m + 1, r, mn);
    else return busca(x, l, m - 1, m);
}

int main() { _
    int k, x;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> ar[i];
    
    while (k--) {
        cin >> x;
        cout << busca(x, 0, n - 1, n) << endl;
    }

    return 0;
}