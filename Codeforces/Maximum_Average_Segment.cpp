/**
* @file Maximum_Average_Segment.cpp
* https://codeforces.com/edu/course/2/lesson/6/4/practice/contest/285069/problem/A
*
* Created on 2024-11-18 at 15:23:36
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

int n, d;
double prefix[MAX_N + 1];
pair<double, int> mn[MAX_N + 1]; // {min(p0 ... pi), min_i}
int ar[MAX_N + 1];

pair<int, int> get_range(double x) {
    // atualizar prefix e mn em O(n)
    prefix[1] = ar[1] - x;
    if (ar[1] - x < 0) mn[1] = {prefix[1], 1};
    else mn[1] = {0, 0};

    for (int i = 2; i <= n; i++) {
        prefix[i] = prefix[i - 1] + ar[i] - x;

        if (prefix[i] < mn[i - 1].first) {
            mn[i] = {prefix[i], i};
        } else mn[i] = mn[i - 1];
    } 

    // verificar de r = d até r = n se a media eh possivel
    for (int r = d; r <= n; r++) {
        int k = r - d;
        if (mn[k].first <= prefix[r]) {
            return {mn[k].second + 1, r};
        }
    }

    return {-1, -1};
}

int main() {
    cin >> n >> d;
    
    for (int i = 1; i <= n; i++) cin >> ar[i];

    double l = 0, r = 100;
    double m;

    for (int i = 0; i < 100; i++) {
        m = (l + r) / 2;
        
        pair<int, int> p = get_range(m);

        if (p.first != -1) l = m;
        else r = m;
    }

    pair<int, int> ans = get_range(l);
    cout << ans.first << ' ' << ans.second << endl;
}