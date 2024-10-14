/**
* @file Binary_Search.cpp
* https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/A
*
* Created on 2024-10-14 at 08:46:17
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

bool binSearch(vector<int> &vec, int x) {
    int l = 0, r = vec.size() - 1, m;

    while (l <= r) {
        m = (l + r) / 2;
        if (x > vec[m]) l = m + 1;
        else if (x < vec[m]) r = m - 1;
        else return true;
    }

    return false;
}

int main() { _
    int n, k, x;
    cin >> n >> k;
    
    vector<int> vec(n);
    for (int i = 0; i < n; i++) cin >> vec[i];

    while (k--) {
        cin >> x;
        // if (binary_search(vec.begin(), vec.end(), x)) cout << "YES" << endl;
        if (binSearch(vec, x)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}