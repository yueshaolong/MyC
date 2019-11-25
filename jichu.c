#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX 1024

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

void sizeofMethod();

void getChar();

void powM();

void scanfM();

void strlenM();

void atoiM();

void itoaM();

void spM();

void snpM();

void putcharM();

void sqrtM();

void fabsM();

void strcopyM();

void strcatM();

void strcmpM();

void strncpyM();

void strncatM();

void strncmpM();

void fgetsM();

void mallocM();

void callocM();

void reallocM();

void memsetM();

void memcpyM();

void memmoveM();

void memcmpM();

void memchrM();

void randM();

void timeM();

void arrayP();

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

//    sizeofMethod();//所占用内存得字节数

//    getChar();//从标准输入流中获取字符

//    powM();//求x得y次方

//    scanfM();//格式化输入

//    strlenM();//求字符串长度
//    atoiM();//字符串类型改为整型
//    itoaM();//整型转换为字符串型

//    spM();//写入格式化数据到字符串
//    snpM();//写入指定长度得格式化数据到字符串
//    putcharM();//输出一个字符到标准输出流
//    sqrtM();//求平方根
//    fabsM();//求绝对值

//    strcopyM();//字符串拷贝
//    strncpyM();//受限字符串拷贝

//    strcatM();//字符串连接
//    strncatM();//受限字符串连接

//    strcmpM();//比较字符串比较大小
//    strncmpM();//受限得字符串比较大小

//    fgetsM();//从指定文件中读取字符串。

//    mallocM();//申请动态内存空间
//    callocM();//申请并初始化一系列内存空间
//    reallocM();//重新分配内存空间

//    memsetM();//使用一个常量填充内存空间,相当于初始化为某个值
//    memcpyM();//拷贝内存空间,按字节来拷贝的，不受数据类型影响
//    memmoveM();//拷贝内存空间,先拷贝源到一个临时数组，再从临时数组拷贝到目标内存，避免内存重叠更安全
//    memcmpM();//比较内存的大小

//    memchrM();//在内存空间中搜索一个字符

//    randM();//随机数

//    timeM();//时间相关


//    arrayP();//数组名字就是指向数组第一个元素的指针，指针法取值

    //指针数组，这是一个数组，里面存的元素是指针。
    char * str[3] = {"稍等", "sdfnsdkf", "到付哈地方"};
    for (int i = 0; i < 3; ++i) {
        printf("%s\n", str[i]);
    }
    //数组指针,指向一个数组的地址
    char c[3] = {'a', 'b', 'c'};
    char (*p)[3] = &c;
    for (int j = 0; j < 3; ++j) {
        printf("%c\n", *(*p+j));
    }

    return 0;
}

void arrayP() {
    //数组名是一个常量是不可变的，而指针是左值是一个变量
    char str[] = "sdefe";
    char *ps = str;
    printf("%p\n", str);
    printf("ps = %p\n", ps);
    printf("s的地址%p\n", &str[0]);
    for (int i = 0; i < strlen(str); ++i) {
        //ps+1并不是地址加1,而是移动到下一个元素
        printf("第%d个元素 %c\n", i, *(ps+i));//指针法取值
        printf("第%d个元素 %c\n", i, *(str+i));//指针法取值
        printf("第%d个元素 %c\n", i, str[i]);//下标法取值
    }
    int count = 0;
    while (*ps++ != '\0'){
        count ++;
    }
    printf("长度是%d\n", count);
}

void timeM() {
    time_t t;
    //函数用于返回从标准计时点到当前时间的秒数，即从 1970 年 1 月 1 日的
// UTC 时间 0 时 0 分 0 秒算起到现在所经过的秒数。
    time(&t);
    printf("1970年1月1日零点到现在经过了%ld个小时！\n",  t / 3600);//l 表示将相应的参数按 long 或 unsigned long 类型输出
    struct tm *pTm = localtime(&t);
    printf("秒：%d\n", pTm->tm_sec);//秒，范围为 0~59，60 的话表示闰秒
    printf("分：%d\n", pTm->tm_min);//分，范围是 0~59
    printf("时：%d\n", pTm->tm_hour);//时，范围是 0~23
    printf("一个月中的第几天：%d\n", pTm->tm_mday);//一个月中的第几天，范围是 1~31
    printf("一年中的第几个月：%d\n", pTm->tm_mon);//一年中的第几个月，范围是 0~11
    printf("自 1900 年往后的第几年：%d\n", pTm->tm_year);//自 1900 年往后的第几年
    printf("星期几：%d\n", pTm->tm_wday);//星期几，自星期天开始计算，范围是 0~6
    printf("一年中的第几天：%d\n", pTm->tm_yday);//一年中的第几天，范围是 0~365
    printf("指定日光节约时间是否生效：%d\n", pTm->tm_isdst);//指定日光节约时间是否生效，正数表示生效，0 表示不生效，负数表示该信息不可用

}

void randM() {
    int i;
    time_t t;

    // 使用当前时间值初始化伪随机数种子序列
    //函数用于返回从标准计时点到当前时间的秒数，即从 1970 年 1 月 1 日的
    // UTC 时间 0 时 0 分 0 秒算起到现在所经过的秒数。
    srand((unsigned)time(&t));
    printf("1970年1月1日零点到现在经过了%ld个小时！\n",  t / 3600);//l 表示将相应的参数按 long 或 unsigned long 类型输出
    struct tm *pTm = localtime(&t);

    // 生成0到99的伪随机数
    for (i = 0; i < 5; i++){
        printf("%d\n", rand() % 100);//0~99的随机数
        printf("%d\n", rand() % 10);//产生0~9的随机数，注意10会被整除
        //产生13~63的随机数，rand() % 51产生的是0~50随机数，再加13就是13~63
        printf("%d\n", rand() % 51 + 13);
        printf("\n");
    }
}

void memchrM() {
    char str1[] = "I love";
    //扫描 s 指向的内存空间的前 n 个字节，找到第一个匹配字符 c 时停止操作。
//1. 如果找到该字符，则返回指向该字符的指针；
//2. 如果找不到该字符，返回 NULL。
    char *c = (char *)memchr(str1, 'o', 8);
    if (c != NULL){
        printf("%#x\n", c);//0x61fe14
        printf("%c\n", *c);//o
    } else{
        printf("没找到\n");
    }
}

void memcmpM() {
    char str1[] = "I love";
    char str2[] = "I hove";
    //函数比较 s1 和 s2 指向的两个内存空间前 n 个字节，返回一个小于，
    // 等于或大于 0 的数表示 s1 小于、等于或大于 s2
    printf("%d\n", memcmp(str1, str2, 1));//0 表示相等
    printf("%d\n", memcmp(str1, str2, 3));//1 表示str1大于str2
}

void memmoveM() {
    char str[] = "I love com!";
    char *ptr;
    int length = sizeof(str);//18,  因为加上了字符串结束符'\0'

    printf("length = %d\n", length);

    ptr = (char *)malloc(length * sizeof(char));//操作的是字节数，所以要乘上类型所占的字节数
    if (ptr == NULL){
        exit(1);//函数用于立即终止当前进程的执行。
    }

    memset(ptr, 0, length * sizeof(char));//所有字节全初始化为0
//从 src 指向的内存空间拷贝 n 个字节到 dest 指向的内存空间。为了避免因为两个内存空间出现重叠
// 而导致的悲剧，该函数会先将 src 指向的内存空间拷贝到一个临时的数组中，
// 完了再从临时数组拷贝到目标内存空间。
    memmove(ptr, str, length * sizeof(char));//把str的全部字节拷贝给ptr

    printf("%s\n", ptr);
}

void memcpyM() {
    char str[] = "I love com!";
    char *ptr;
    int length = sizeof(str);//18,  因为加上了字符串结束符'\0'

    printf("length = %d\n", length);

    ptr = (char *)malloc(length * sizeof(char));//操作的是字节数，所以要乘上类型所占的字节数
    if (ptr == NULL){
//        exit(1);
    }

    memset(ptr, 0, length * sizeof(char));//所有字节全初始化为0
    //从 src 指向的内存空间拷贝 n 个字节到 dest 指向的内存空间。src 和 dest
    // 指向的内存区域不能出现重叠，否则应该使用 memmove 函数。
    memcpy(ptr, str, length * sizeof(char));//把str的全部字节拷贝给ptr

    printf("%s\n", ptr);
}

void memsetM() {
    int *ptr;

    ptr = (int *)malloc(3 * sizeof(int));//申请3*4个字节的内存空间
    if (ptr == NULL){
//        exit(1);
    }
    //使用0来填充ptr的前n个字节,这里把所有的字节都填充了0，就是全都初始化为0了。
    memset(ptr, 0, 3 * sizeof(int));
    for (int i = 0; i < 3; ++i) {
        printf("  %d", ptr[i]);
    }
}

void reallocM() {
    int i, num;
    int count = 0;
    int *ptr = NULL; // 注意，这里必须初始化为NULL

    do{
        printf("请输入一个整数(输入-1表示结束)：");
        scanf("%d", &num);
        count++;

        //重新分配内存空间,  每循环一次，就重新分配一次内存空间。空间也在8的倍数增加。
        ptr = (int *)realloc(ptr, count * sizeof(int));
        if (ptr == NULL){
            printf("内存空间不足！\n");
            exit(1);
        }

        ptr[count-1] = num;//ptr其实是一个int型的数组的指针
    } while(num != -1);

    printf("输入的整数分别是：");
    for (i = 0; i < count; i++){
        printf("%d ", ptr[i]);
    }
    printf("\n");

    free(ptr);
}

void callocM() {
    int i, num;
    long sum = 0;
    int *buffer;

    printf("你准备输入多少个整数：");
    scanf("%d", &num);

    //calloc 函数在内存中动态地申请 nmemb 个长度为 size 的连续内存空间（即申请的总空间尺寸为
// nmemb * size），这些内存空间全部被初始化为 0。如果 nmemb 或 size 参数的值为 0，
// 那么返回值会因标准库实现的不同而不同，可能是 NULL，也可能返回一个指针值，
// 稍后可以传递给 free 函数。
//返回一个指向申请的内存空间的指针，由于返回类型是 void 指针（void *），
// 所以它可以被转换成任何类型的数据。
    buffer = (int *)calloc(num, sizeof(int));//这里返回一个int型得指针
    if (buffer == NULL){
        printf("内存空间不足！\n");
        exit(1);
    }

    for (i = 0; i < num; i++){
        printf("请输入第%d个数字：", i+1);
        scanf("%d", &buffer[i]);//buffer其实是一个int型数组得指针，这里为数组元素赋值
        sum += buffer[i];
    }

    printf("：%d\n", buffer[0]);
    printf("：%d\n", buffer[1]);
    printf("：%d\n", buffer[2]);
    printf("它们的和是：%ld\n", sum);

    free(buffer);
}

void mallocM() {
    int i, length;
    char *buffer;

    printf("请输入字符串的长度：");
    scanf("%d", &length);//自己定一个字符串长度

    //malloc 函数向系统申请分配 size 个字节的内存空间，并返回一个指向这块空间的指针。
// 申请的这块空间并没有被“清理”（初始化为 0）。如果 size 的值为 0，
// 那么返回值会因标准库实现的不同而不同，可能是 NULL，也可能返回一个指针值，
// 稍后可以传递给 free 函数。
    buffer = (char *)malloc(length+1); // 还要存放'\0'字符
    if (buffer == NULL){
        printf("内存空间不足！\n");
        exit(1);
    }

    printf("请输入%d个字符的字符串：", length);

    //从标准输入流中获取字符
    getchar(); // 清除上一次输入残留的'\n'字符
    for (i = 0; i < length; i++){
        buffer[i] = (char)getchar();
    }
    buffer[i+1] = '\0';

    printf("您输入的字符串是：%s\n", buffer);

    //free 函数释放 ptr 参数指向的内存空间。该内存空间必须是由 malloc、calloc 或 realloc
    // 函数申请的。否则，该函数将导致未定义行为。如果 ptr 参数是 NULL，不执行任何操作。
    free(buffer);
}

void fgetsM() {
    char str[MAX];

    printf("请输入一个字符串：");//sdsf
    fgets(str, 3, stdin);//sd
// 最多可以读取 size - 1 个字符(这里就是读2个字符)，因为结尾处会自动添加一个字符串结束符 '\0'。
//当读取到换行符（'\n'）或文件结束符（EOF）时，表示结束读取（'\n' 会被作为一个合法的字符读取）。

    printf("您输入的内容是：%s", str);
}

void strncmpM() {
    char str1[40] = "FishC";
    char str2[40] = "FishC.com";
    printf("比较字符串： %d\n", strncmp(str1, str2, 3));//0 相等
    printf("比较字符串： %d\n", strncmp(str1, str2, 6));//-1 str1小于str2
    printf("比较字符串： %d\n", strncmp(str1, str2, 10));//-1 str1小于str2


}

void strncatM() {
    char str1[20] = "I ";
    char str2[20] = "love ";
    char str3[20] = "FishC.com!";

    strncat(str1, str2, 4);//I love
    strncat(str1, str3, 10);//I loveFishC.com!

    printf("str1: %s\n", str1);//I loveFishC.com!
}

void strncpyM() {
    char str1[] = "abcfdg4";
    char str2[30];
    strncpy(str2, str1, strlen(str1));
    printf("str2:%s\n", str2);//abcfdg4
    char str3[30];
    strncpy(str3, str1, 3);
    printf("str3:%s\n", str3);//abc
    char str4[30];
    strncpy(str4, str1, 30);
    printf("str4:%s\n", str4);//abcfdg4
    char str5[30];
    str5[29] = '\0';//为了使该函数更“安全”，建议使用 dest[sizeof(dest) - 1] = '\0';
// 语句确保目标字符串是以 '\0' 结尾
    strncpy(str5, str1, 29);
    printf("str5:%s\n", str5);//abcfdg4


}

void strcmpM() {
    char str1[] = "abc";
    char str2[] = "afv";
    printf("比较字符串：%d\n", strcmp(str1, str2));//-1
// < 0	字符串 1 的字符小于字符串 2 对应位置的字符
// 0	两个字符串的内容完全一致
// > 0	字符串 1 的字符大于字符串 2 对应位置的字符
}

void strcatM() {
    char str1[100] = "Original String";
    char str2[] = "New String";

    strcat(str1, "==");
    strcat(str1, str2);

    printf("str1: %s\n", str1);//Original String==New String

}

void strcopyM() {
    char str1[] = "Original String";
    char str2[] = "New String";
    char str3[100];

    strcpy(str1, str2);
    strcpy(str3, "Copy Successful");

    printf("str1: %s\n", str1);//New String
    printf("str2: %s\n", str2);//New String
    printf("str3: %s\n", str3);//Copy Successful
}

void fabsM() {
    printf("-3.14得绝对值是：%.1f\n", fabs(-3.14));//3.1
    printf("-3.14得绝对值是：%.2f\n", fabs(-3.14));//3.14
    printf("-3.14得绝对值是：%.4f\n", fabs(-3.14));//3.1400
    printf("-3.14得绝对值是：%f\n", fabs(-3.14));//3.140000

}

void sqrtM() {
    int i = (int)sqrt(16);
    printf("%d\n", i);//4
    double j = sqrt(17);
    printf("%f\n", j);//4.123106

}

void putcharM() {
    int c = 'A';
    int i = 3;
    while (i){
        c += i;
        i--;
        putchar(c);//DFG
        putchar('\n');
    }
}

void snpM() {
    char c[65];
    int i = snprintf(c, 6, "%s", "avcdfgsad");
    printf("字符串%s\n", c);//avcdfg
    printf("返回值是：%d\n", i);//-1  第二个参数缓冲区大小，小于字符串长度

//    int i1 = snprintf(c, 9, "avcdfgsad");
    int i1 = snprintf(c, 10, "avcdfgsad");
    printf("字符串%s\n", c);//avcdfgsad
    printf("返回值是：%d\n", i1);//9  第二个参数缓冲区大小大于等于字符串长度,返回选中的字符串长度

}

void spM() {
    char c[65];
    int i;
    i = sprintf(c,"%d + %d = %d", 2, 3, 2+3);
    printf("字符串%s\n", c);//字符串2 + 3 = 5
    printf("长度是：%d\n", i);//10

}

void itoaM() {
    int i;
    char c[65];//sizeof(int)=8;8*8+1
    printf("输一个数字：");
    scanf("%d\n", &i);
    itoa(i,c,10);
    printf("十进制输出：%s\n", c);
    itoa(i,c,2);
    printf("二进制输出：%s\n", c);
    itoa(i,c,16);
    printf("十六进制输出：%s\n", c);
}

void atoiM() {//字符串中得数字转换为整型
    printf("%d\n", atoi("abcd123"));//0
    printf("%d\n", atoi("123FishC"));//123
    printf("%d\n", atoi("1234"));//1234
    printf("%d\n", atoi("-12.34"));//-12
    printf("%d\n", atoi("123456789999999999"));//-519087105

}

void strlenM() {
    char c[] = "sdfsdfsf";
    printf("数组长度：%d\n", strlen(c));//8
    printf("数组大小：%d\n", sizeof(c));//9  数组大小包含了结束符\0,所以比长度大1
    char *cc = "lsdkfkfjl";
    printf("数组长度：%d\n", strlen(cc));//9
    printf("数组大小：%d\n", sizeof(cc));//8  这里求得是指针得大小，64位系统占8个字节

    int i = 2;
    int *pi = &i;
    printf("%d\n", sizeof(pi));
}

void scanfM() {
    char c;
    int i;
    int d;
    scanf("%c%d%x", &c, &i, &d);
    printf("变量c的值：%c\n", c);
    printf("变量i的值：%d\n", i);
    printf("变量j的值：%#X(%d)\n", d, d);
}

void powM() {
    double result = pow(2, 31) - 1;
    printf("4个字节表示的最大数：%f\n", result);//小数形式输出
    printf("4个字节表示的最大数：%e\n", result);//指数+e输出
    printf("4个字节表示的最大数：%E\n", result);//指数+E输出
    printf("4个字节表示的最大数：%g\n", result);//以 %f 或 %e 中较短的输出宽度输出
    printf("4个字节表示的最大数：%G\n", result);//以 %f 或 %E 中较短的输出宽度输出

}

void getChar() {
    int count = 0;
    printf("请输入一个字符串:");
    while (getchar() != '\n'){
        count += 1;
    }
    printf("字符串长度是：%d\n", count);
}

void sizeofMethod() {
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
}


