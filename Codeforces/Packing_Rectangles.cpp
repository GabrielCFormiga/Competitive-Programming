/**
* @file Packing_Rectangles.cpp
* https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/A
*
* Created on 2024-10-14 at 17:34:09
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
    a * w <= L
    b * h <= L
    a * b >= n
    
 */
llu w, h, n;

bool good(llu x) {
    return (x / w) * (x / h) >= n;
}

int main() {
    cin >> w >> h >> n;

    llu L;
    llu lo = 1, hi = 1; 

    while (!good(hi)) hi <<= 1;

    llu mid;
    while (lo <= hi) {
        mid = lo + (hi - lo) / 2;

        if (good(mid)) {
            L = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << L << endl;
}
