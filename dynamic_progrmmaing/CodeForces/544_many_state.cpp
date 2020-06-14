/*
    => Here, there is three option for a tree
                ->cut to left
                ->cut to right
                ->not cut it at all
    =>subtasks are f(cut->toleft), f(cut->toright), f(nocut)
    => relationship between subtasks -> max( f(cut->toleft)if possible, f(cut->toright)if possible, f(nocut) )
*/

#include <bits/stdc++.h>
using namespace std;

int n;
const int MAXN = 1e5 + 10;

int x[MAXN];
int h[MAXN];
int dp[MAXN][4]; // second array is to save the max cut tree by cutting left right or no cut

/*
int cut_tree(int tree_x, int state_x) {
    if (tree_x >= n) {
        return 0;
    }

    if (dp[tree_x][state_x] != -1)
        return dp[tree_x][state_x];

    int tooksofar = (state_x <= 1) ? x[tree_x] : x[tree_x] + h[tree_x];

    dp[tree_x][state_x] = cut_tree(tree_x + 1, 0); // without cutting tree

    if (tooksofar < x[tree_x + 1] - h[tree_x + 1])  // if possible to cut left
        dp[tree_x][state_x] = max(dp[tree_x][state_x], 1 + cut_tree(tree_x+1, 1));

    if (tree_x + 2 < n && x[tree_x+1] + h[tree_x + 1] < x[tree_x + 2])   // if possible to cut right
        dp[tree_x][state_x] = max(dp[tree_x][state_x], 1 + cut_tree(tree_x+1, 2));

    if (tree_x + 2 >= n)  // when on the last position
        dp[tree_x][state_x] = max(dp[tree_x][state_x], 1 + cut_tree(tree_x + 1, 2));

    return dp[tree_x][state_x];

}

*/


int main()
{
    cin >> n; 
    int a, b;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        x[i] = a;
        h[i] = b;
    }
    for (int i = 0; i < MAXN; i++) {
        dp[i][0] = -1;
        dp[i][1] = -1;
        dp[i][2] = -1;
    }
    
    
    //bottom up approach
    dp[0][0] = 0;
    dp[0][1] = 1; // cutting first one to the left
    if(x[0]+h[0] < x[1])
        dp[0][2]=1;
    
    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i-1][0], max(dp[i-1][1], dp[i-1][2]) );  // ith tree not cutted at all
        
        
        if (x[i] - h[i] > x[i-1])  // ith tree cutted to left
            dp[i][1] = max(dp[i][1], max(dp[i-1][1], dp[i-1][0])+1); // max of f(left), f(0)
                
        if (x[i] - h[i] > x[i-1] + h[i-1]) // ith tree cutted to left for i-1th cutted right
            dp[i][1] = max(dp[i][1], dp[i-1][2]+1 );
        
        
        if (i + 1 < n &&  x[i] + h[i] < x[i+1]) { 
            dp[i][2] = max(dp[i-1][0], max(dp[i-1][1], dp[i-1][2]) ) + 1; // right can be from any state
        }
        if (i == n-1)
            dp[i][2] = max(dp[i-1][0], max(dp[i-1][1], dp[i-1][2]) ) + 1;
    }
    
    
    //int x = cut_tree(0, 0),  y = cut_tree(0, 1), z = cut_tree(0,2);
    int ans = max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]) );
    cout << ans  << endl;

    return 0;
}
