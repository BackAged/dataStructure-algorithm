#include <bits/stdc++.h>
 
using namespace std;

// as number is huge we can't use array and bottom up approach here
map<int, long long> dp;



/*
  =>sub task is for any given coin find f(n/2) f(n/3) and f(n/4) add them upp to find exchange coins
  => relation of subtask exchange of any coin = max(f(n/2) + f(n/3) + f(n/4) , n)
*/
 
long long f(int n){
    if(n==0) return 0;
    
    if(dp[n]!=0) return dp[n];
    
    dp[n] =max(f(n/2)+f(n/3)+f(n/4), (long long int)n);
    
    return dp[n];
}
 
int main(){    
    int n;
        
    while(scanf("%d",&n)==1) printf("%lld\n",f(n));
    
    return 0;
} 
