/**
* @file War.cpp
* https://vjudge.net/problem/UVA-10158
*
* Created on 2025-03-24 at 00:36:53
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

#define MAX_N 20100

int n;
int p[MAX_N];
int r[MAX_N];

int get(int x) {
    return (p[x] == x ? x : p[x] = get(p[x]));
}

void unionn(int x, int y) {
    x = get(x);
    y = get(y);

    if (x == y) return;

    if (r[x] == r[y]) r[x]++;

    if (r[x] > r[y]) p[y] = x;
    else p[x] = y;
}

int enemies_id(int x) {
    return x + n;
}

bool areFriends(int x, int y) {
    // friends
    if (get(x) == get(y)) return true;

    // common enemy
    if (get(enemies_id(x)) == get(enemies_id(y))) return true;
    
    return false;
}

bool areEnemies(int x, int y) {
    // enemies
    if (get(x) == get(enemies_id(y))) return true;
    if (get(y) == get(enemies_id(x))) return true;
    return false;
}


int main() { _
    cin >> n;

    for (int i = 0; i < MAX_N; i++) p[i] = i;
    
    int c, x, y;

    // int i = 1;
    while (cin >> c >> x >> y && c != 0) {
        // cout << "op = " << i++ << " => ";
        // cout << "c = " << c << " x = " << x << " y = " << y << endl;


        if (c == 1) {
            // setFriends
            if (areEnemies(x, y)) cout << -1 << endl;
            else {
                unionn(x, y);
                unionn(enemies_id(x), enemies_id(y));
            }

        } else if (c == 2) {
            // setEnemies
            if (areFriends(x, y)) cout << -1 << endl;
            else {
                unionn(x, enemies_id(y));
                unionn(y, enemies_id(x));
            };

        } else if (c == 3) {
            // areFriends
            cout << areFriends(x, y) << endl;
        } else {
            // areEnemies
            cout << areEnemies(x, y) << endl;
        }
    }
    
    return 0;
}