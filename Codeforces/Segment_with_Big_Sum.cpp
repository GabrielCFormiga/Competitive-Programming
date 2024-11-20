/**
* @file Segment_with_Big_Sum.cpp
* https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/B
*
* Created on 2024-11-20 at 00:10:02
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
    int n;
    ll s;
    cin >> n >> s;

    vector<int> vec(n);
    for (int i = 0; i < n; i++) cin >> vec[i];

    int l = 0, r = 0;
    int ans = INF; 
    ll sum = 0;

    while (r < n) {
        sum += vec[r];

        while (sum - vec[l] >= s) {
            sum -= vec[l];
            l++;
        }

        if (sum >= s) ans = min(ans, r - l + 1);
        r++;
    }

    cout << (ans == INF ? -1 : ans) << endl;

    return 0;
}