//
// Created by hasee on 2019/9/23.
//

#include <stdio.h>

int main(){
    //C:/Work/CLionProjects/MyC
    FILE *pr = fopen("C:/Work/CLionProjects/MyC/file/a.txt", "r");
    if(pr != NULL){
        while(getc(pr) != EOF){
            putchar(getc(pr));
        }
    } else{
        printf("����\n");
    }
    fclose(pr);

//    FILE *fp;
//    int ch;
//    if ((fp = fopen("C:\\Work\\CLionProjects\\MyC\\file\\a.txt", "r")) == NULL){
//        printf("���ļ�ʧ�ܣ�\n");
//    }
//    while ((ch = fgetc(fp)) != EOF){
//        putchar(ch);
//    }
//    fclose(fp);
    
    /*FILE *pw = fopen("./file.txt", "w");
    if (pw){
        fputc('a', pw);
    } else{
        printf("w����");
    }
    fclose(pw);*/





}