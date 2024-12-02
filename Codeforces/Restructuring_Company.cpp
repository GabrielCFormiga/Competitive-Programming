/**
* @file Restructuring_Company.cpp
* https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/C
*
* Created on 2024-12-01 at 22:53:15
* @author GabrielCampelo
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

#define MAX_N 200100

int n, q;
int p[MAX_N];
int proxm[MAX_N];
int r[MAX_N];

int get(int v) {
    return p[v] = (p[v] == v ? v : get(p[v]));
}

void unionn(int u, int v) {
    u = get(u);
    v = get(v);

    if (u == v) return;

    if (r[u] == r[v]) r[u]++;

    if (r[u] > r[v]) p[v] = u;
    else p[u] = v;
} 

// O(q(logn + α(n)))
int main() { _
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        p[i] = i;
        proxm[i] = i + 1;
    }

    int type, x, y;

    while (q--) {
        cin >> type >> x >> y;

        if (type == 1) {
            unionn(x, y);
        } else if (type == 2) {
            int curr = x;

            while (proxm[curr] <= y) {
                unionn(curr, proxm[curr]);
                int aux = proxm[curr];
                proxm[curr] = y + 1;
                curr = aux;
            }
        } else {    
            if (get(x) == get(y)) cout << "YES" << endl;
            else cout << "NO" << endl;
        }  
    }
    
    return 0;
}