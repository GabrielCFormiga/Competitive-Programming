/**
* @file Police_Recruits.cpp
*
* Created on 2025-04-11 at 03:33:42
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
    cin >> n;

    int cops = 0;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int aux;
        cin >> aux;
        
        if (aux > 0) cops += aux;
        else {
            if (cops > 0) cops--;
            else ans++; 
        }
    }

    cout << ans << endl;
    
    return 0;
}