/**
* @file Points_and_Powers_of_Two.cpp
* https://codeforces.com/problemset/problem/988/D
*
* Created on 2024-10-11 at 05:18:52
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

/* 
    vamos supor que a resposta seja 3
    com a < b < c, assim

    dist(a, b) = 2^k
    dist(b, c) = 2^l
    dist(a, c) = 2^m

    mas, dist(a, c) = dist(a, b) + dist(b, c)
    logo, k = l

    vamos supor que a resposta seja 4
    com a < b < c < d, assim

    Sabemos que,
    dist(a, b) = dist(b, c) = dist(c, d) = 2^k

    chegamos em um absurdo pois
    dits(a, d) != 3 * 2^k 
 */

int main() { _
    int n;
    cin >> n;

    vector<int> pot(30 + 1);
    pot[0] = 1;
    for (int i = 1; i <= 30; i++) {
        pot[i] = 2 * pot[i - 1];
    }


    map<int, int> mp;
    vector<int> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i];
        mp[points[i]] = 1;
    }

    // verifica se a resposta eh 3
    for (int point : points) {
        for (int d : pot) {
            if (mp.find(point + d) != mp.end() && mp.find(point - d) != mp.end()) {
                cout << 3 << endl;
                cout << point << ' ' << point - d << ' ' << point + d << endl;
                return 0;
            }
        }
    }

    // verifica se a resposta eh 2
    for (int point : points) {
        for (int d : pot) {
            if (mp.find(point + d) != mp.end()) {
                cout << 2 << endl;
                cout << point << ' ' << point + d << endl;
                return 0;
            }
        }
    }

    cout << 1 << endl;
    cout << points[0] << endl;

    return 0;
}