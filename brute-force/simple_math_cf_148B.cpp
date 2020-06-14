#include<bits/stdc++.h>
using namespace std;


int main () {
    double vp, vd, t, f, c;

    cin >> vp >> vd >> t >> f >> c;

    int min_bijou = 0;

    double  pc = vp * t;
    double dc = 0;
    
    if (vp < vd) {
        while (true) {
            double t1 = pc / (vd - vp); // after t second dragon overtakes her
            pc += (t1  * vp);
            
            double dr = pc / vd;
            
            if (pc >= c)        // if she has not reached she needs one bijou
                break;
            min_bijou++;
            
            pc += (dr + f) * vp;
        }
    }
    cout << min_bijou << endl;
}
