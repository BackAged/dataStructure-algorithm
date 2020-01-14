#include <iostream>
#include <string>
using namespace std;

int visited[100][100];
int edit_distance(const string &str1, const string &str2, int str1n, int str2n) {
  if (str1n < 0) {
      return (str2n >= 0) ? str2n + 1: 0;
  }
  if (str2n < 0) {
      return (str1n >= 0) ? str1n + 1: 0;
  }
  if (visited[str1n][str2n] != -1) {
      return visited[str1n][str2n];
  }
  
  int ans = INT32_MAX;
  if (str1[str1n] == str2[str2n]) {
      ans = min (ans, edit_distance(str1, str2, str1n-1, str2n-1));
  } else {
    int insertion = edit_distance(str1, str2, str1n, str2n-1);
    int deletion = edit_distance(str1, str2, str1n-1, str2n);
    int substitution = edit_distance(str1, str2, str1n-1, str2n-1);
    ans = min(ans, 1 + min(substitution, min(insertion,deletion)));
  }
  
  visited[str1n][str2n] = ans;
  return ans;
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  fill(visited[0], visited[0] + 100 * 100, -1);
  std::cout << edit_distance(str1, str2, str1.length()-1, str2.length()-1) << std::endl;
  return 0;
}