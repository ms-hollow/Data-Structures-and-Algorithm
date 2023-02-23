//Leonen Abbegail Miles
//BSCS-NS-2B

#include <stdio.h>
#define SIZE 4 

void main(){

    int i, m = 0, c;
    int set[SIZE] = {1,6,10,25};
    int arr[15] = {0}; //array para sa stack ng coins or magiging list siya ng coins

    printf("Enter an amount you want to exchange: ");
    scanf("%d", &c);

    for(i=SIZE-1 ;i>=0; i--){  //yung LEN-1 parang innit sa last program nung 1st year
        while (c >= set[i]){
            c = c - set[i];
            arr[m++] = set[i];
        }
    }
    printf("\nTotal of Coins: %d", m);
    printf("\nList: ");
    for(i = 0; i<m; i++){ //printing the list of coins na magiging output equivalent sa amount
        printf("%d ", arr[i]);
    }
}