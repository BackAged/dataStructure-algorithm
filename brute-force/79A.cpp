#include<bits/stdc++.h>
using namespace std;

int main () {
    int x, y;

    cin >> x >> y;

    int step = 1;

    while (true) {
        if (step == 1) {
            int remaining  = 220;
            if (x >= 2) {
                remaining = 20;
                x -= 2;
            }
            else if (x == 1){
                remaining = 120;
                x--;
            }

            int two = remaining / 10;

            if (two > y) {
                cout << "Hanako" << endl;
                break;
            }
            else {
                y -= two;
            }
            step = 2;
        } else {
            int remaining  = 220;
            if (y >= 22) {
                remaining = 0;
                y -= 22;
                step = 1;
                continue;
            } else if (y >= 12 && x >= 1) {
                y -= 12;
                x--;
                step = 1;
                continue;
            } else if (y >= 2 && x >= 2) {
                y -= 2;
                x -= 2;
                step = 1;
                continue;
            } else {
                cout << "Ciel" << endl;
                break;
            }
            step = 1;
        }


    }


}
