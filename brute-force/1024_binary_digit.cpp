#include<bits/stdc++.h>
using namespace std;

#include<iostream>

using namespace std;



// this function returns next higher number with same number of set bits as x.
long long int snoob(long long int x)
{

  long long int rightOne;
  long long int nextHigherOneBit;
  long long int rightOnesPattern;

  long long int next = 0;

  if(x)
  {

    // right most set bit
    rightOne = x & -(signed)x;

    // reset the pattern and set next higher bit
    // left part of x will be here
    nextHigherOneBit = x + rightOne;

    // nextHigherOneBit is now part [D] of the above explanation.

    // isolate the pattern
    rightOnesPattern = x ^ nextHigherOneBit;

    // right adjust pattern
    rightOnesPattern = (rightOnesPattern)/rightOne;

    // correction factor
    rightOnesPattern >>= 2;

    // rightOnesPattern is now part [A] of the above explanation.

    // integrate new pattern (Add [D] and [A])
    next = nextHigherOneBit | rightOnesPattern;
  }

  return next;
}

int main () {
    int t;
    cin >> t;
    for (int cse = 1; cse <= t; cse++) {
        long long int n;
        cin >> n;

        cout << "Case " << cse << ": " << snoob(n) << endl;

    }


    return 0;
}
