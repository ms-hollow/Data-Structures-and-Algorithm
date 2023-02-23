/*  Leonen, Abbegail Miles
    BSCS-NS-1B
*/


#include <stdio.h>
#include <stdlib.h>


int addition(int n);
int subtraction(int n);
int multiplication(int n);
int division(int n);

int main(){

    int num_items, n, i, ans, score;
    float grade;
    srand(time(NULL));
    printf("Arithmethic Program\n");
    printf("===============================================\n");
    printf("How many items? ");
    scanf("%d", &num_items);
    printf("[1] Add\n");
    printf("[2] Subtract\n");
    printf("[3] Multiply\n");
    printf("[4] Divide\n");
    printf("[5] Exit\n");
    printf("Please pick from 1 to 5!\n");
    printf("_______________________________________________\n");
    scanf("%d", &ans);

    switch (ans){

        case 1: system("cls");
                score = addition(num_items);
                system("pause");
                break;
        case 2: system("cls");
                score = subtraction(num_items);
                system("pause");
                break;
        case 3: system("cls");
                score = multiplication(num_items);
                system("pause");
                break;
        case 4: system("cls");
                score = division(num_items);
                system("pause");
                break;
        case 5: exit(0); break;
        default:system("cls");
                printf("Please pick from 1 to 5!");
                system("pause");
    }

    grade = (float) score/num_items * 100;
    printf("You got %d correct answers out of %d for %6.2f%%.\n", score, num_items, grade);

}


int addition(int n){
    int i, n1, n2, answer, ctr=0;
    for (i=0;i<n;i++){
        n1 = rand() % 10 + 1;
        n2 = rand() % 10 + 1;
        printf("%d.) What is %d + %d? ",i+1, n1, n2);
        scanf("%d",&answer);
        if (answer == n1+n2){
            printf("Correct!\n");
            ctr++;
        }
        else {
            printf("Wrong! The correct answer is %d.\n", n1+n2);
        }
    }
    return ctr;
}

int subtraction(int n){
    int i, n1, n2, answer, ctr=0, crrctans;
    for (i=0;i<n;i++){
        n1 = rand() % 10 + 1;
        n2 = rand() % 10 + 1;
        printf("%d.) What is %d - %d? ",i+1, n1, n2);
        scanf("%d",&answer);
        crrctans = n1-n2;

        if(crrctans<0){
            crrctans *= -1;
        }

        if (answer == crrctans){
            printf("Correct!\n");
            ctr++;
        }
        else {
            printf("Wrong! The correct answer is %d.\n", crrctans);
        }

    }
    return ctr;
}

int multiplication(int n){
    int i, n1, n2, answer, ctr=0;
    for (i=0;i<n;i++){
        n1 = rand() % 10 + 1;
        n2 = rand() % 10 + 1;
        printf("%d.) What is %d * %d? ",i+1, n1, n2);
        scanf("%d",&answer);
        if (answer == n1*n2){
            printf("Correct!\n");
            ctr++;
        }
        else {
            printf("Wrong! The correct answer is %d.\n", n1*n2);
        }
    }
    return ctr;
}

int division(int n){
    int i, n1, n2, answer, ctr=0, temp;

    for (i=0;i<n;i++){
        n1 = rand() % 10 + 1;
        n2 = rand() % 10 + 1;
        printf("%d.) What is %d / %d? ",i+1, n1, n2);
        scanf("%d",&answer);

        if (n1 < n2 || n2 > n1){
            temp = n1;
            n1 = n2;
            n2 = temp;
        }

        if (answer == n1/n2){
            printf("Correct!\n");
            ctr++;
        }
        else {
           printf("Wrong! The correct answer is %d.\n", n1/n2);
        }
    }
    return ctr;
}
