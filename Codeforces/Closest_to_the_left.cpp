/**
* @file Closest_to_the_left.cpp
* https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/B
*
* Created on 2024-10-14 at 09:01:07
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

void exibe(vector<int> &vec, int l, int r, int mx) {
    cout << "mx = " << mx << endl;
    for (int i = l; i <= r; i++) cout << vec[i] << " ";
    cout << endl << endl;
}

int busca(vector<int> &vec, int x, int l, int r, int mx) {
    // exibe(vec, l, r, mx);
    if (l > r) return mx + 1;   
    if (l == r && vec[l] <= x) return l + 1;

    int m = (l + r) / 2;
    if (vec[m] > x) return busca(vec, x, l, m - 1, mx);
    else {
        return busca(vec, x, m + 1, r, m);
    }
}

int main() { _
    int n, k, x;
    cin >> n >> k;
    
    vector<int> vec(n);
    for (int i = 0; i < n; i++) cin >> vec[i];

    while (k--) {
        cin >> x;
        cout << busca(vec, x, 0, vec.size() - 1, -1) << endl;
    }

    return 0;
}