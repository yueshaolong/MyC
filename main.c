#include <stdio.h>
#include <stdlib.h>

/*���κ궨��*/
#define M(y) y*y+3*y
//#undef M

#ifdef M  //������Ѿ����壬�򷵻���
#endif
#ifndef M //���û�ж���꣬�򷵻���
// ���������ĺ궨��
#define M 10//�����
#undef M//ȡ���Ѷ���ĺ�
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

#if !defined (MESSAGE)//���û�ж����MESSAGE������һ��
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


//�����������нϴ��һ��
int max(int a, int b){
    return a>b ? a : b;
}
#define max(a,b)(a>b ? a : b);

void const_zz() {//����ָ��
    //ע��char const *p��const char *pЧ����ͬ��
    char const *p1;//const���ε���char������Ϊ����ָ�롣
    // ��Ϊconst���ε���char������p1��ָ����ڴ��ַ����Ӧ��ֵ��const�������޸ġ�
    // ��ָ����ָ����ڴ��ַ�ǿ����޸ĵģ���Ϊ�䲢����const���͡�
    // p1=1;//��ȷ  ��ַ�ɸı�
    // *(p1+1)='a';//����  ֵ���ɸı�

    //ָ�볣��
    char *const p2;//const���ε���*������Ϊָ�볣��
    // ��Ϊconst���ε���ָ��p2������ָ����ָ����ڴ��ַ��const�������޸ġ�
    // ��p2��ָ���ڴ��ַ����Ӧ��ֵ�ǿ����޸ĵģ���Ϊ�䲢����const���͡�
    // p2=1;//���� ��ַ���ɱ�
    // p2[1]='a';//��ȷ ֵ���Ա�
    // *(p2+1)='a';//��ȷ ֵ���Ա䣬����һ�н��һ��

    //ָ������ָ�볣��: constͬʱ�������ͺ�ָ�롣
    const char *const p3;
    char const *const p4;
    //��Ϊconstͬʱ���������ͺ�ָ�룬����ָ����ָ����ڴ��ַ�����޸� ͬʱ�ڴ��ַ����Ӧ��ֵҲ�����޸ġ�
    // p3=1;//���� ��ַ�����޸�
    // p4[1]='a';//����  ֵ�����޸�

}

void arr_zz() {
    //ָ������
    int *p3[5];//�����p3��һ�����飬����5��int����ָ�������
    //ָ�����飨Ҳ����Ԫ��Ϊָ�����͵����飩������Ϊ��ά�����һ�ֱ�������ʽ��
    // һ������£����������е�ָ���ָ��̬������ڴ�����
    /*���һ�������е�����Ԫ�ر���Ķ���ָ�룬��ô���Ǿͳ���Ϊָ�����顣ָ������Ķ�����ʽһ��Ϊ��
    dataType *arrayName[length];
    [ ]�����ȼ�����*���ö�����ʽӦ�����Ϊ��
    dataType *(arrayName[length]);
    ��������˵��arrayName��һ�����飬������length��Ԫ�أ���������˵��ÿ��Ԫ�ص�����ΪdataType *��*/
    int a = 16, b = 932, c = 100;
    //����һ��ָ������
    int *arr[3] = {&a, &b, &c};//Ҳ���Բ�ָ�����ȣ�ֱ��д�� int *arr[]
    //����һ��ָ��ָ�������ָ��
    int **parr = arr;
    printf("%d, %d, %d\n", *arr[0], *arr[1], *arr[2]);
    printf("%d, %d, %d\n", **(parr+0), **(parr+1), **(parr+2));
    /*���н����
    16, 932, 100
    16, 932, 100*/
    /*arr ��һ��ָ�����飬�������� 3 ��Ԫ�أ�ÿ��Ԫ�ض���һ��ָ�룬�ڶ��� arr ��ͬʱ��
    ����ʹ�ñ��� a��b��c �ĵ�ַ���������˳�ʼ���������ͨ�����Ƕ�ô�����ơ�*/
    /*parr ��ָ������ arr ��ָ�룬ȷ�е�˵��ָ�� arr �� 0 ��Ԫ�ص�ָ�룬
    ���Ķ�����ʽӦ�����Ϊint *(*parr)�������е�*��ʾ parr ��һ��ָ�룬
    ���������int *��ʾ parr ָ������ݵ����͡�arr �� 0 ��Ԫ�ص�����Ϊ int *��
    �����ڶ��� parr ʱҪ������ *��*/
    /*��һ�� printf() ����У�arr[i] ��ʾ��ȡ�� i ��Ԫ�ص�ֵ����Ԫ����һ��ָ�룬
    ����Ҫ��ǰ������һ�� * ����ȡ����ָ������ݣ�Ҳ�� *arr[i] ����ʽ��*/
    /*�ڶ��� printf() ����У�parr+i ��ʾ�� i ��Ԫ�صĵ�ַ��*(parr+i) ��ʾ��ȡ
    �� i ��Ԫ�ص�ֵ����Ԫ����һ��ָ�룩��**(parr+i) ��ʾ��ȡ�� i ��Ԫ��ָ������ݡ�*/

    //ָ�����黹���Ժ��ַ���������ʹ�ã��뿴��������ӣ�
    char *str[3] = {
            "c.biancheng.net",
            "C����������",
            "C Language"
    };
    printf("%s\n%s\n%s\n", str[0], str[1], str[2]);
    /*���н����
    c.biancheng.net
    C����������
    C Language*/
    /*��Ҫע����ǣ��ַ����� str �д�ŵ����ַ������׵�ַ�������ַ��������ַ�������λ���������ڴ�����
    ���ַ������Ƿֿ��ġ�
    Ҳֻ�е�ָ��������ÿ��Ԫ�ص����Ͷ���char *ʱ������������������ָ�����鸳ֵ���������Ͳ��С�*/
    //Ϊ�˱�����⣬���Խ�������ַ�������ĳ��������ʽ�����Ƕ��ǵȼ۵ġ�
    char *str0 = "c.biancheng.net";
    char *str1 = "C����������";
    char *str2 = "C Language";
    char *str_2[3] = {str0, str1, str2};
    printf("%s\n%s\n%s\n", str_2[0], str_2[1], str_2[2]);



    //����ָ��
    //Ҫ����ָ���������͵�ָ�룬����ʹ������,����arrPtr����ָ��ӵ��10��Ԫ�������ָ�롣
    int (*arrPtr)[10]; //�����arrPtr��һ��ָ�룬ָ��һ������10��Ԫ�ص�����
    //�ڸ����У�ָ����10��intԪ�ص������ָ��ᱻ��ʼ��Ϊ NULL��
    // Ȼ��������Ѻ�������ĵ�ַ�����������ô���ʽ *arrPtr �������飬
    // ���ң�*arrPtr��[i] ��������Ϊ i ������Ԫ�ء������±�������Ĺ���
    // ���ʽ��*arrPtr��[i] ��ͬ�� *����*arrPtr��+i����
    // ��ˣ���i=0��**arrPtr �������ĵ�һ��Ԫ�أ�������ֵΪ 0��

    //Ϊ��չʾ����ָ�� arrPtr �ļ������㣬����ʹ��������λһ����ά�����ĳЩԪ�أ�Ҳ���Ǿ����ڵ�ĳЩ�У�
    int matrix[3][10];            // 3�У�10�е�����
    // ����������һ��ָ���һ��Ԫ�ص�ָ�룬Ҳ���ǵ�һ�е�ָ��
    arrPtr = matrix;            // ʹ��arrPtrָ�����ĵ�һ��
    (*arrPtr)[0] = 5;       // ��5��ֵ����һ�еĵ�һ��Ԫ��
    arrPtr[2][9] = 6;           // ��6��ֵ�����һ�е����һ��Ԫ��
    ++arrPtr;                   // ��ָ���ƶ�����һ��
    (*arrPtr)[0] = 7;           // ��7��ֵ���ڶ��еĵ�һ��Ԫ��
}

void medthod_zz(){
    /*һ����������ռ��һ���������ڴ����򣬺������ڱ��ʽ����ʱҲ�ᱻת��Ϊ�ú��������ڴ�������׵�ַ��
    ����������ǳ����ơ����ǿ��԰Ѻ���������׵�ַ�������ڵ�ַ������һ��ָ�������
    ʹָ�����ָ�������ڵ��ڴ�����Ȼ��ͨ��ָ������Ϳ����ҵ������øú���������ָ����Ǻ���ָ�롣*/
    /*����ָ��Ķ�����ʽΪ��
    returnType (*pointerName)(param list);
    returnType Ϊ��������ֵ���ͣ�pointerNmae Ϊָ�����ƣ�param list Ϊ���������б�
    �����б��п���ͬʱ�������������ͺ����ƣ�Ҳ����ֻ�������������ͣ�ʡ�Բ��������ƣ�
    ��һ��ͺ���ԭ�ͷǳ����ơ�
    ע��( )�����ȼ�����*����һ�����Ų���ʡ�ԣ����д�� returnType *pointerName(param list);
    �ͳ���һ���������������ú����ķ���ֵ������һ��ָ��ΪreturnType *��*/

    int x, y, maxval;
    //���庯��ָ��
    int (*pmax)(int, int) = max;  //Ҳ����д��int (*pmax)(int a, int b)
    printf("Input two numbers:");//��������������
    scanf("%d %d", &x, &y);//�ڿ���̨������������
    maxval = (*pmax)(x, y);
    printf("Max value: %d\n", maxval);

}

int main() {
    printf("Hello, World!\n�ҵ�C\n");


//    int x =1, y =1, z = 1;
//    printf("%d\n", ++x || (++y && ++z));

//    puts("C����������");
    /*�����*/
//    M(5);

//    message_for(Carole, Debra);

//    int tokens = 20;
//    tokenpaster(s);

//    printf("Here is the message: %s\n", MESSAGE);

//    printf("ƽ��%d\n", square(2));
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
    //����һ�����ͱ���
    int i = 10;
    //��i�ĵ�ַʹ��ȡ��ַ����pָ��
    int *p = &i;
    //��� 0xffff 16���Ƶ�ַ
    //%o��%x�ǽ�ʮ������10���˽��ƺ�ʮ�����������
    // ��%�ź���ġ�#������������������������ֵλ����
    // ��ʾ�˽���ʱ������ֵǰ���������0.��ʾʮ������ʱ��������ֵǰ����0x��
    // ������%f��%e�ȸ����ʽ���ַ�ʱ����ʹ�����õ���ֵ����С�����֣�Ҳ�����С���㡣
    printf("%#x\n", &i);
    printf("%d\n", *p);
    printf("%p\n", &*p);

    //������ ?
    // pָ��һ���ڴ��ַ��ʹ��*��������ַ��ֵ ��Ϊ 10
    int pv = *p;
    printf("%d\n", pv);
    printf("%p\n", &pv);
    //�޸ĵ�ַ��ֵ,��iֵҲ���100
    // Ϊ�����õĽ����ֵҲ����Ϊָ����ָ���ڴ渳ֵ
    *p = 100;
    printf("%d\n", *p);

    return 0;
}

int c(){
    int array[5] = {0};
        //���ʽ�е�������������������һ��ָ��������һ��Ԫ�ص�ָ��
       printf("array = %p\n", array);//������������������һ��ָ��������һ��Ԫ�ص�ָ��
       printf("&array = %p\n", &array);//����ĵ�ַ
       printf("&array = %p\n", &array[0]);//�����һ��Ԫ�صĵ�ַ
       printf("array + 1 = %p\n", array + 1);//��ַ+1
       printf("&array + 1 = %p\n", &array + 1);
       printf("&array[0] + 1 = %p\n", &array[0] + 1);
       printf("\n");
       printf(" sizeof(int*) = %d\n", sizeof(int*));//�������ָ��ĳ���  8λ
       printf(" sizeof(array[0]) = %d\n", sizeof(&array[0]));//�������ָ��ĳ���  8λ
       printf("sizeof(&array) = %d\n", sizeof(&array));//�������ָ��ĳ���  8λ
       printf(" sizeof(0xffffcc04) = %d\n",sizeof(0xffffcc04));//��ֵ�ĳ���  4λ
       printf(" sizeof(array) = %d\n", sizeof(array));//�������͵ĳ���  20λ

}



int a1(){
    int *ptr_i = NULL;

    char c;
    short s;

    char  *ptr_c = &c;
    short *ptr_s = &s;

    int n = 7;
    int *ptr_n = &n;
    printf("ptr_n d=%d\n", n);//7  n��ֵ��7
    printf("ptr_n p=%p\n", &n);//000000000061FDBC  ������7�ĵط����ڴ�λ�ã�
    printf("ptr_n p=%p\n", ptr_n);//000000000061FDBC��������7�ĵط����ڴ�λ�ã�
    printf("ptr_n p=%p\n", &ptr_n);//000000000061FDB8,������000000000061FDBC��6421948���ĵط����ڴ�λ�ã�
    //�����ǰѵ�ַת������ʮ���Ƶ�ֵ�����������Ϊ000000000061FDBC�������ʮ���Ƹպ���6421948
    printf("ptr_n d=%d\n", ptr_n);//6421948��ָ���ֵ

    printf("��С%d\n", sizeof(ptr_n));

    void *ptr_v = ptr_n;
    printf("ptr_v d=%d\n", ptr_v);//ָ���ֵ
    printf("ptr_v p=%p\n", ptr_v);//ָ��ĵ�ַ

    int *ptr_n_1 = (int*)ptr_v;//�ȼ�
    printf("ptr_v d=%d\n", ptr_n_1);//ָ���ֵ
    printf("ptr_v p=%p\n", ptr_n_1);//ָ��ĵ�ַ
    return 0;
};

int b1(){
    int i = 100;
    int *ptr_i = &i;
    printf("ptr_i%p\n", ptr_i);//000000000061FDDC  6421980 ÿ��1����ַ��4
    printf("ptr_i%p\n", ptr_i+1);//000000000061FDE0 6421984
    printf("ptr_i%p\n", ptr_i+2);//000000000061FDE4 6421988

    short c = 100;
    short *ptr_c = &c;
    printf("ptr_c%p\n", ptr_c);//000000000061FDDA  6421978  ÿ��1����ַ��2
    printf("ptr_c%p\n", ptr_c+1);//000000000061FDDC  6421980
    printf("ptr_c%p\n", ptr_c+2);//000000000061FDDE  6421982

    long d = 100;
    long *ptr_d = &d;
    printf("ptr_d%p\n", ptr_d);//000000000061FDCC  6421964  ÿ��1����ַ��4
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
    printf("����ǰa=%d, b=%d\n", a, b);
    swap(a,b);
    printf("������a=%d, b=%d\n", a, b);
    printf("==============================\n");
    a = 20;
    b = 30;
    printf("����ǰa=%d, b=%d\n", a, b);
    swap1(&a,&b);
    printf("������a=%d, b=%d\n", a, b);
}

void e(){
    int i = 100;
    int *ptr_i = &i;
    int **ptr_i2 = &ptr_i;

    printf("%p\n", &i);
    printf("%p\n", ptr_i);
    printf("%p\n", ptr_i2);
}