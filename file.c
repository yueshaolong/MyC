//
// Created by hasee on 2019/9/23.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void charRead();

void charWrite();

void strWrite();

void strRead();

void fprintfW();

void fscanfM();

void *fwriteB();

void freadB();

void tyzsq();

void bzscl();

void errzsq();

void clearerrM();

void dyerr();

void ioCach();

typedef struct Date {
    int year;
    int month;
    int day;
} DATE, *DATEP;

typedef struct Book {
    char name[40];
    float price;
    struct Date date;
} BOOK, *BOOKP;

int mainn(){
//    charRead();//���ļ���ȡ�ַ�
//    charWrite();//���ļ�д���ַ�

//    strWrite();//���ļ���д���ַ���
//    strRead();//���ļ��ж�ȡ�ַ���

//    fprintfW();//ʹ��fprintf����д������
//    fscanfM();//ʹ��scanf������ȡ����

//    fwriteB();//������д��
//    freadB();//��ȡ�������ļ�

//    tyzsq();//�ļ���Ծλ�ö�д

//    bzscl();//��׼���������
//    errzsq();//����ָʾ��
//    clearerrM();//clearerr �����������ָ���ļ���ĩβָʾ���ʹ���ָʾ��
//    dyerr();//��ӡ���ִ�����Ϣ

    ioCach();//IO����

    return 0;
}

void ioCach() {
    char buff[1024];
    memset(buff, '\0', sizeof(buff));
    //setvbuf ��������ָ��һ���������Ļ���ģʽ��
//�����������������ֻ���ģʽ�������棬���黺��Ͱ��л��档������������Ϊ�����棬
// ���ݻ�ֱ��д��Ŀ���ļ����ӡ����Ļ�ϣ��������Ϊ���黺�棬��ô���ݻ���д�뵽������У�
// �������Ϊ���л��棬��ô�ڽ��յ����з���'\n'��֮ǰ�����ݶ����Ȼ����ڻ������ġ�
    setvbuf(stdout, buff, _IONBF, 1024);//�黺�棬ȫ������
    fprintf(stdout, "welcome to zz\n");
    fflush(stdout);//ǿ��д���ļ���ǿ��ˢ�»�������
    fprintf(stdout, "12344");
    getchar();
}

void dyerr() {
    FILE *pIobuf = fopen("sdf.txt", "r");
    if (pIobuf == NULL){
        printf("���ļ�ʧ�ܣ�errno=%d\n", errno);//errno�������
        perror("���ļ�ʧ�ܣ�");//perror�������
        fprintf(stderr, "�����ˣ�%s ��ԭ��", strerror(errno));
//        exit(EXIT_FAILURE);
    }
}

void clearerrM() {
    //clearerr �����������ָ���ļ���ĩβָʾ���ʹ���ָʾ����
    FILE *pIobuf = fopen("../file/a.txt", "r");
    if (pIobuf == NULL){
        printf("�ļ���ʧ��");
        exit(EXIT_FAILURE);
    }
    clearerr(pIobuf);//�ļ���ĩβָʾ���ʹ���ָʾ����������ˣ������������䲻�ᱻ��ӡ
    if (feof(pIobuf) || ferror(pIobuf)){
        printf("------������------");
    }
    fclose(pIobuf);
}

void errzsq() {
    FILE *pIobuf1 = fopen("../file/a.txt", "r");
    if (pIobuf1 == NULL){
        fputs("���ļ�ʧ�ܣ�", stderr);//��׼�������
        exit(EXIT_FAILURE);
    }
    while (1){
        int ch = fgetc(pIobuf1);
        if (feof(pIobuf1)){
            break;
        }
        putchar(ch);
    }
    fputc('a', pIobuf1);
    //ferror����ָʾ��
    if (ferror(pIobuf1)){
        printf("������\n", stderr);
    }
    fclose(pIobuf1);
}

void bzscl() {
    FILE *pIobuf = fopen("sdf.txt", "r");
    if (pIobuf == NULL){
        fputs("���ļ�ʧ�ܣ�", stderr);//��׼�������
        exit(EXIT_FAILURE);
    }
}

void tyzsq() {
    FILE *pIobuf = fopen("../file/fell.txt", "w");
    if (pIobuf != NULL){
        //ftell  ��ǰ�ļ�ĩβ��λ��
        printf("%ld\n", ftell(pIobuf));
        fputc('F', pIobuf);
        printf("%d\n", ftell(pIobuf));
        fputs("asdf", pIobuf);
        printf("%ld\n", ftell(pIobuf));

        //��λ��ָʾ����ʼ�����ļ�ͷ��λ�ã���ʱ�������ݻḲ��ԭʼ������
        rewind(pIobuf);
        fputs("hello", pIobuf);
        long i = ftell(pIobuf);
        printf("%ld\n", i);

        fseek(pIobuf, i, SEEK_SET);
        fputc('V', pIobuf);
    } else{
        printf("д��ʧ��");
    }
    fclose(pIobuf);
}

void freadB() {
    struct Book *book_read;
    book_read = (BOOKP)malloc(sizeof(BOOK));
    if (book_read == NULL){
        printf("����ʧ�ܣ�");
        exit(EXIT_FAILURE);
    }
    FILE *pIobuf1 = fopen("../file/book.txt", "r");
    if (pIobuf1 != NULL){
        fread(book_read, sizeof(BOOK), 1, pIobuf1);
        printf("������%s\n", book_read->name);
        printf("�۸�%.1f\n", book_read->price);
        printf("���ڣ�%d-%d-%d\n", book_read->date.year, book_read->date.month,
                book_read->date.day);
    } else{
        printf("�Զ����ƶ�ȡ�ļ�ʧ��");
    }
    fclose(pIobuf1);
}

void *fwriteB() {
    struct Book *book_write;
    book_write = (BOOKP)malloc(sizeof(BOOK));
    if (book_write == NULL){
        printf("����ʧ�ܣ�");
        exit(EXIT_FAILURE);
    }
    strcpy(book_write->name, "C���Ի���");
    book_write->price = 12.0;
    book_write->date.year = 2019;
    book_write->date.month = 12;
    book_write->date.day = 4;

    FILE *pIobuf = fopen("../file/book.txt", "wb");
    if (pIobuf != NULL){
        fwrite(book_write, sizeof(BOOK), 1, pIobuf);
    } else{
        printf("�Զ�����д�ļ�ʧ��");
    }
    fclose(pIobuf);
}

void fscanfM() {
    int year,month,day;
    FILE *pIobuf = fopen("../file/date.txt", "a+");
    if (pIobuf != NULL){
        fscanf(pIobuf, "%d-%d-%d", &year, &month, &day);
    } else{
        printf("д�����");
    }
    printf("year=%d\n", year);
    printf("month=%d\n", month);
    printf("day=%d\n", day);
    fclose(pIobuf);
}

void fprintfW() {
    time_t t;
    time(&t);
    struct tm *pTm = localtime(&t);
    FILE *pIobuf = fopen("../file/date.txt", "w+");
    if (pIobuf != NULL){
        fprintf(pIobuf, "%d-%d-%d", 1900+pTm->tm_year, 1+pTm->tm_mon, pTm->tm_mday);
    } else{
        printf("д�����");
    }
    fclose(pIobuf);
}

void strRead() {//���ļ���ȡ�ַ���
    FILE *pIobuf1 = fopen("../file/string1.txt", "a+");
    char str1[128];
    if (pIobuf1 != NULL){
        //fgets ���������Զ�ȡ size - 1 ���ַ�����Ϊ��β�����Զ����һ���ַ��������� '\0'��
        // ����ȡ�����з���'\n'�����ļ���������EOF��ʱ����ʾ������ȡ��'\n' �ᱻ��Ϊһ���Ϸ����ַ���ȡ����
        while (!feof(pIobuf1)) {
            fgets(str1, 128, pIobuf1);//sdfj,Ϊʲô���ĸ��ַ�����Ϊ\0ռ����һ��λ��
            printf("%s\n", str1);
        }
    } else{
        printf("��ȡ�ַ�������");
    }
}

void strWrite() {
    FILE *pIobuf = fopen("../file/string1.txt", "w+");
    char str[128];
    if (pIobuf != NULL){
        printf("�������ַ�����");
        scanf("%s", str);
        fputs(str, pIobuf);
        fputs("\n", pIobuf);
        fputs("��ϲ��C����", pIobuf);
    } else{
        printf("a+����");
    }
    fclose(pIobuf);
}

void charWrite() {
//a+  ���壺
//1. �Զ���׷�ӵ�ģʽ��һ���ı��ļ�
//2. ����ļ��������򴴽�һ���µ��ļ�
//3. ��ȡ�Ǵ��ļ�ͷ��ʼ����д���������ļ�ĩβ׷��
    FILE *pw = fopen("../file/b.txt", "a+");
    if (pw){
        putc('x', pw);
//        fputc('x', pw);
    } else{
        printf("w����");
    }
    fclose(pw);
}

void charRead() {
//C:/Work/CLionProjects/MyC/file/a.txt  ����·�����Զ���
// ..\file\a.txt
// ../file/a.txt
// ���·��Ϊɶ�������㣿�� Clion �У�Դ�ļ�����������ɿ�ִ���ļ���
// ���� cmake-build-debug Ŀ¼�£�Ҳ�������յ�ִ��Ŀ¼�������ļ����·��Ӧ���� ../
    FILE *pr = fopen("..\\file\\a.txt", "r");
    int c;
    if(pr != NULL){
        while((c = getc(pr)) != EOF){
            putchar(c);
        }
    } else{
        printf("����\n");
    }
    fclose(pr);
    printf("\n");

    FILE *fp;
    int ch;
    if ((fp = fopen("C:\\Work\\CLionProjects\\MyC\\file\\a.txt", "r")) == NULL){
        printf("���ļ�ʧ�ܣ�\n");
    }
    while ((ch = fgetc(fp)) != EOF){
        putchar(ch);
    }
    fclose(fp);
}
