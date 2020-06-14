#include<bits/stdc++.h>
using namespace std;


int main () {
    int n;
    cin >> n;

    string a;
    cin >> a;

    int ones = 0, zeores = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == '0') {
            ones++;
        } else {
            zeores++;
        }
    }

    cout << abs(ones-zeores) << endl;


}
