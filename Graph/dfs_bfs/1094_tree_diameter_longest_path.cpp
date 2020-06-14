#include <bits/stdc++.h>
using namespace std;

vector < pair<int, int> > graph[30005];

bool vis[30005];
long long max_distance;
int start;


void dfs(int j, long long dis)
{
	int x;
	int w;
	
	if(dis > max_distance) {
		max_distance = dis;
		start = j;
	}
	int s = graph[j].size();
	for (int i = 0; i < s; i++) {
		x = graph[j][i].first;
		w = graph[j][i].second;

		if(vis[x] == 0) {
			vis[x] = 1;
			dfs(x, dis+w);
		}

	}
}



int main()
{

	int x;
	int y;
	int w;
	int t;
	int n;

	scanf("%d", &t);

	for (int cs = 1; cs <= t; cs++) {
		scanf("%d", &n);
		
    	for (int i = 0; i < 30005; i++) {
    	    graph[i].clear();
    	}
		
		for (int i = 0; i < n - 1; i++) {
			cin >> x;
			cin >> y;
			cin >> w;
			graph[x].push_back(make_pair(y, w));
			graph[y].push_back(make_pair(x, w));
		}


		max_distance = INT_MIN; // setting the max
		memset(vis, 0, sizeof(vis)); // clearing visited
		vis[0] = 1;
		dfs(0, 0); // first dfs with 0 as root
		

		max_distance = INT_MIN;
		memset(vis, 0, sizeof(vis));
		vis[start] = 1;
		dfs(start, 0); // second dfs with previous farthest node
		printf("Case %d: %lld\n", cs, max_distance);	
	}

}
