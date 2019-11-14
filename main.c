#include <stdio.h>
#include <stdlib.h>

/*带参宏定义*/
#define M(y) y*y+3*y
//#undef M

#ifdef M  //如果宏已经定义，则返回真
#endif
#ifndef M //如果没有定义宏，则返回真
// 不带参数的宏定义
#define M 10//定义宏
#undef M//取消已定义的宏
#endif


#define  message_for(a, b) \
    printf(#a " and " #b ": We love you!\n")

#if SYSTEM_1
# include "system_1.h"
#elif SYSTEM_2
# include "system_2.h"
#elif SYSTEM_3
#endif

#define tokenpaster(n) printf (" " #n " = %d", token##n)

#if !defined (MESSAGE)//如果没有定义宏MESSAGE，则定义一下
#define MESSAGE "You wish!"
#endif

#define square(x) ((x) * (x))

#define MAX(x,y) ((x) > (y) ? (x) : (y))

typedef unsigned char BYTE;

int a();
int b();
int c();
void sw();
int a1();
int b1();
int c1();

void d();
void e();


//返回两个数中较大的一个
int max(int a, int b){
    return a>b ? a : b;
}
#define max(a,b)(a>b ? a : b);

void const_zz() {//常量指针
    //注意char const *p与const char *p效果相同。
    char const *p1;//const修饰的是char，定义为常量指针。
    // 因为const修饰的是char，所以p1所指向的内存地址所对应的值是const，不可修改。
    // 但指针所指向的内存地址是可以修改的，因为其并不是const类型。
    // p1=1;//正确  地址可改变
    // *(p1+1)='a';//错误  值不可改变

    //指针常量
    char *const p2;//const修饰的是*，定义为指针常量
    // 因为const修饰的是指针p2，所以指针所指向的内存地址是const，不可修改。
    // 但p2所指向内存地址所对应的值是可以修改的，因为其并不是const类型。
    // p2=1;//错误 地址不可变
    // p2[1]='a';//正确 值可以变
    // *(p2+1)='a';//正确 值可以变，和上一行结果一样

    //指向常量的指针常量: const同时修饰类型和指针。
    const char *const p3;
    char const *const p4;
    //因为const同时修饰这类型和指针，所以指针所指向的内存地址不可修改 同时内存地址所对应的值也不可修改。
    // p3=1;//错误 地址不可修改
    // p4[1]='a';//错误  值不可修改

}

void arr_zz() {
    //指针数组
    int *p3[5];//这里的p3是一个数组，具有5个int类型指针的数组
    //指针数组（也就是元素为指针类型的数组）常常作为二维数组的一种便捷替代方式。
    // 一般情况下，这种数组中的指针会指向动态分配的内存区域。
    /*如果一个数组中的所有元素保存的都是指针，那么我们就称它为指针数组。指针数组的定义形式一般为：
    dataType *arrayName[length];
    [ ]的优先级高于*，该定义形式应该理解为：
    dataType *(arrayName[length]);
    括号里面说明arrayName是一个数组，包含了length个元素，括号外面说明每个元素的类型为dataType *。*/
    int a = 16, b = 932, c = 100;
    //定义一个指针数组
    int *arr[3] = {&a, &b, &c};//也可以不指定长度，直接写作 int *arr[]
    //定义一个指向指针数组的指针
    int **parr = arr;
    printf("%d, %d, %d\n", *arr[0], *arr[1], *arr[2]);
    printf("%d, %d, %d\n", **(parr+0), **(parr+1), **(parr+2));
    /*运行结果：
    16, 932, 100
    16, 932, 100*/
    /*arr 是一个指针数组，它包含了 3 个元素，每个元素都是一个指针，在定义 arr 的同时，
    我们使用变量 a、b、c 的地址对它进行了初始化，这和普通数组是多么地类似。*/
    /*parr 是指向数组 arr 的指针，确切地说是指向 arr 第 0 个元素的指针，
    它的定义形式应该理解为int *(*parr)，括号中的*表示 parr 是一个指针，
    括号外面的int *表示 parr 指向的数据的类型。arr 第 0 个元素的类型为 int *，
    所以在定义 parr 时要加两个 *。*/
    /*第一个 printf() 语句中，arr[i] 表示获取第 i 个元素的值，该元素是一个指针，
    还需要在前面增加一个 * 才能取得它指向的数据，也即 *arr[i] 的形式。*/
    /*第二个 printf() 语句中，parr+i 表示第 i 个元素的地址，*(parr+i) 表示获取
    第 i 个元素的值（该元素是一个指针），**(parr+i) 表示获取第 i 个元素指向的数据。*/

    //指针数组还可以和字符串数组结合使用，请看下面的例子：
    char *str[3] = {
            "c.biancheng.net",
            "C语言中文网",
            "C Language"
    };
    printf("%s\n%s\n%s\n", str[0], str[1], str[2]);
    /*运行结果：
    c.biancheng.net
    C语言中文网
    C Language*/
    /*需要注意的是，字符数组 str 中存放的是字符串的首地址，不是字符串本身，字符串本身位于其他的内存区域，
    和字符数组是分开的。
    也只有当指针数组中每个元素的类型都是char *时，才能像上面那样给指针数组赋值，其他类型不行。*/
    //为了便于理解，可以将上面的字符串数组改成下面的形式，它们都是等价的。
    char *str0 = "c.biancheng.net";
    char *str1 = "C语言中文网";
    char *str2 = "C Language";
    char *str_2[3] = {str0, str1, str2};
    printf("%s\n%s\n%s\n", str_2[0], str_2[1], str_2[2]);



    //数组指针
    //要声明指向数组类型的指针，必须使用括号,这里arrPtr就是指向拥有10个元素数组的指针。
    int (*arrPtr)[10]; //这里的arrPtr是一个指针，指向一个具有10个元素的数组
    //在该例中，指向有10个int元素的数组的指针会被初始化为 NULL。
    // 然而，如果把合适数组的地址分配给它，那么表达式 *arrPtr 会获得数组，
    // 并且（*arrPtr）[i] 会获得索引为 i 的数组元素。根据下标运算符的规则，
    // 表达式（*arrPtr）[i] 等同于 *（（*arrPtr）+i）。
    // 因此，当i=0，**arrPtr 获得数组的第一个元素，其索引值为 0。

    //为了展示数组指针 arrPtr 的几个运算，下例使用它来定位一个二维数组的某些元素，也就是矩阵内的某些行：
    int matrix[3][10];            // 3行，10列的数组
    // 数组名称是一个指向第一个元素的指针，也就是第一行的指针
    arrPtr = matrix;            // 使得arrPtr指向矩阵的第一行
    (*arrPtr)[0] = 5;       // 将5赋值给第一行的第一个元素
    arrPtr[2][9] = 6;           // 将6赋值给最后一行的最后一个元素
    ++arrPtr;                   // 将指针移动到下一行
    (*arrPtr)[0] = 7;           // 将7赋值给第二行的第一个元素
}

void medthod_zz(){
    /*一个函数总是占用一段连续的内存区域，函数名在表达式中有时也会被转换为该函数所在内存区域的首地址，
    这和数组名非常类似。我们可以把函数的这个首地址（或称入口地址）赋予一个指针变量，
    使指针变量指向函数所在的内存区域，然后通过指针变量就可以找到并调用该函数。这种指针就是函数指针。*/
    /*函数指针的定义形式为：
    returnType (*pointerName)(param list);
    returnType 为函数返回值类型，pointerNmae 为指针名称，param list 为函数参数列表。
    参数列表中可以同时给出参数的类型和名称，也可以只给出参数的类型，省略参数的名称，
    这一点和函数原型非常类似。
    注意( )的优先级高于*，第一个括号不能省略，如果写作 returnType *pointerName(param list);
    就成了一个函数，它表明该函数的返回值类型是一个指针为returnType *。*/

    int x, y, maxval;
    //定义函数指针
    int (*pmax)(int, int) = max;  //也可以写作int (*pmax)(int a, int b)
    printf("Input two numbers:");//请输入两个数字
    scanf("%d %d", &x, &y);//在控制台输入两个数字
    maxval = (*pmax)(x, y);
    printf("Max value: %d\n", maxval);

}

int main() {
    printf("Hello, World!\n我的C\n");


//    int x =1, y =1, z = 1;
//    printf("%d\n", ++x || (++y && ++z));

//    puts("C语言中文网");
    /*宏调用*/
//    M(5);

//    message_for(Carole, Debra);

//    int tokens = 20;
//    tokenpaster(s);

//    printf("Here is the message: %s\n", MESSAGE);

//    printf("平方%d\n", square(2));
//    printf("Max between 20 and 10 is %d\n", MAX(10, 20));

//    BYTE a;
//    BYTE byte;

//    const_zz();
//    arr_zz();
//    medthod_zz();

//    a(23);
//    b();
//    c();
//    a1();
//    b1();
    c1();
//    d();
//    e();
//    sw();

    return 0;
}


int a(){
    char c = 128;
    printf("%d\n",c);
    printf("%hhd\n",c);
    printf("%hd\n",c);
    printf("%hu\n",c);
    return 0;
}

int b(){
    //声明一个整型变量
    int i = 10;
    //将i的地址使用取地址符给p指针
    int *p = &i;
    //输出 0xffff 16进制地址
    //%o和%x是将十进制数10按八进制和十六进制输出，
    // 而%号后面的‘#’的作用是完整呈现所有数值位数。
    // 显示八进制时，在数值前会加上数字0.显示十六进制时，会在数值前加上0x。
    // 如果配合%f、%e等浮点格式化字符时，即使所设置的数值不含小数部分，也会包含小数点。
    printf("%#x\n", &i);
    printf("%d\n", *p);
    printf("%p\n", &*p);

    //解引用 ?
    // p指向一个内存地址，使用*解出这个地址的值 即为 10
    int pv = *p;
    printf("%d\n", pv);
    printf("%p\n", &pv);
    //修改地址的值,则i值也变成100
    // 为解引用的结果赋值也就是为指针所指的内存赋值
    *p = 100;
    printf("%d\n", *p);

    return 0;
}

int c(){
    int array[5] = {0};
        //表达式中的数组名被编译器当做一个指向该数组第一个元素的指针
       printf("array = %p\n", array);//数组名被编译器当做一个指向该数组第一个元素的指针
       printf("&array = %p\n", &array);//数组的地址
       printf("&array = %p\n", &array[0]);//数组第一个元素的地址
       printf("array + 1 = %p\n", array + 1);//地址+1
       printf("&array + 1 = %p\n", &array + 1);
       printf("&array[0] + 1 = %p\n", &array[0] + 1);
       printf("\n");
       printf(" sizeof(int*) = %d\n", sizeof(int*));//计算的是指针的长度  8位
       printf(" sizeof(array[0]) = %d\n", sizeof(&array[0]));//计算的是指针的长度  8位
       printf("sizeof(&array) = %d\n", sizeof(&array));//计算的是指针的长度  8位
       printf(" sizeof(0xffffcc04) = %d\n",sizeof(0xffffcc04));//数值的长度  4位
       printf(" sizeof(array) = %d\n", sizeof(array));//数组类型的长度  20位

}



int a1(){
    int *ptr_i = NULL;

    char c;
    short s;

    char  *ptr_c = &c;
    short *ptr_s = &s;

    int n = 7;
    int *ptr_n = &n;
    printf("ptr_n d=%d\n", n);//7  n的值是7
    printf("ptr_n p=%p\n", &n);//000000000061FDBC  存数字7的地方（内存位置）
    printf("ptr_n p=%p\n", ptr_n);//000000000061FDBC，存数字7的地方（内存位置）
    printf("ptr_n p=%p\n", &ptr_n);//000000000061FDB8,存数字000000000061FDBC（6421948）的地方（内存位置）
    //这里是把地址转换成了十进制的值，如上面输出为000000000061FDBC，换算成十进制刚好是6421948
    printf("ptr_n d=%d\n", ptr_n);//6421948，指针的值

    printf("大小%d\n", sizeof(ptr_n));

    void *ptr_v = ptr_n;
    printf("ptr_v d=%d\n", ptr_v);//指针的值
    printf("ptr_v p=%p\n", ptr_v);//指针的地址

    int *ptr_n_1 = (int*)ptr_v;//等价
    printf("ptr_v d=%d\n", ptr_n_1);//指针的值
    printf("ptr_v p=%p\n", ptr_n_1);//指针的地址
    return 0;
};

int b1(){
    int i = 100;
    int *ptr_i = &i;
    printf("ptr_i%p\n", ptr_i);//000000000061FDDC  6421980 每加1，地址加4
    printf("ptr_i%p\n", ptr_i+1);//000000000061FDE0 6421984
    printf("ptr_i%p\n", ptr_i+2);//000000000061FDE4 6421988

    short c = 100;
    short *ptr_c = &c;
    printf("ptr_c%p\n", ptr_c);//000000000061FDDA  6421978  每加1，地址加2
    printf("ptr_c%p\n", ptr_c+1);//000000000061FDDC  6421980
    printf("ptr_c%p\n", ptr_c+2);//000000000061FDDE  6421982

    long d = 100;
    long *ptr_d = &d;
    printf("ptr_d%p\n", ptr_d);//000000000061FDCC  6421964  每加1，地址加4
    printf("ptr_d%p\n", ptr_d+1);//000000000061FDD0  6421968
    printf("ptr_d%p\n", ptr_d+2);//000000000061FDD4  6421972

    return 0;
}

int c1(){

    int arr[] = {1,2,3};

    int *ptr_arr = arr;
    printf("ptr_arr%p\n", ptr_arr);
    printf("arr%p\n", &arr);
    printf("ptr_arr[0]%d\n", ptr_arr[0]);

    ptr_arr[2] = 1000;//
    printf("ptr_arr[2]%d\n", arr[2]);

    return 0;
}

void d(){
    int i = 258;
    int j = 10000;

    int *ptr_i = &i;

    printf("%p\n", &i);
    printf("%p\n", &j);
    printf("%p\n", &ptr_i);
    printf("%p\n", ptr_i);
    printf("------------------------------\n");

    ptr_i = (int*)malloc(sizeof(int));
    printf("%p\n", &ptr_i);
    printf("%p\n", ptr_i);

    free(ptr_i);
    printf("----------------------\n");
    printf("%p\n", ptr_i);
    ptr_i = NULL;
    printf("%p\n", ptr_i);


}

void swap(int x, int y){
    int temp = x;
    x = y;
    y = temp;
}

void swap1(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void sw() {
    int a = 2;
    int b = 3;
    printf("交换前a=%d, b=%d\n", a, b);
    swap(a,b);
    printf("交换后a=%d, b=%d\n", a, b);
    printf("==============================\n");
    a = 20;
    b = 30;
    printf("交换前a=%d, b=%d\n", a, b);
    swap1(&a,&b);
    printf("交换后a=%d, b=%d\n", a, b);
}

void e(){
    int i = 100;
    int *ptr_i = &i;
    int **ptr_i2 = &ptr_i;

    printf("%p\n", &i);
    printf("%p\n", ptr_i);
    printf("%p\n", ptr_i2);
}