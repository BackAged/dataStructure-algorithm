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
int visited[17][1 << 16];
int marriagePriorityIndex[17][17];

bool isWomanMarriedInCurrentCombination(int woman, int womenMarriageStateMask) {
    return womenMarriageStateMask & (1 << woman);
}

int getThisWoamnMarried(int woman, int womenMarriageStateMask) {
    return womenMarriageStateMask | (1 << woman);
}

void clearVisited() {
    memset(visited, -1, sizeof(visited));
}

int getHighesttPriorityMarriage(int r, int womanMarriageStateMask, int n) {
    if (r >= n) {
        return 0;
    }

    if (visited[r][womanMarriageStateMask] != -1) {
        return visited[r][womanMarriageStateMask];
    }

    int highestPriority = -1;
    for (int i = 0; i < n; i++) {
        if (!isWomanMarriedInCurrentCombination(i, womanMarriageStateMask)) {
            int womanNewMarriageStateMask = getThisWoamnMarried(i, womanMarriageStateMask);
            highestPriority = max(highestPriority, marriagePriorityIndex[r][i] + getHighesttPriorityMarriage(r + 1, womanNewMarriageStateMask, n) );
        }
    }

    visited[r][womanMarriageStateMask] = max(visited[r][womanMarriageStateMask], highestPriority);
    return highestPriority;
}

void takePriority(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> marriagePriorityIndex[i][j];
        }
    }
}


int main() {
	int t;
	cin >> t;
    int cse = t;
	
	while (t--) {
        int n;
        cin >> n;

        clearVisited();

        takePriority(n);

        cout << "Case " << cse - t << ": " << getHighesttPriorityMarriage(0, 0, n) << endl;
	}
	
	return 0;
}