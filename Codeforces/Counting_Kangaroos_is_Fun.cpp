/**
* @file Counting_Kangaroos_is_Fun.cpp
* https://codeforces.com/problemset/problem/372/A
*
* Created on 2024-11-17 at 16:26:54
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

#define MAX_N 500100

int n;

int main() { _
    cin >> n;
    
    vector<int> vec(n);
    for (int i = 0; i < n; i++) cin >> vec[i];

    sort(all(vec));

    /* 
        n = 2
        0 1 -> i = 0
        n = 3
        0 1 2 -> i = 0
        n = 4
        0 1 2 3 -> i = 1
        n = 5
        0 1 2 3 4 -> i = 1
        n = 6
        0 1 2 3 4 5 -> i = 2 
     */

    int ans = n;
    int i = n / 2 - 1;
    int j = n - 1;

    while (i >= 0 && j > n / 2 - 1) {
        if (vec[j] >= vec[i] * 2) {
            ans--;
            j--;
        }
        i--;
    }

    cout << ans << endl;

    return 0;
}