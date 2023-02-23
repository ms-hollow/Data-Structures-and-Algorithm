//Leonen, Abbegail Miles
//BSCS-NS-2B

#include <stdio.h>

int chars[256];

void init(){
    //Index 0 will store the count for 'a', index 1 will store the count for 'b', and so on.
    //All counts (i.e. array elements) are initialized to zero.
    for (int i=0;i<256;i++)
        chars[i] = 0;
}

int main(){
    FILE *fp;
    int i, size = 0;
    char *fn, ch;

    system("cls");
    init();

    printf("Input file name: ");
    scanf("%s",fn);
    fp=fopen(fn,"r");

    if (fp==NULL){
        printf("File error.\n");
        system("pause");
    }
    while((ch=fgetc(fp))!=EOF){
        putchar(ch);
        size++;

        if(ch >= 0 && ch <= 255){
            chars[ch - 0]++;
            }
        }
        putchar('\n'); //put new line para hindi magkadikit ang output ng buong laman ng file and number of occurrences
        for(int i = 0; i< 256; i++){
        if(chars[i] != 0){ //hanggang hindi equal to zero tuloy ang loop
        //first output- decimal val of the ASCII char
        //second - character
        //third - number of occurences
        printf("%-5d: %-5c: %-5d\n",0 + i,0 + i,chars[i]);
                }
            }

    fclose(fp);
    printf("\nFile size: %d bytes/ %f kb.\n",size,size/1024.0);
    system("pause");
    return 0;
}
