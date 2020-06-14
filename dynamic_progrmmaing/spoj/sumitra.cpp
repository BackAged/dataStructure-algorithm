#include <bits/stdc++.h>
using namespace std;

int dp[105][105];



int main()
{
    int n, r, a;
    cin >> n;


    while (n--) {
        cin >> r;



        for (int i = 0; i < 105; i++) {
            memset(dp[i], 0, sizeof dp[i]);
        }

        for (int i = 1;  i <= r; i++) {
            for (int j = 0; j < i; j++) {
                scanf("%d", &a);
                dp[i-1][j] = a;
            }
        }
        int ans = -1;

        for (int i = 1; i < r; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0) {
                    dp[i][j] += dp[i-1][j];
                    ans = max (ans, dp[i][j]);
                    continue;
                }
                dp[i][j] += max(dp[i-1][j], dp[i-1][j-1]);
                ans = max (ans, dp[i][j]);
            }
        }


        cout << ans << endl;


    }
    return 0;
}
