/**
* @file Children_Holiday.cpp
* https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/D
*
* Created on 2024-11-13 at 01:40:55
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

int m, n;
vector<tuple<int, int, int>> vec;

int f(int x) {
    int res = 0;
    int t, z, y;

    for (const auto& tuple : vec) {
        t = get<0>(tuple);
        z = get<1>(tuple);
        y = get<2>(tuple);

        int bloco = t * z + y;
        int qtd_blocos = x / bloco;
        
        int sobra;
        int tempo_sobra = x - qtd_blocos * bloco;
        if (tempo_sobra >= bloco - y) sobra = z;
        else sobra = tempo_sobra / t;

        res += qtd_blocos * z + sobra;
    }

    return res;
}


int main() { _
    cin >> m >> n;

    int t, // baloes/min 
        z, // baloes antes do descanso
        y; // descanso

    for (int i = 0; i < n; i++) {
        cin >> t >> z >> y;
        vec.pb(make_tuple(t, z, y));
    }

    int l = 0, r = 3000000;
    int mid;

    while (l < r) {
        mid = l + (r - l) / 2;
        
        if (f(mid) >= m) r = mid;
        else l = mid + 1;
    }


    cout << r << endl;
    int total = 0;
    for (int i = 0; i < n; i++) {
        t = get<0>(vec[i]);
        z = get<1>(vec[i]);
        y = get<2>(vec[i]);

        int bloco = t * z + y;
        int qtd_blocos = r / bloco;
        
        int sobra;
        int tempo_sobra = r - qtd_blocos * bloco;
        if (tempo_sobra >= bloco - y) sobra = z;
        else sobra = tempo_sobra / t;

        int ans = qtd_blocos * z + sobra; 

        if (total + ans <= m) {
            cout << ans;
            total += ans;
        } else {
            if (m > total) {
                cout << m - total;
                total = m;
            } else {
                cout << 0;
            }
        }

        if (i == n - 1) cout << endl;
        else cout << ' ';
    }

    return 0;
}