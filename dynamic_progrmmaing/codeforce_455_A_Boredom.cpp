#include<bits/stdc++.h>
using namespace std;

/*
    ProblemLink => http://lightoj.com/volume_showproblem.php?problem=1011
    
    as it's required to find the highest priority index marriage combination maintaining **MONOGAMY**
    * so in the highest priority index marriage combination you have to take unique column value, (no two values in same column)
    * so if we keep going row by row, for each column we check if it's already married if not then take it and forward
    * another important observation is =>=> that to memoize the previous computation 
        you have to store the whole [column state which of it's taken and which is not] and row
    * to store the [column state] efficiently we use **BIT MASKING** we use number bit to store state of column (1 => is married or false)
*/
int visited[100000];
int alexSequence[100000];


int getHighestPoint(int n) {
    if (n < 0) {
        return 0;
    }

    if (visited[n]) {
        return 0;
    }
    
    int skipping = getHighestPoint(n-1);

    if (n-1 >= 1) {
        visited[n-1] = 1;
    }
    visited[n+1] = 1;

    int taking = getHighestPoint(n-2) + alexSequence[n];

    if (n-1 >= 1) {
        visited[n-1] = 0;
    }
    visited[n+1] = 0;

    return max(skipping, taking);
}

void takeinput(int n) {
    for (int i = 0; i < n; i++) {
        cin >> alexSequence[i];
    }
}


int main() {
    int n;
    cin >> n;

    takeinput(n);
    cout << getHighestPoint(n-1) << endl;
	return 0;
}