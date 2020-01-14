#include<bits/stdc++.h>
using namespace std;
int dp[201][201][201];
int ans = -1;
int lcs(string a1, string a2, int len1, int len2, int counter) {
    if (len1 < 0 || len2 < 0) {
        return counter;
    }
    if (dp[len1][len2][counter] != -1) {
        return dp[len1][len2][counter];
    }
    ans = max(counter, ans);
    int lc = 0;
    if (a1[len1] == a2[len2]) {
        lc = lcs(a1, a2, len1-1, len2-1, counter + 1);
    } else {
        lc = max (lc, max(lcs(a1, a2, len1-1, len2, 0), lcs(a1, a2, len1, len2-1, 0)));
    } 
    
    
    dp[len1][len2][counter] = lc;
    return lc;
}

int main()
 {
	int t;
	cin >> t;
	
	while (t--) {
	    int l1, l2;
	    cin >> l1 >> l2;
	    
	    string a1, a2;
	    cin >> a1 >> a2;
	    
	    memset(dp, -1, sizeof(dp));
	    
	    lcs(a1, a2, l1-1, l2-1, 0);
        cout << ans << endl;
        ans = -1;
	}
	
	return 0;
}

1
17 60
KXCGMTMVVGFQQWSPD
JXZADDUKVLQPKUZJZHWSUTPCAFSYAIBJHAMMEGWBTPQELRNKBLDXGUZGCSEC