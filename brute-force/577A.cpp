#include<bits/stdc++.h>
using namespace std;

int factorial(int x, int n) {
    int counter = 0;
    for (int i = 1; i <=  sqrt(x); i++) {
        if (x % i == 0 && x / i <= n) {
            if (x / i == i) {
                counter++;
            } else {
                counter += 2;
            }
        }
    }
    return counter;
}



int main () {
    int n, x;
    cin >> n >> x;

    cout << factorial(x, n) << endl;

    return 0;
}
