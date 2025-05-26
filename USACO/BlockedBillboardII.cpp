#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

struct Rect {
    int x1, y1, x2, y2;
    int area(){
        return (y2 - y1) * (x2 - x1);
    }
};

int xOverlap; 
int yOverlap; 
int intersect(Rect p, Rect q){
    xOverlap = max(0, min(p.x2, q.x2) - max(p.x1, q.x1));
	yOverlap = max(0, min(p.y2, q.y2) - max(p.y1, q.y1));
	return xOverlap * yOverlap;
}

int main(){
    freopen("billboard.in", "r", stdin);
	freopen("billboard.out", "w", stdout);

    // cover a with b
    Rect a, b;
    cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
	cin >> b.x1 >> b.y1 >> b.x2 >> b.y2; 
    
    if(intersect(a, b) == a.area()){
        cout << 0 << endl;
    } else if(((a.x2 - a.x1) == xOverlap)){
        if(b.y2 < a.y2 && b.y1 > a.y1){
            cout << a.area();
        } else {
            cout << a.area() - intersect(a, b) << endl;
        }
    } else if(((a.y2 - a.y1) == yOverlap)){
         if(b.x2 < a.x2 && b.x1 > a.x1){
            cout << a.area();
        } else {
            cout << a.area() - intersect(a, b) << endl;
        }
    } else {
        cout << a.area() << endl;
    } 
   
    return 0;
}

