#include <bits/stdc++.h>
using namespace std;

/*

=> The main point is there can be no multiple punctuation
=> I search through the string if its not a alphabet, then i while loop untill i find another alphabet
=> If i find a puncuation i out put that with a following space
=> If i haven't find that i output only a space

*/

int main()
{
    string a;
    getline (cin, a);

    int i = 0;
    int s = a.size();

    string temp = " ";

    while (i < s) {
        temp = " ";
        if (a[i] != ' ' && a[i] != '.' && a[i] != ',' && a[i] != '?' && a[i] != '!') {
            cout << a[i];
        } else {
            while (a[i] == ' ' ||  a[i] == '.' || a[i] == ',' || a[i] == '?' || a[i] == '!') {
                if (a[i] == '.' || a[i] == ',' || a[i] == '?' || a[i] == '!') {
                    temp = a[i];
                }
                i++;
            }
            if (temp != " ") {
                cout << temp << " ";
            }
            else {
                cout << " ";
            }
            i--;
        }
        i++;
    }

    cout << endl;
    return 0;
}
