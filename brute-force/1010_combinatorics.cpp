#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, m, first, second, temp;
    
    scanf("%d", &t);
    
    int answer;
    
    /*
      the main idea was to place a knight on one cell and and leave one cell
      in the next row do the opposite of before row
      what that means finally placing knight diagonally from each other
      and
      the exceptions is when its two whether row or column,
      we can find that we can place 4knight together and 2column space then, so we have to find how many 4's knight we can
      place, then if the remaingin space is 1 col we can place another 2knight together in two row,
      or if its more we can place another 4 knight
    */
    
    for (int cse = 1; cse <= t; cse++) {
        scanf("%d %d", &n, &m);
        
        if(m == 1) {
            answer = n;
        }
		else if(n == 1){
		    answer = m;
		}
    
    // this is the part i struggled with,
    // i broke the cases into different different case
    // without making a universal pattern
   
   

		else if (n == 2) {
		    answer = (m / 4) * 4;
		    if (m % 4 == 1) {
		        answer += 2;
		    } else if( m % 4 > 1) {
		        answer += 4;
		    }
		}
		else if (m == 2) {
		    answer = (n / 4) * 4;
		    if (n % 4 == 1) {
		        answer += 2;
		    } else if(n % 4 > 1) {
		        answer += 4;
		    }
		}
        else {
            if (m % 2 == 0) {
                first = m / 2;
                second = first;
            } else {
                first = m / 2 + 1;
                second = first - 1;
            }
        
            if (n % 2 == 0) {
                temp = n / 2;
                answer = first * temp + second * temp;
            } else {
                temp = n / 2 + 1;
                answer = first * temp + second * (temp - 1);
            }
        }
        printf("Case %d: %d\n", cse, answer);
    }
        
    return 0;
}
