#include<bits/stdc++.h>
using namespace std;

/*
    ProblemLink => https://practice.geeksforgeeks.org/problems/longest-common-subsequence/0
    
    for a certain index i in both string
    1. if ith character of both string is same then we add 1 to answer and forward the both string position to i + 1
    2. if ith character of both string is not same then we take the answer which is max of these
        1. either we forward string a without adding anything to answer
        2. or we forward string b without adding anything to answer
*/
int visited[101][101];

int longestCommonSubSequence(string s1, string s2, int s1N, int s2N) {
    if (s1N < 0 || s2N < 0) {
        return 0;
    }
    
    if (visited[s1N][s2N] != -1) {
        return visited[s1N][s2N];
    }

    if (s1[s1N] == s2[s2N]) {
        return 1 + longestCommonSubSequence(s1, s2, s1N - 1, s2N -1);
    }
    
    visited[s1N][s2N] = max( longestCommonSubSequence(s1, s2, s1N-1, s2N), longestCommonSubSequence(s1, s2, s1N, s2N-1));
    return visited[s1N][s2N];
}

void clearVisited(int s1N, int s2N) {
    for (int i = 0; i < s1N; i++) {
        for (int j = 0; j < s2N; j++) {
            visited[i][j] = -1;
        }
    }
}

int main() {
	int t;
	cin >> t;
	
	while (t--) {
	    int an, bn;
	    cin >> an;
	    cin >> bn;

	    string a, b;
	    cin >> a;
	    cin >> b;

	    clearVisited(an, bn);
	    cout << longestCommonSubSequence(a, b, an-1, bn-1) << endl;
	}
	
	return 0;
}
