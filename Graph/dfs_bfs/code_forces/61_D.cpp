#include <bits/stdc++.h>
using namespace std;

/*
// ***** there is a unique path between two cities ******
// there is no path relaxation here
// so every edge is visited twice you think level by level
//              /\
//             /\
//            / 
// from the graph it goes down to bottom of left, then goes up on level up, and then one level up
// then on level right down, then up again and so on. every edge is visited twice until the last path if 
// you do naive traversal
// then we should traverse the farthest path once and the rest twice, that would give us the min traverse

*/
long long int max_path = INT_MIN;
vector< pair<int,int> >graph[100005];
int visited[100005];


void dfs(int source, long long int d) {
    visited[source] = 1;
    int s = graph[source].size();
    
    max_path = max(max_path, d);
    
    for (int i = 0; i < s; i++) {
        int to = graph[source][i].first;
        int w = graph[source][i].second;
        
        if (!visited[to]) {
            dfs(to, d + w);
        }
    }

}


int main()
{
    int n, u, v, w;
    cin >> n;
    
    long long int min_distance = 0;
    for (int i = 0; i < n-1; i++) {
        cin >> u >> v >> w;
        
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
        
        min_distance += (2 * w); // taking all distance twice as it gets visited twice
    }
    
    // find the maximum path distance and visit that once so minus it from the total min_distance
    dfs(1, 0);
    
    cout << (min_distance - max_path) << endl;
    
    return 0;
}
