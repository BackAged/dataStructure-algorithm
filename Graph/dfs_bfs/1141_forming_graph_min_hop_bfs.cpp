/*
    => simple min hop problem
    => for a node number n you find its prime factor and add to it to find new node until
    => the destination node or never



*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

vector<int>graph[N];

// storing prime up to N
int primes[N] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997};



int dist[N];


void bfs(int s, int d) {
    queue<int>q;
    q.push(s);
    dist[s] = 0;

    while (!q.empty()) {
        int f = q.front();
        q.pop();

        for (int i = 0; primes[i] < f; i++) {
            if (f % primes[i] == 0) {
                int to = f + primes[i];
                if (dist[to] == -1 && to <= d) {
                    q.push(to);
                    dist[to] = dist[f] + 1;
                    if (to == d) {
                        return;
                    }
                }

                while (f % primes[i]) {
                    f /= primes[i];
                }
            }
        }

    }
}


int main()
{

    int t, s, d;
    scanf("%d", &t);

    for (int cs = 1; cs <= t; cs++){
        scanf("%d %d", &s, &d);

        memset(dist, -1, sizeof dist);

        bfs(s, d);
        printf("Case %d: %d\n", cs, dist[d]);
    }
    return 0;
}
