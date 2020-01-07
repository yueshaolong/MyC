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
//    charRead();//从文件读取字符
//    charWrite();//向文件写入字符

//    strWrite();//向文件中写入字符串
//    strRead();//从文件中读取字符串

//    fprintfW();//使用fprintf函数写入数据
//    fscanfM();//使用scanf函数读取数据

//    fwriteB();//二进制写入
//    freadB();//读取二进制文件

//    tyzsq();//文件跳跃位置读写

//    bzscl();//标准错误输出流
//    errzsq();//错误指示器
//    clearerrM();//clearerr 函数用于清除指定文件的末尾指示器和错误指示器
//    dyerr();//打印各种错误信息

    ioCach();//IO缓存

    return 0;
}

void ioCach() {
    char buff[1024];
    memset(buff, '\0', sizeof(buff));
    //setvbuf 函数用于指定一个数据流的缓存模式。
//对于数据流，有三种缓存模式：不缓存，按块缓存和按行缓存。如果输出流设置为不缓存，
// 数据会直接写入目标文件或打印到屏幕上；如果设置为按块缓存，那么数据会先写入到缓存块中；
// 如果设置为按行缓存，那么在接收到换行符（'\n'）之前，数据都是先缓存在缓冲区的。
    setvbuf(stdout, buff, _IONBF, 1024);//块缓存，全量缓存
    fprintf(stdout, "welcome to zz\n");
    fflush(stdout);//强制写入文件，强制刷新缓冲区。
    fprintf(stdout, "12344");
    getchar();
}

void dyerr() {
    FILE *pIobuf = fopen("sdf.txt", "r");
    if (pIobuf == NULL){
        printf("打开文件失败！errno=%d\n", errno);//errno错误输出
        perror("打开文件失败！");//perror错误输出
        fprintf(stderr, "出错了：%s 的原因。", strerror(errno));
//        exit(EXIT_FAILURE);
    }
}

void clearerrM() {
    //clearerr 函数用于清除指定文件的末尾指示器和错误指示器。
    FILE *pIobuf = fopen("../file/a.txt", "r");
    if (pIobuf == NULL){
        printf("文件打开失败");
        exit(EXIT_FAILURE);
    }
    clearerr(pIobuf);//文件的末尾指示器和错误指示器都被清除了，所以下面的语句不会被打印
    if (feof(pIobuf) || ferror(pIobuf)){
        printf("------出错啦------");
    }
    fclose(pIobuf);
}

void errzsq() {
    FILE *pIobuf1 = fopen("../file/a.txt", "r");
    if (pIobuf1 == NULL){
        fputs("打开文件失败！", stderr);//标准错误输出
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
    //ferror错误指示器
    if (ferror(pIobuf1)){
        printf("出错了\n", stderr);
    }
    fclose(pIobuf1);
}

void bzscl() {
    FILE *pIobuf = fopen("sdf.txt", "r");
    if (pIobuf == NULL){
        fputs("打开文件失败！", stderr);//标准错误输出
        exit(EXIT_FAILURE);
    }
}

void tyzsq() {
    FILE *pIobuf = fopen("../file/fell.txt", "w");
    if (pIobuf != NULL){
        //ftell  当前文件末尾的位置
        printf("%ld\n", ftell(pIobuf));
        fputc('F', pIobuf);
        printf("%d\n", ftell(pIobuf));
        fputs("asdf", pIobuf);
        printf("%ld\n", ftell(pIobuf));

        //将位置指示器初始化到文件头的位置，此时插入数据会覆盖原始的数据
        rewind(pIobuf);
        fputs("hello", pIobuf);
        long i = ftell(pIobuf);
        printf("%ld\n", i);

        fseek(pIobuf, i, SEEK_SET);
        fputc('V', pIobuf);
    } else{
        printf("写入失败");
    }
    fclose(pIobuf);
}

void freadB() {
    struct Book *book_read;
    book_read = (BOOKP)malloc(sizeof(BOOK));
    if (book_read == NULL){
        printf("分配失败！");
        exit(EXIT_FAILURE);
    }
    FILE *pIobuf1 = fopen("../file/book.txt", "r");
    if (pIobuf1 != NULL){
        fread(book_read, sizeof(BOOK), 1, pIobuf1);
        printf("书名：%s\n", book_read->name);
        printf("价格：%.1f\n", book_read->price);
        printf("日期：%d-%d-%d\n", book_read->date.year, book_read->date.month,
                book_read->date.day);
    } else{
        printf("以二进制读取文件失败");
    }
    fclose(pIobuf1);
}

void *fwriteB() {
    struct Book *book_write;
    book_write = (BOOKP)malloc(sizeof(BOOK));
    if (book_write == NULL){
        printf("分配失败！");
        exit(EXIT_FAILURE);
    }
    strcpy(book_write->name, "C语言基础");
    book_write->price = 12.0;
    book_write->date.year = 2019;
    book_write->date.month = 12;
    book_write->date.day = 4;

    FILE *pIobuf = fopen("../file/book.txt", "wb");
    if (pIobuf != NULL){
        fwrite(book_write, sizeof(BOOK), 1, pIobuf);
    } else{
        printf("以二进制写文件失败");
    }
    fclose(pIobuf);
}

void fscanfM() {
    int year,month,day;
    FILE *pIobuf = fopen("../file/date.txt", "a+");
    if (pIobuf != NULL){
        fscanf(pIobuf, "%d-%d-%d", &year, &month, &day);
    } else{
        printf("写入出错！");
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
        printf("写入出错！");
    }
    fclose(pIobuf);
}

void strRead() {//从文件读取字符串
    FILE *pIobuf1 = fopen("../file/string1.txt", "a+");
    char str1[128];
    if (pIobuf1 != NULL){
        //fgets 函数最多可以读取 size - 1 个字符，因为结尾处会自动添加一个字符串结束符 '\0'。
        // 当读取到换行符（'\n'）或文件结束符（EOF）时，表示结束读取（'\n' 会被作为一个合法的字符读取）。
        while (!feof(pIobuf1)) {
            fgets(str1, 128, pIobuf1);//sdfj,为什么是四个字符，因为\0占用了一个位置
            printf("%s\n", str1);
        }
    } else{
        printf("读取字符串出错！");
    }
}

void strWrite() {
    FILE *pIobuf = fopen("../file/string1.txt", "w+");
    char str[128];
    if (pIobuf != NULL){
        printf("请输入字符串：");
        scanf("%s", str);
        fputs(str, pIobuf);
        fputs("\n", pIobuf);
        fputs("我喜欢C语言", pIobuf);
    } else{
        printf("a+出错");
    }
    fclose(pIobuf);
}

void charWrite() {
//a+  含义：
//1. 以读和追加的模式打开一个文本文件
//2. 如果文件不存在则创建一个新的文件
//3. 读取是从文件头开始，而写入则是在文件末尾追加
    FILE *pw = fopen("../file/b.txt", "a+");
    if (pw){
        putc('x', pw);
//        fputc('x', pw);
    } else{
        printf("w出错");
    }
    fclose(pw);
}

void charRead() {
//C:/Work/CLionProjects/MyC/file/a.txt  绝对路径可以读到
// ..\file\a.txt
// ../file/a.txt
// 相对路径为啥是两个点？在 Clion 中，源文件经编译后生成可执行文件，
// 放在 cmake-build-debug 目录下，也就是最终的执行目录，所以文件相对路径应该是 ../
    FILE *pr = fopen("..\\file\\a.txt", "r");
    int c;
    if(pr != NULL){
        while((c = getc(pr)) != EOF){
            putchar(c);
        }
    } else{
        printf("出错\n");
    }
    fclose(pr);
    printf("\n");

    FILE *fp;
    int ch;
    if ((fp = fopen("C:\\Work\\CLionProjects\\MyC\\file\\a.txt", "r")) == NULL){
        printf("打开文件失败！\n");
    }
    while ((ch = fgetc(fp)) != EOF){
        putchar(ch);
    }
    fclose(fp);
}
