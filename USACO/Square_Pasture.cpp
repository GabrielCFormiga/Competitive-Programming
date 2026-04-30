#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

struct Rect {
    int bl_x, bl_y, tr_x, tr_y;
};

int main(){ _
    freopen("square.in", "r", stdin);
	freopen("square.out", "w", stdout);


    Rect a, b;
    cin >> a.bl_x >> a.bl_y >> a.tr_x >> a.tr_y;
    cin >> b.bl_x >> b.bl_y >> b.tr_x >> b.tr_y;

    int h = max(a.tr_y, b.tr_y) - min(a.bl_y, b.bl_y);
    int l = max(a.tr_x, b.tr_x) - min(a.bl_x, b.bl_x);

    cout << max(h, l) * max(h, l) << endl;

    return 0;
}