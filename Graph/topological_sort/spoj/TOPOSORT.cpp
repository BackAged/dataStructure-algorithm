#include <bits/stdc++.h>
using namespace std;

const int N = 1e4+10;
const int M = 1e6+5;
int n, m;


vector<int>graph[N];
int arr[N];
set<int>minHeap; // as set is sorted ascending order
vector<int>tasks;

int main()
{
    scanf("%d %d", &n, &m);
    
    int a, b;

    // talking input
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        arr[b]++;
    }
    
    // first talking all the root of dijsoint connected set of components
    for (int i = 1; i <= n; i++) 
        if (arr[i] == 0)
            minHeap.insert(i);
    
    // as set is ordered the lowest node is always taken
    while (!minHeap.empty()) {
        int s = *minHeap.begin();
        minHeap.erase(minHeap.begin());
        
        tasks.push_back(s);
        
        for (int i = 0; i < graph[s].size(); i++) {
            int to = graph[s][i];
            arr[to]--;
            if (arr[to] == 0) {
                minHeap.insert(to);
            }
        }
            
    }
    
    
    if (tasks.size() >= n) {
        for (int i = 0; i < n-1; i++) {
            cout << tasks[i] << " ";
        }
        cout << tasks[n-1] << endl;
    } else {
        cout << "Sandro fails." << endl;
    }
    
    
    
    
    
    return 0;
}
