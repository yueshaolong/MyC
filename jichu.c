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

union Date{

};

int main() {
    printf("Hello, World!\n我的C\n");

//    str();
//    strr();
    strarr();

    union Date date;
    return 0;
}