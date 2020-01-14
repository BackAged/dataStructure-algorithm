#include <iostream>
#include <vector>

using namespace std;
int visited[100][100];

int lcs2(vector<int> &a, vector<int> &b, int as, int bs) {
  if (as < 0 || bs < 0) {
    return 0;
  }
  if (visited[as][bs] != -1) {
    return visited[as][bs];
  }

  int ans = 0;
  if (a[as] == b[bs]) {
    ans = max(ans, 1 + lcs2(a, b, as-1, bs-1));
  } else {
    ans = max(lcs2(a, b, as-1, bs), lcs2(a, b, as, bs-1));
  }
  
  visited[as][bs] = ans;

  return ans;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }
  fill(visited[0], visited[0] + 100 * 100, -1);
  std::cout << lcs2(a, b, a.size()-1, b.size()-1) << std::endl;
}