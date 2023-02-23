#include <stdio.h>
#define SIZE 4 // size of array

int i, m = 0, c, temp; 
int set[SIZE] = {1,6,10,25};
int arr[15] = {0}; //array para sa stack ng coins or magiging list siya ng coins


void main(){

    printf("Enter an amount you want to exchange: ");
    scanf("%d", &c);
    temp = c;

    for(i=SIZE-1 ;i>=0; i--){  
        while (c >= set[i]){
            c = c - set[i];
            arr[m] = set[i];
            m++;
        }
    }
    printf("Total of Coins: %d", m);
    printf("\nList: ");
    for(i = 0; i<m; i++){ //printing the list of coins na magiging output equivalent sa amount
        printf("%d ", arr[i]);
    }
}

void divCon(){
    if (m >= set[i])
        m -= set[i];
        arr[m] = set[i];
        m++;
    divCon(i);
}
