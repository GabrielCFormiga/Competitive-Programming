/**
* @file Quick_Sort_raro.cpp
* https://codeforces.com/group/OyefIGO3t4/contest/447260/problem/C
*
* Created on 2024-11-17 at 23:36:46
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
    n = 2
    2 1 -> 1 | 2

    n = 3
    3 1 2 -> 1 | 3 2 -> 1 | 2 | 3

    n = 4
    3 1 2 4 -> 1 | 3 2 4 -> 1 | 2 | 3 | 4

    index do menor na particao tem que ser na metade ou na direita
 */


int main() { _
    int n;
    cin >> n;

    vector<int> vec(n);

    int mn = 1;
    int l = 0, r = n - 1;
    while (r >= 0) {
        int len = r - l + 1;
        // cout << len << endl;
        int pivot = len / 2;
        for (int i = 0; i < n; i++) {
            if (vec[i] == 0) {
                if (pivot == 0) {
                    vec[i] = mn++;
                    break;
                } else {
                    pivot--;
                }
            }
        }
        r--;
        if (pivot > 0) break;
    }
    
    for (int i = 0; i < n; i++) cout << vec[i] << (i == n - 1 ? endl : ' ');

    return 0;
}