//
// Created by hasee on 2019/9/23.
//

#include <stdio.h>

int mainf(){
    FILE *pr = fopen("./a.txt", "r");
    if(pr){
        while(!feof(pr)){
            char c = fgetc(pr);
            printf("i=%s\n",c);
        }
    } else{
        printf("r����");
    }
    fclose(pr);
    
    FILE *pw = fopen("./a.txt", "w");
    if (pw){
        fputc('a', pw);
    } else{
        printf("w����");
    }
    fclose(pw);





}