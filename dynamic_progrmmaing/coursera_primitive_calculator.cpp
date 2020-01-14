#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int choice[1000000];
int visited[1000000];


int optimal_sequence(int n) {
  visited[0] = 0;
  visited[1] = 0; 
  
  for (int i = 2; i <= n; i++) {
      int ans = INT32_MAX;

      int t1 = 1 + visited[i - 1];
      if (t1 < ans) {
        ans = t1;
        choice[i] = i - 1;
      }
      if (i % 2 == 0) {
          int t2 = 1 + visited[i/2];
          if (t2 < ans) {
            ans = t2;
            choice[i] = i / 2;
          }
      }
      if (i % 3 == 0) {
          int t3 = 1 + visited[i/3];
          if (t3 < ans) {
            ans = t3;
            choice[i] = i / 3;
          }
      }
      visited[i] = min(ans, visited[i]);
  }
  return visited[n];
}

void printOptimalSolution(int n) {
  if (n == 1) {
    cout << 1 << " ";
    return;
  }
  printOptimalSolution(choice[n]);
  cout  << n << " ";
}

int main() {
  int n;
  cin >> n;
  fill_n(visited, 1000005, INT32_MAX);
  int sequence = optimal_sequence(n);
  cout << sequence << endl;
  printOptimalSolution(n);
}