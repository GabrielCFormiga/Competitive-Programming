/**
* @file Ropes.cpp
* https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/B
*
* Created on 2024-11-12 at 21:28:39
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
    int n, k;
    float l = 0, r = 0;

    cin >> n >> k;

    vector<int> ropes(n);    
    
    for (int i = 0; i < n; i++) {
        cin >> ropes[i];
        r = max(r, (float)ropes[i]);
    }

    float m;
    for (int i = 0; i < 60; i++) {
        m = (l + r) / 2;

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += floor(ropes[i] / m);
        }

        if (cnt >= k) l = m;
        else r = m;
    }

    cout << setprecision(20) << l << endl;
    
    return 0;
}