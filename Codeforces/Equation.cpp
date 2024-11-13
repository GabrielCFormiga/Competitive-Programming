/**
* @file Equation.cpp
* https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/E
*
* Created on 2024-11-13 at 02:34:51
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

const double delta = 1e-6;
double c;

double f(double x) {
    return x * x + sqrt(x);
} 

int main() { _
    cin >> c;

    double l = 0, r = 100000;
    double m;
    while (r - l > delta) {
        m = (r + l) / 2;

        if (f(m) > c) r = m;
        else l = m;
    }

    cout << setprecision(20) << l << endl;

    return 0;
}