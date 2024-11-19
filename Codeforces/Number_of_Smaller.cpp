/**
* @file Number_of_Smaller.cpp
* https://codeforces.com/edu/course/2/lesson/9/1/practice/contest/307092/problem/B
*
* Created on 2024-11-19 at 17:56:30
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
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    
    int j = 0;
    for (int i = 0; i < m; i++) {
        while (j < n && a[j] < b[i]) j++;
        cout << j << (i == m - 1 ? endl : ' ');
    }

    return 0;
}