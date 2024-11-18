/**
* @file Big_Sorting.cpp
* https://www.hackerrank.com/challenges/big-sorting/problem
*
* Created on 2024-11-17 at 23:52:11
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

#define MAX_LEN 1000000

int main() { _
    int n;
    cin >> n;

    vector<string> vec(n);
    for (int i = 0; i < n; i++) cin >> vec[i];

    if (n == 1) {
        cout << vec[0] << endl;
        return 0;
    }

    sort(all(vec), [](string &a, string &b) {
        if (a.size() != b.size()) 
            return a.size() < b.size();  
        return a < b;  
    });

    for (int i = 0; i < n; i++) cout << vec[i] << endl;
    
    return 0;
}