#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void str() {
    printf("字符串\n");
    char str[10] = {'h','e','l','l','o','\0'};
    char str1[10] = "hello";//'\0'可以省略
    char *str2 = "hello";//str2分配在栈上，"hello"分配在常量区
    printf("字符串%s\n", str);
    printf("字符串%s\n", str1);
    printf("字符串%s\n", str2);


    printf("输入一个字符串\n");
    char str3[10];
    scanf("%s", str3);//控制台接受一个字符串,遇到空格或回车会认为结束了。
    printf("str3 = %s\n", str3);
    char *str4 = (char *)calloc(10, sizeof(char));
    scanf("%s", str4);
    printf("str4 = %s\n", str4);
//    gets(str3);//控制台接受一个字符串,遇到空格也会输出
//    printf("str3 = %s\n", str3);
    fgets(str3, 10, stdin);//控制台接受一个字符串,只会获取10个字符，但看到的是9个，隐藏了一个结尾'\0'
    printf("str3 = %s\n", str3);
}

void strr() {
    printf("字符数组赋值\n");
    char str[10] = "abc";
    for (int i = 0; i < 10; ++i) {
        str[i] = 'a'+i;
    }
    printf("%s\n", str);//a b c d e f g h i j
    strcpy(str, "sdfsdf");//给str赋值
    printf("%s\n", str);//s d f s d f \0 h i j
    printf("strlen=%d\n", strlen(str));//6  真实数据长度，'\0'没有算上去，算到'\0'就结束
    printf("sizeof=%d\n", sizeof(str));//10  数组长度

    printf("---------------------------\n");
    printf("字符串拼接\n");
    char s1[] = "abc";
    char s2[] = "123";
    strcat(s1, s2);//（abc, 123）
    printf("拼接后%s\n", s1);//abc123
    strcat(s2, s1);//(123, abc123)
    printf("拼接后%s\n", s2);//123abc123
    printf("拼接后%s\n", s1);//bc123，原来跟s2的大小有关
    //s2[3]  输出：s2 = 123abcabcabca  s1 = abcabcabca
    //s2[4]  输出：s2 = 123abc  s1 = bc
    //s2[5]  输出：s2 = 123abc  s1 = c
    //s2[6]  输出：s2 = 123abc  s1 = 空
    //s2[7]  输出：s2 = 123abc  s1 = abc

    printf("---------------------------\n");
    printf("拷贝字符串\n");
    char *ss = "he";
    printf("s1 = %s\n", s1);//s1 = bc123
    strcpy(s1, ss);//把ss的字符拷贝到s1中
    printf("s1 = %s\n", s1);//s1 = he

    char c[10] = "sdf";
    strncpy(c, "hjkysfsdfs", 4);//只拷贝前4个字符
    printf("c = %s\n", c);//c = hjky

    printf("%d\n", strcmp("adq", "ad"));//判断两个字符串是否相等，相等是0，不相等时，大于1，小于-1
    printf("%d\n", strcmp("ad", "ad"));//0
    printf("%d\n", strcmp("a", "b"));//-1

}

void strarr() {
    printf("二维数组\n");
    char s[3][3] = {"sdf", "ss", "123"};
    printf("s[0] = %s\n", s[0]);//s[0] = sdfss
    strcpy(s[0], "aaa");//s[0]是一个数组名字，指向数组第一个元素地址
    printf("s[0] = %s\n", s[0]);//s[0] = aaa

    char *sss[] = {"df", "ffff","eee"};
    printf("sss[0] = %s\n", sss[0]);//sss[0] = df
    sss[0] = "abc";
    printf("sss[0] = %s\n", sss[0]);//sss[0] = abc
}

struct Books{//结构体
    char title[10];
    char auther[10];
    int id;
} book = {"C语言", "zero", 1};

int StructDemo() {
    printf("---------------------------\n");
    printf("book1.title = %s\n", book.title);
    printf("book1.auther = %s\n", book.auther);
    printf("book1.id = %d\n", book.id);
    struct Books book1;
    strcpy(book1.title, "adfsdf");
    strcpy(book1.auther, "kkk");
    book1.id=2;
    printf("book1.title = %s\n", book1.title);
    printf("book1.auther = %s\n", book1.auther);
    printf("book1.id = %d\n", book1.id);
    printf("sizeof(book1) = %d\n", sizeof(book1));//24
    struct Books *b;
    b = &book1;
    printf("---------------------------\n");
    printf("book1.title = %s\n", b->title);
    printf("book1.auther = %s\n", b->auther);
    printf("book1.id = %d\n", b->id);
    printf("book1.title = %s\n", (*b).title);
    printf("book1.auther = %s\n", (*b).auther);
    printf("book1.id = %d\n", (*b).id);

    return 0;
}
union Date{//共用体
    int i;
    float f;
    char str[20];
};
int unionDemo(){
    union Date date;
    date.i = 2;
    date.f = 2.1;
    strcpy(date.str, "sdf");
    printf("---------------------------\n");
    printf("date.i = %d\n", date.i);
    printf("date.f = %d\n", date.f);
    printf("date.str = %s\n", date.str);
    printf("sizeof(date) = %d\n", sizeof(date));//20
    return 0;
};

int main() {
    printf("Hello, World!\n我的C\n");

//    str();
//    strr();
//    strarr();

//    StructDemo();
//    unionDemo();

    printf("char 长度%d\n", sizeof(char));//1字节
    printf("short 长度%d\n", sizeof(short));//2字节

    printf("int 长度%d\n", sizeof(int));//4字节
    printf("short int 长度%d\n", sizeof(short int));//2字节
    printf("long int 长度%d\n", sizeof(long int));//4字节
    printf("long long int 长度%d\n", sizeof(long long int));//8字节

    printf("long 长度%d\n", sizeof(long));//4字节

    printf("float 长度%d\n", sizeof(float));//4字节
    printf("double 长度%d\n", sizeof(double));//8字节
    printf("long double 长度%d\n", sizeof(long double));//16字节

    printf("_Bool 长度%d\n", sizeof(_Bool));//1字节
    return 0;
}


