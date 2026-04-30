#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

// O(1) contudo o código da sol2 foi longo e complicado de codar
// com struct é mais fácil
// sol 1

struct Rect {
    int x1, y1, x2, y2;
    int area(){
        return (y2 - y1) * (x2 - x1);
    }
};

int intersect(Rect p, Rect q){
    int xOverlap = max(0, min(p.x2, q.x2) - max(p.x1, q.x1));
	int yOverlap = max(0, min(p.y2, q.y2) - max(p.y1, q.y1));
	return xOverlap * yOverlap;
}

int main(){
    freopen("billboard.in", "r", stdin);
	freopen("billboard.out", "w", stdout);

    Rect a, b, t;
    cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
	cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
	cin >> t.x1 >> t.y1 >> t.x2 >> t.y2; 
    cout << a.area() + b.area() - intersect(a, t) - intersect(b, t) << endl;
}


// sol 2
/*
int main(){ _
    vector<int> b1(4);
    vector<int> b2(4);
    vector<int> t(4);
    int l1 = 0, h1= 0, l2= 0, h2= 0;
    int area;

    cin >> b1[0] >> b1[1] >> b1[2] >> b1[3];
    cin >> b2[0] >> b2[1] >> b2[2] >> b2[3];
    area = (b1[2] - b1[0]) * (b1[3] - b1[1]) + (b2[2] - b2[0]) * (b2[3] - b2[1]);
    cin >> t[0] >> t[1] >> t[2] >> t[3];

    // check b1 ^ t
    // x
    if(t[2] <= b1[0] || t[0] >= b1[2]){
        // b1 ^ t = vazio
    } else {
        if(t[0] <= b1[0]){
            // 1 ou 4
            if(t[2] <= b1[2]){
                l1 = t[2] - b1[0]; 
            } else {
                l1 = b1[2] - b1[0];
            }
        } else {
            // 2 ou 3
            if(t[2] <= b1[2]){
                l1 = t[2] - t[0]; 
            } else {
                l1 = b1[2] - t[0];
            }
        }
    }
    // y 
    if(t[3] <= b1[1] || t[1] >= b1[3]){
        // b1 ^ t = vazio
    } else {
        if(t[1] <= b1[1]){
            // 1 ou 4
            if(t[3] <= b1[3]){
                h1 = t[3] - b1[1]; 
            } else {
                h1 = b1[3] - b1[1];
            }
        } else {
            // 2 ou 3
            if(t[3] <= b1[3]){
                h1 = t[3] - t[1]; 
            } else {
                h1 = b1[3] - t[1];
            }
        }
    }

    // check b2 ^ t
    // x
    if(t[2] <= b2[0] || t[0] >= b2[2]){
        // b2 ^ t = vazio
    } else {
        if(t[0] <= b2[0]){
            // 1 ou 4
            if(t[2] <= b2[2]){
                l2 = t[2] - b2[0]; 
            } else {
                l2 = b2[2] - b2[0];
            }
        } else {
            // 2 ou 3
            if(t[2] <= b2[2]){
                l2 = t[2] - t[0]; 
            } else {
                l2 = b2[2] - t[0];
            }
        }
    }
    // y 
    if(t[3] <= b2[1] || t[1] >= b2[3]){
        // b2 ^ t = vazio
    } else {
        if(t[1] <= b2[1]){
            // 1 ou 4
            if(t[3] <= b2[3]){
                h2 = t[3] - b2[1]; 
            } else {
                h2 = b2[3] - b2[1];
            }
        } else {
            // 2 ou 3
            if(t[3] <= b2[3]){
                h2 = t[3] - t[1]; 
            } else {
                h2 = b2[3] - t[1];
            }
        }
    }
    
    area -= l1*h1 + l2*h2;
    cout << area << endl;

    return 0;
}
*/