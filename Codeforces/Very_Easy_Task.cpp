/**
* @file Very_Easy_Task.cpp
* https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/C
*
* Created on 2024-11-13 at 01:16:11
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

/* 
    4 1 1
    
    t(0) = 0
    t = 0, +1 +0, -> t(1) = 1 
    t = 1, +1 +1, -> t(2) = 3
    t = 2, +1 +1, -> t(3) = 5

    quando 
    (t/x) + (t/y) + 1 >= n
    ans = t0 + t;
    */

int n, x, y;

bool f(int t) {
    return (t/x + t/y + 1 >= n);
}

int main() { _
    cin >> n >> x >> y;
    
    if (x > y) swap(x, y);

    if (n == 1) {
        cout << x << endl;
    } else {
        int t0 = x;

        int l = 1, r = 1e9;
        while (l < r) {
            int m = l + (r - l) / 2;

            if (f(m)) r = m;
            else l = m + 1;
        }

        cout << r + t0 << endl;
    }

    return 0;
}