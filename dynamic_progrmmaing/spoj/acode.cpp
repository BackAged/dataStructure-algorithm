#include <bits/stdc++.h>
using namespace std;

/*
    => if alwasy take a character and form a combination
    => if two consecutive character form a letter then take that two
    => combination equal = f(s+1) + f(s+2) ---- if the recursion has gone last that means it has found an combination
    => bottom approach would dp[i] = dp[i-1] + if(possible) dp[i-2]
*/


long long dp[5000+10] ;
char arr[5000+10];

long long solve(int pos,int len)
{
    if(pos==len) return 1 ;
    if(arr[pos]=='0') return 0 ;
   
    
    if(dp[pos]) return dp[pos];

    dp[pos] = solve(pos+1,len);
    if(pos+1<len)
    {
        if(arr[pos]=='1') dp[pos] +=solve(pos+2,len);
        else if(arr[pos]=='2'&&arr[pos+1]<='6') dp[pos] +=solve(pos+2,len);
    }

    return dp[pos] ;
}

long long solve(int pos, int len) {
    dp[0] = 1; 
    dp[1] = 1;
    
    
    for (int i = 2; i <= len; i++) {
        if (arr[i-2] == '1' || (arr[i-2] == '2' && arr[i-1] <= '6'))
            dp[i] += dp[i-2];
        if (arr[i-1] != '0')  // if two char one is zero you must have take them together here we add dp[i-2]
            dp[i] += dp[i-1];  // leave the dp[i-1]
                                // even if we take single char as 0 we actually add nothing
    }
    return dp[len];
}


int main()
{
  
    while( scanf("%s",&arr)==1 )
    {
        if(strcmp(arr,"0")==0) break ;
        memset(dp, 0, sizeof dp);
        printf("%lld\n",solve(0,strlen(arr)));
    }
    return 0;
}
