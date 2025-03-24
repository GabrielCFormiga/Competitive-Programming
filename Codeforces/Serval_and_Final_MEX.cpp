/**
* @file Serval_and_Final_MEX.cpp
*
* Created on 2025-03-22 at 15:42:38
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
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;

        int mid = n / 2;
        vector<int> vec(n + 1);

        for (int i = 1; i <= n; i++) cin >> vec[i];

        bool zero_in_left = false;
        for (int i = 1; i <= mid; i++) {
            if (vec[i] == 0) {
                zero_in_left = true;
                break;
            }
        }

        bool zero_in_right = false;
        for (int i = mid + 1; i <= n; i++) {
            if (vec[i] == 0) {
                zero_in_right = true;
                break;
            }
        }

        if (zero_in_left && zero_in_right) {
            cout << 3 << endl;
            cout << 1 << ' ' << mid << endl;
            cout << 2 << ' ' << n - mid + 1 << endl;
            cout << 1 << ' ' << 2 << endl;
        } else if (zero_in_left) {
            cout << 2 << endl;
            cout << 1 << ' ' << mid << endl;
            cout << 1 << ' ' << n - mid + 1 << endl;
        } else if (zero_in_right) {
            cout << 2 << endl;
            cout << mid + 1 << ' ' << n << endl;
            cout << 1 << ' ' << mid + 1 << endl;
        } else {
            cout << 1 << endl;
            cout << 1 << ' ' << n << endl;
        }

    } 
    
    return 0;
}