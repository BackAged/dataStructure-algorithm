#include<bits/stdc++.h>
using namespace std;


int main () {
    int t;
    cin >> t;

    for (int cse = 1; cse <= t; cse++) {more dp solution
        long long int n;

        cin >> n;

        long long int lower_boundp = floor(sqrt(n));

        long long int upper_boundp = ceil(sqrt(n));

        if (upper_boundp - lower_boundp == 0) {
            lower_boundp = upper_boundp - 1;
        }


        long long int h = upper_boundp * upper_boundp;
        long long int l = lower_boundp * lower_boundp;

        long long int mid_point = (h - ( l + 1)) / 2;

        long long int m = h - mid_point;

        if (m == n) {
            cout <<"Case " << cse << ": " << upper_boundp << " " << upper_boundp << endl;
            continue;
        }

        if (upper_boundp % 2 != 0) {
             if (n > m) {
                cout <<"Case " << cse << ": " <<  upper_boundp - abs(n - m) << " " << upper_boundp << endl;
            } else {
                cout <<"Case " << cse << ": " << upper_boundp <<  " " << upper_boundp - abs(m - n)<<endl;
            }
        } else {
            if (n < m) {
               cout <<"Case " << cse << ": " << upper_boundp - abs(n - m) << " " << upper_boundp << endl;
            } else {
               cout <<"Case " << cse << ": " << upper_boundp <<  " " << upper_boundp - abs(m - n)<<endl;
            }
        }


    }



    return 0;

}
