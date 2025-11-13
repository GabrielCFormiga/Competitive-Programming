/**
* @file c.cpp
*
* Created on 2025-06-10 at 14:08:23
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
    
    int n; cin >> n;


    while(n--){
        int x, y; cin >> x >> y;
    
        if (x >= 0 && x <= 100 && y >= -100 && y <= 0) cout << 'S' << endl;
        else if (x >= 100 && x <= 200 && y >= x-200 && y <= 0) cout << 'S' << endl;
        else if (x >= 0 && x <= 100 && y >= 0 && y <= 100-x) cout << 'S' << endl;
        else if (x <= 0 && x >= -100 && y <= 0 && y >= -100-x) cout << 'S' << endl;
        else if (x >= -200 && x <= -100 && y >= 0 && y <= 200+x) cout << 'S' << endl;
        else if (x <= 0 && x >= -100 && y >= 0 && y <= 100) cout << 'S' << endl;
        else cout << 'N' << endl;
    }

    return 0;
}
