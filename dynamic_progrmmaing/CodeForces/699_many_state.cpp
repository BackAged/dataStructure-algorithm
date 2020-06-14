#include <bits/stdc++.h>
using namespace std;

int dp[105][4];
int arr[105];


int main()
{
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    
    int g, c;
    
    if (arr[0] == 0) {
        g = 0;
        c = 0;
    } else if (arr[0] == 1) {
        g = 0;
        c = 1;
    } else if (arr[0] == 2) {
        g = 1;
        c = 0;
    } else {
        g = 1;
        c = 1;
    }
    
    dp[0][0] = 0; // rest
    dp[0][1] = g; // gym
    dp[0][2] = c; // contest
    
    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i-1][0], max(dp[i-1][1], dp[i-1][2]) ); // taking rest
        if (arr[i] == 0) {
            
        } else if (arr[i] == 1) {
            dp[i][2] = max(dp[i][2], max(dp[i-1][0], dp[i-1][1])+1 ); // taking gym
        } else if (arr[i] == 2) {
            dp[i][1] = max(dp[i][1], max(dp[i-1][0], dp[i-1][2])+1 ); // taking contest
        } else { // gym contest both is open
            dp[i][2] = max(dp[i][2], max(dp[i-1][0], dp[i-1][1])+1 );
            dp[i][1] = max(dp[i][1], max(dp[i-1][0], dp[i-1][2])+1 );
        }
    }
    
    cout << n - max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]) ) << endl;
    
    return 0;
}
 
