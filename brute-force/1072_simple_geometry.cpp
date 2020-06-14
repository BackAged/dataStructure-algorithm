#include <bits/stdc++.h>
using namespace std;

int main()
{
    /*
        1.any line from center to circles parameter creates an 90angle with the parameter
        2.that makes the perpendicular is r
        3. and R-r the hypotenuse
    */

    const double PI=acos(-1);
    int t;
    cin >> t;

    double R;
    int n;

    for (int cs = 1; cs <= t; cs++) {
        cin >> R >> n;
        double theta = PI / n;
        double anstheta = sin(theta);
        double ans = (R * anstheta) /(1 + anstheta);
         printf("Case %d: %.10lf\n", cs, ans);
    }
    return 0;
}
