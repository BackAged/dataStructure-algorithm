#include<bits/stdc++.h>
using namespace std;

int dp1[100];
int dp2[105];

// memoized version
int solve (int n) {
    if (n < 0)
        return 0;
    else if (n == 0)
        return 1; // we have gone to zero with a valid permutation
    else if (dp1[n] != -1)
        return dp1[n];
    return dp1[n] = solve(n-1) + solve(n-3) + solve(n-5);
}


// tabular version

int main () {
    // Given 3 Number {1, 3, 5} how
    // many ways to calculate a Number N

    // first finding the subproblem or state =>
    // for any 1 + how_many_ways(n-1) + 3 + how_many_ways(n-3) + 5 + how_many_ways(n-5)
    dp2[0] = 1;
    int arr[3] = {1, 3, 5};

    for (int i = 1; i <= 50; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr[j] <= i) { // its solving the sub problem from bottom up manner
                                // doing the same thing how_many(n-1) + how_many(n-3) + how_many(n-5)
                dp2[i] = dp2[i] + dp2[i-arr[j]];
            }
        }
    }

    for (int i = 0; i < 50; i++) {
        cout << dp2[i] << " ";
    }
    return 0;
}
