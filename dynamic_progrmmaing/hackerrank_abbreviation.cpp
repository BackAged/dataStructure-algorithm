#include <bits/stdc++.h>

using namespace std;

// int lcs(string a, string b, int an, int bn) {
//     bool dp[an+1][bn+1];
//     int count=0;
//     for(int k=1;k<=an;k++){
//         int i=k-1;
//         if(a[i]>=65&&a[i]<=90||count==1){
//             count=1;
//             dp[k][0]=0;
//         }else dp[k][0]=1; 
//     }

//     for(int j=0;j<=bn;j++){
//         if(j==0)
//             dp[0][j]=1;
//         else dp[0][j]=0;
//     }

//     for (int i = 1; i <= an; i++) {
//         for (int j = 1; j <= bn; j++) {
//             if (isupper(a[i-1]) && a[i-1] != b[j-1]) {
//                 dp[i][j] = false;
//             } if (a[i-1] == b[j-1]) {
//                 dp[i][j] = dp[i-1][j-1];
//             }   else if (a[i-1] == tolower(b[j-1])) {
//                 dp[i][j] = dp[i-1][j-1] || dp[i-1][j] ;
//             } else {
//                 dp[i][j] = dp[i-1][j];
//             }
//         }
//     }
//     return dp[an][bn];
// }

int visited[1001][1001];
bool lcsRecursive(string a, string b, int an, int bn) {
    if (an < 0 && bn < 0) return true;
    if (an < 0 && bn >= 0) return false;
    if (visited[an][bn] != -1) {
        return visited[an][bn] == 1 ? true : false;
    }

    bool ans;
    if (a[an] == b[bn]) {
        ans = lcsRecursive(a, b, an-1, bn-1);
    } else if (a[an] == char(tolower(b[bn]))){
        ans = lcsRecursive(a, b, an-1, bn-1) || lcsRecursive(a, b, an-1, bn);
    } else if (isupper(a[an])) {
        ans = false;   
    } else {
        ans = lcsRecursive(a, b, an-1, bn);
    }
    visited[an][bn] = ans == true ? 1 : 0;
    return ans;
}

void fill_visited_null() {
    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 1001; j++) {
            visited[i][j] = -1;
        }
    }
}
void print_visited(int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << visited[i][j];
        }
        cout << endl;
    }
}
// Complete the abbreviation function below.
string abbreviation(string a, string b) {
    fill_visited_null();
    int lc = lcsRecursive(a, b, a.size()-1, b.size()-1);
    //print_visited(a.size(), b.size());
    if (lc) return "YES";
    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = abbreviation(a, b);

        cout << result << "\n";
    }

    fout.close();

    return 0;
}
