#include <bits/stdc++.h>
using namespace std;

int fac(int x) {
    set<int>s;
    for (int i = 1; i <= sqrt(x)+1; i++) {
        if (x % i == 0) {
            s.insert(i);
            s.insert(x/i);
        }
    }
    return s.size();
}

bool cmp(const pair<int, int>&x, const pair<int,int>&y) {
    if (x.first < y.first) {
        return true;
    } else if (x.first == y.first) {
        return x.second > y.second;
    }
    return false;

}


int main()
{
    int t, n;
    cin >> t;

    /*
        calculating all factorial of numbers 1 - 1000 with
        O( N* (N+1) / 2 ) => N = 100
        )
        sorting => log1000
        for query O(T)
    */

    vector< pair<int, int> > facs;
    facs.push_back(make_pair(1, 1));
    facs.push_back(make_pair(2, 2));

    // making the array with all factorial
    for (int i = 3; i <= 1000; i++) {
        int f = fac(i);
        facs.push_back(make_pair(f, i));
    }

    sort(facs.begin(), facs.end(), cmp);

    for (int cs = 1; cs <= t; cs++) {
        cin >> n;
        cout << "Case " << cs << ": " << facs[n-1].second << endl;
    }

    return 0;
}
