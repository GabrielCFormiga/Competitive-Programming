#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

struct Seq {
    int x1, x2;
};


bool overlap(Seq &a, Seq &b){
    return max(0, min(a.x2, b.x2) - max(a.x1, b.x1));
}

int main(){ _
    freopen("paint.in", "r", stdin);
	freopen("paint.out", "w", stdout);
    Seq a, b;
    cin >> a.x1 >> a.x2 >> b.x1 >> b.x2;

    if(overlap(a, b) == 0){
        cout << a.x2 - a.x1 + b.x2 - b.x1 << endl;
    } else {
        cout << max(a.x2, b.x2) - min(a.x1, b.x1) << endl;
    }

    return 0;
}