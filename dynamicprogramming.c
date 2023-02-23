#include <stdio.h>
#define LEN 4

int collect(int Sum[], int m, int n){
    int i, j, in, ex; // i and j for counter || in and ex for value
    int coinChange[n+1][m];
    for(i=0;i<m;i++)
    coinChange[0][i]=1;
    for(i=1;i<n+1;i++){
        for(j=0;j<m;j++){
        in = (i-Sum[j]>=0)? coinChange[i - Sum[j]][j]:0;
        ex = (j>=1)? coinChange[i][j-1]: 0;
        coinChange[i][j] = in +ex;
        }
    }
    return coinChange[n-1][m-1];
}

int main(){
    int coinSet[LEN] = {1,6,10,25};
    int m = sizeof(coinSet)/sizeof(coinSet[0]);
    int n,i;
    printf("Enter an amount you want to exchange: ");
    scanf("%d", &n);
    printf("Total of coins: %d", collect(coinSet,m,n));
    return 0;
}
