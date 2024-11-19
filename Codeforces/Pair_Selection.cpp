/**
* @file Pair_Selection.cpp
* https://codeforces.com/edu/course/2/lesson/6/4/practice/contest/285069/problem/C
*
* Created on 2024-11-19 at 01:46:29
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
int a[MAX_N];
int b[MAX_N];

bool possible(double x) {
    vector<double> vec(n);
    for (int i = 0; i < n; i++) {
        vec[i] = a[i] - b[i] * x;
    }

    sort(all(vec), greater<double>());

    double sum = 0;
    for (int i = 0; i < k; i++) sum += vec[i];

    return sum >= 0;
} 

int main() { _
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    double l = 0, r = 1e5;
    double m;

    for (int i = 0; i < 50; i++) {
        m = (l + r) / 2;

        if (possible(m)) l = m;
        else r = m;
    }

    cout << fixed << setprecision(10) << l << endl;

    return 0;
}