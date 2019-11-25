#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX 1024

void str() {
    printf("�ַ���\n");
    char str[10] = {'h','e','l','l','o','\0'};
    char str1[10] = "hello";//'\0'����ʡ��
    char *str2 = "hello";//str2������ջ�ϣ�"hello"�����ڳ�����
    printf("�ַ���%s\n", str);
    printf("�ַ���%s\n", str1);
    printf("�ַ���%s\n", str2);


    printf("����һ���ַ���\n");
    char str3[10];
    scanf("%s", str3);//����̨����һ���ַ���,�����ո��س�����Ϊ�����ˡ�
    printf("str3 = %s\n", str3);
    char *str4 = (char *)calloc(10, sizeof(char));
    scanf("%s", str4);
    printf("str4 = %s\n", str4);
//    gets(str3);//����̨����һ���ַ���,�����ո�Ҳ�����
//    printf("str3 = %s\n", str3);
    fgets(str3, 10, stdin);//����̨����һ���ַ���,ֻ���ȡ10���ַ�������������9����������һ����β'\0'
    printf("str3 = %s\n", str3);
}

void strr() {
    printf("�ַ����鸳ֵ\n");
    char str[10] = "abc";
    for (int i = 0; i < 10; ++i) {
        str[i] = 'a'+i;
    }
    printf("%s\n", str);//a b c d e f g h i j
    strcpy(str, "sdfsdf");//��str��ֵ
    printf("%s\n", str);//s d f s d f \0 h i j
    printf("strlen=%d\n", strlen(str));//6  ��ʵ���ݳ��ȣ�'\0'û������ȥ���㵽'\0'�ͽ���
    printf("sizeof=%d\n", sizeof(str));//10  ���鳤��

    printf("---------------------------\n");
    printf("�ַ���ƴ��\n");
    char s1[] = "abc";
    char s2[] = "123";
    strcat(s1, s2);//��abc, 123��
    printf("ƴ�Ӻ�%s\n", s1);//abc123
    strcat(s2, s1);//(123, abc123)
    printf("ƴ�Ӻ�%s\n", s2);//123abc123
    printf("ƴ�Ӻ�%s\n", s1);//bc123��ԭ����s2�Ĵ�С�й�
    //s2[3]  �����s2 = 123abcabcabca  s1 = abcabcabca
    //s2[4]  �����s2 = 123abc  s1 = bc
    //s2[5]  �����s2 = 123abc  s1 = c
    //s2[6]  �����s2 = 123abc  s1 = ��
    //s2[7]  �����s2 = 123abc  s1 = abc

    printf("---------------------------\n");
    printf("�����ַ���\n");
    char *ss = "he";
    printf("s1 = %s\n", s1);//s1 = bc123
    strcpy(s1, ss);//��ss���ַ�������s1��
    printf("s1 = %s\n", s1);//s1 = he

    char c[10] = "sdf";
    strncpy(c, "hjkysfsdfs", 4);//ֻ����ǰ4���ַ�
    printf("c = %s\n", c);//c = hjky

    printf("%d\n", strcmp("adq", "ad"));//�ж������ַ����Ƿ���ȣ������0�������ʱ������1��С��-1
    printf("%d\n", strcmp("ad", "ad"));//0
    printf("%d\n", strcmp("a", "b"));//-1

}

void strarr() {
    printf("��ά����\n");
    char s[3][3] = {"sdf", "ss", "123"};
    printf("s[0] = %s\n", s[0]);//s[0] = sdfss
    strcpy(s[0], "aaa");//s[0]��һ���������֣�ָ�������һ��Ԫ�ص�ַ
    printf("s[0] = %s\n", s[0]);//s[0] = aaa

    char *sss[] = {"df", "ffff","eee"};
    printf("sss[0] = %s\n", sss[0]);//sss[0] = df
    sss[0] = "abc";
    printf("sss[0] = %s\n", sss[0]);//sss[0] = abc
}

struct Books{//�ṹ��
    char title[10];
    char auther[10];
    int id;
} book = {"C����", "zero", 1};

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
union Date{//������
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
    printf("Hello, World!\n�ҵ�C\n");

//    str();
//    strr();
//    strarr();

//    StructDemo();
//    unionDemo();

//    sizeofMethod();//��ռ���ڴ���ֽ���

//    getChar();//�ӱ�׼�������л�ȡ�ַ�

//    powM();//��x��y�η�

//    scanfM();//��ʽ������

//    strlenM();//���ַ�������
//    atoiM();//�ַ������͸�Ϊ����
//    itoaM();//����ת��Ϊ�ַ�����

//    spM();//д���ʽ�����ݵ��ַ���
//    snpM();//д��ָ�����ȵø�ʽ�����ݵ��ַ���
//    putcharM();//���һ���ַ�����׼�����
//    sqrtM();//��ƽ����
//    fabsM();//�����ֵ

//    strcopyM();//�ַ�������
//    strncpyM();//�����ַ�������

//    strcatM();//�ַ�������
//    strncatM();//�����ַ�������

//    strcmpM();//�Ƚ��ַ����Ƚϴ�С
//    strncmpM();//���޵��ַ����Ƚϴ�С

//    fgetsM();//��ָ���ļ��ж�ȡ�ַ�����

//    mallocM();//���붯̬�ڴ�ռ�
//    callocM();//���벢��ʼ��һϵ���ڴ�ռ�
//    reallocM();//���·����ڴ�ռ�

//    memsetM();//ʹ��һ����������ڴ�ռ�,�൱�ڳ�ʼ��Ϊĳ��ֵ
//    memcpyM();//�����ڴ�ռ�,���ֽ��������ģ�������������Ӱ��
//    memmoveM();//�����ڴ�ռ�,�ȿ���Դ��һ����ʱ���飬�ٴ���ʱ���鿽����Ŀ���ڴ棬�����ڴ��ص�����ȫ
//    memcmpM();//�Ƚ��ڴ�Ĵ�С

//    memchrM();//���ڴ�ռ�������һ���ַ�

//    randM();//�����

//    timeM();//ʱ�����


//    arrayP();//�������־���ָ�������һ��Ԫ�ص�ָ�룬ָ�뷨ȡֵ

    //ָ�����飬����һ�����飬������Ԫ����ָ�롣
    char * str[3] = {"�Ե�", "sdfnsdkf", "�������ط�"};
    for (int i = 0; i < 3; ++i) {
        printf("%s\n", str[i]);
    }
    //����ָ��,ָ��һ������ĵ�ַ
    char c[3] = {'a', 'b', 'c'};
    char (*p)[3] = &c;
    for (int j = 0; j < 3; ++j) {
        printf("%c\n", *(*p+j));
    }

    return 0;
}

void arrayP() {
    //��������һ�������ǲ��ɱ�ģ���ָ������ֵ��һ������
    char str[] = "sdefe";
    char *ps = str;
    printf("%p\n", str);
    printf("ps = %p\n", ps);
    printf("s�ĵ�ַ%p\n", &str[0]);
    for (int i = 0; i < strlen(str); ++i) {
        //ps+1�����ǵ�ַ��1,�����ƶ�����һ��Ԫ��
        printf("��%d��Ԫ�� %c\n", i, *(ps+i));//ָ�뷨ȡֵ
        printf("��%d��Ԫ�� %c\n", i, *(str+i));//ָ�뷨ȡֵ
        printf("��%d��Ԫ�� %c\n", i, str[i]);//�±귨ȡֵ
    }
    int count = 0;
    while (*ps++ != '\0'){
        count ++;
    }
    printf("������%d\n", count);
}

void timeM() {
    time_t t;
    //�������ڷ��شӱ�׼��ʱ�㵽��ǰʱ������������� 1970 �� 1 �� 1 �յ�
// UTC ʱ�� 0 ʱ 0 �� 0 ������������������������
    time(&t);
    printf("1970��1��1����㵽���ھ�����%ld��Сʱ��\n",  t / 3600);//l ��ʾ����Ӧ�Ĳ����� long �� unsigned long �������
    struct tm *pTm = localtime(&t);
    printf("�룺%d\n", pTm->tm_sec);//�룬��ΧΪ 0~59��60 �Ļ���ʾ����
    printf("�֣�%d\n", pTm->tm_min);//�֣���Χ�� 0~59
    printf("ʱ��%d\n", pTm->tm_hour);//ʱ����Χ�� 0~23
    printf("һ�����еĵڼ��죺%d\n", pTm->tm_mday);//һ�����еĵڼ��죬��Χ�� 1~31
    printf("һ���еĵڼ����£�%d\n", pTm->tm_mon);//һ���еĵڼ����£���Χ�� 0~11
    printf("�� 1900 ������ĵڼ��꣺%d\n", pTm->tm_year);//�� 1900 ������ĵڼ���
    printf("���ڼ���%d\n", pTm->tm_wday);//���ڼ����������쿪ʼ���㣬��Χ�� 0~6
    printf("һ���еĵڼ��죺%d\n", pTm->tm_yday);//һ���еĵڼ��죬��Χ�� 0~365
    printf("ָ���չ��Լʱ���Ƿ���Ч��%d\n", pTm->tm_isdst);//ָ���չ��Լʱ���Ƿ���Ч��������ʾ��Ч��0 ��ʾ����Ч��������ʾ����Ϣ������

}

void randM() {
    int i;
    time_t t;

    // ʹ�õ�ǰʱ��ֵ��ʼ��α�������������
    //�������ڷ��شӱ�׼��ʱ�㵽��ǰʱ������������� 1970 �� 1 �� 1 �յ�
    // UTC ʱ�� 0 ʱ 0 �� 0 ������������������������
    srand((unsigned)time(&t));
    printf("1970��1��1����㵽���ھ�����%ld��Сʱ��\n",  t / 3600);//l ��ʾ����Ӧ�Ĳ����� long �� unsigned long �������
    struct tm *pTm = localtime(&t);

    // ����0��99��α�����
    for (i = 0; i < 5; i++){
        printf("%d\n", rand() % 100);//0~99�������
        printf("%d\n", rand() % 10);//����0~9���������ע��10�ᱻ����
        //����13~63���������rand() % 51��������0~50��������ټ�13����13~63
        printf("%d\n", rand() % 51 + 13);
        printf("\n");
    }
}

void memchrM() {
    char str1[] = "I love";
    //ɨ�� s ָ����ڴ�ռ��ǰ n ���ֽڣ��ҵ���һ��ƥ���ַ� c ʱֹͣ������
//1. ����ҵ����ַ����򷵻�ָ����ַ���ָ�룻
//2. ����Ҳ������ַ������� NULL��
    char *c = (char *)memchr(str1, 'o', 8);
    if (c != NULL){
        printf("%#x\n", c);//0x61fe14
        printf("%c\n", *c);//o
    } else{
        printf("û�ҵ�\n");
    }
}

void memcmpM() {
    char str1[] = "I love";
    char str2[] = "I hove";
    //�����Ƚ� s1 �� s2 ָ��������ڴ�ռ�ǰ n ���ֽڣ�����һ��С�ڣ�
    // ���ڻ���� 0 ������ʾ s1 С�ڡ����ڻ���� s2
    printf("%d\n", memcmp(str1, str2, 1));//0 ��ʾ���
    printf("%d\n", memcmp(str1, str2, 3));//1 ��ʾstr1����str2
}

void memmoveM() {
    char str[] = "I love com!";
    char *ptr;
    int length = sizeof(str);//18,  ��Ϊ�������ַ���������'\0'

    printf("length = %d\n", length);

    ptr = (char *)malloc(length * sizeof(char));//���������ֽ���������Ҫ����������ռ���ֽ���
    if (ptr == NULL){
        exit(1);//��������������ֹ��ǰ���̵�ִ�С�
    }

    memset(ptr, 0, length * sizeof(char));//�����ֽ�ȫ��ʼ��Ϊ0
//�� src ָ����ڴ�ռ俽�� n ���ֽڵ� dest ָ����ڴ�ռ䡣Ϊ�˱�����Ϊ�����ڴ�ռ�����ص�
// �����µı��磬�ú������Ƚ� src ָ����ڴ�ռ俽����һ����ʱ�������У�
// �����ٴ���ʱ���鿽����Ŀ���ڴ�ռ䡣
    memmove(ptr, str, length * sizeof(char));//��str��ȫ���ֽڿ�����ptr

    printf("%s\n", ptr);
}

void memcpyM() {
    char str[] = "I love com!";
    char *ptr;
    int length = sizeof(str);//18,  ��Ϊ�������ַ���������'\0'

    printf("length = %d\n", length);

    ptr = (char *)malloc(length * sizeof(char));//���������ֽ���������Ҫ����������ռ���ֽ���
    if (ptr == NULL){
//        exit(1);
    }

    memset(ptr, 0, length * sizeof(char));//�����ֽ�ȫ��ʼ��Ϊ0
    //�� src ָ����ڴ�ռ俽�� n ���ֽڵ� dest ָ����ڴ�ռ䡣src �� dest
    // ָ����ڴ������ܳ����ص�������Ӧ��ʹ�� memmove ������
    memcpy(ptr, str, length * sizeof(char));//��str��ȫ���ֽڿ�����ptr

    printf("%s\n", ptr);
}

void memsetM() {
    int *ptr;

    ptr = (int *)malloc(3 * sizeof(int));//����3*4���ֽڵ��ڴ�ռ�
    if (ptr == NULL){
//        exit(1);
    }
    //ʹ��0�����ptr��ǰn���ֽ�,��������е��ֽڶ������0������ȫ����ʼ��Ϊ0�ˡ�
    memset(ptr, 0, 3 * sizeof(int));
    for (int i = 0; i < 3; ++i) {
        printf("  %d", ptr[i]);
    }
}

void reallocM() {
    int i, num;
    int count = 0;
    int *ptr = NULL; // ע�⣬��������ʼ��ΪNULL

    do{
        printf("������һ������(����-1��ʾ����)��");
        scanf("%d", &num);
        count++;

        //���·����ڴ�ռ�,  ÿѭ��һ�Σ������·���һ���ڴ�ռ䡣�ռ�Ҳ��8�ı������ӡ�
        ptr = (int *)realloc(ptr, count * sizeof(int));
        if (ptr == NULL){
            printf("�ڴ�ռ䲻�㣡\n");
            exit(1);
        }

        ptr[count-1] = num;//ptr��ʵ��һ��int�͵������ָ��
    } while(num != -1);

    printf("����������ֱ��ǣ�");
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

    printf("��׼��������ٸ�������");
    scanf("%d", &num);

    //calloc �������ڴ��ж�̬������ nmemb ������Ϊ size �������ڴ�ռ䣨��������ܿռ�ߴ�Ϊ
// nmemb * size������Щ�ڴ�ռ�ȫ������ʼ��Ϊ 0����� nmemb �� size ������ֵΪ 0��
// ��ô����ֵ�����׼��ʵ�ֵĲ�ͬ����ͬ�������� NULL��Ҳ���ܷ���һ��ָ��ֵ��
// �Ժ���Դ��ݸ� free ������
//����һ��ָ��������ڴ�ռ��ָ�룬���ڷ��������� void ָ�루void *����
// ���������Ա�ת�����κ����͵����ݡ�
    buffer = (int *)calloc(num, sizeof(int));//���ﷵ��һ��int�͵�ָ��
    if (buffer == NULL){
        printf("�ڴ�ռ䲻�㣡\n");
        exit(1);
    }

    for (i = 0; i < num; i++){
        printf("�������%d�����֣�", i+1);
        scanf("%d", &buffer[i]);//buffer��ʵ��һ��int�������ָ�룬����Ϊ����Ԫ�ظ�ֵ
        sum += buffer[i];
    }

    printf("��%d\n", buffer[0]);
    printf("��%d\n", buffer[1]);
    printf("��%d\n", buffer[2]);
    printf("���ǵĺ��ǣ�%ld\n", sum);

    free(buffer);
}

void mallocM() {
    int i, length;
    char *buffer;

    printf("�������ַ����ĳ��ȣ�");
    scanf("%d", &length);//�Լ���һ���ַ�������

    //malloc ������ϵͳ������� size ���ֽڵ��ڴ�ռ䣬������һ��ָ�����ռ��ָ�롣
// ��������ռ䲢û�б�����������ʼ��Ϊ 0������� size ��ֵΪ 0��
// ��ô����ֵ�����׼��ʵ�ֵĲ�ͬ����ͬ�������� NULL��Ҳ���ܷ���һ��ָ��ֵ��
// �Ժ���Դ��ݸ� free ������
    buffer = (char *)malloc(length+1); // ��Ҫ���'\0'�ַ�
    if (buffer == NULL){
        printf("�ڴ�ռ䲻�㣡\n");
        exit(1);
    }

    printf("������%d���ַ����ַ�����", length);

    //�ӱ�׼�������л�ȡ�ַ�
    getchar(); // �����һ�����������'\n'�ַ�
    for (i = 0; i < length; i++){
        buffer[i] = (char)getchar();
    }
    buffer[i+1] = '\0';

    printf("��������ַ����ǣ�%s\n", buffer);

    //free �����ͷ� ptr ����ָ����ڴ�ռ䡣���ڴ�ռ�������� malloc��calloc �� realloc
    // ��������ġ����򣬸ú���������δ������Ϊ����� ptr ������ NULL����ִ���κβ�����
    free(buffer);
}

void fgetsM() {
    char str[MAX];

    printf("������һ���ַ�����");//sdsf
    fgets(str, 3, stdin);//sd
// �����Զ�ȡ size - 1 ���ַ�(������Ƕ�2���ַ�)����Ϊ��β�����Զ����һ���ַ��������� '\0'��
//����ȡ�����з���'\n'�����ļ���������EOF��ʱ����ʾ������ȡ��'\n' �ᱻ��Ϊһ���Ϸ����ַ���ȡ����

    printf("������������ǣ�%s", str);
}

void strncmpM() {
    char str1[40] = "FishC";
    char str2[40] = "FishC.com";
    printf("�Ƚ��ַ����� %d\n", strncmp(str1, str2, 3));//0 ���
    printf("�Ƚ��ַ����� %d\n", strncmp(str1, str2, 6));//-1 str1С��str2
    printf("�Ƚ��ַ����� %d\n", strncmp(str1, str2, 10));//-1 str1С��str2


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
    str5[29] = '\0';//Ϊ��ʹ�ú���������ȫ��������ʹ�� dest[sizeof(dest) - 1] = '\0';
// ���ȷ��Ŀ���ַ������� '\0' ��β
    strncpy(str5, str1, 29);
    printf("str5:%s\n", str5);//abcfdg4


}

void strcmpM() {
    char str1[] = "abc";
    char str2[] = "afv";
    printf("�Ƚ��ַ�����%d\n", strcmp(str1, str2));//-1
// < 0	�ַ��� 1 ���ַ�С���ַ��� 2 ��Ӧλ�õ��ַ�
// 0	�����ַ�����������ȫһ��
// > 0	�ַ��� 1 ���ַ������ַ��� 2 ��Ӧλ�õ��ַ�
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
    printf("-3.14�þ���ֵ�ǣ�%.1f\n", fabs(-3.14));//3.1
    printf("-3.14�þ���ֵ�ǣ�%.2f\n", fabs(-3.14));//3.14
    printf("-3.14�þ���ֵ�ǣ�%.4f\n", fabs(-3.14));//3.1400
    printf("-3.14�þ���ֵ�ǣ�%f\n", fabs(-3.14));//3.140000

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
    printf("�ַ���%s\n", c);//avcdfg
    printf("����ֵ�ǣ�%d\n", i);//-1  �ڶ���������������С��С���ַ�������

//    int i1 = snprintf(c, 9, "avcdfgsad");
    int i1 = snprintf(c, 10, "avcdfgsad");
    printf("�ַ���%s\n", c);//avcdfgsad
    printf("����ֵ�ǣ�%d\n", i1);//9  �ڶ���������������С���ڵ����ַ�������,����ѡ�е��ַ�������

}

void spM() {
    char c[65];
    int i;
    i = sprintf(c,"%d + %d = %d", 2, 3, 2+3);
    printf("�ַ���%s\n", c);//�ַ���2 + 3 = 5
    printf("�����ǣ�%d\n", i);//10

}

void itoaM() {
    int i;
    char c[65];//sizeof(int)=8;8*8+1
    printf("��һ�����֣�");
    scanf("%d\n", &i);
    itoa(i,c,10);
    printf("ʮ���������%s\n", c);
    itoa(i,c,2);
    printf("�����������%s\n", c);
    itoa(i,c,16);
    printf("ʮ�����������%s\n", c);
}

void atoiM() {//�ַ����е�����ת��Ϊ����
    printf("%d\n", atoi("abcd123"));//0
    printf("%d\n", atoi("123FishC"));//123
    printf("%d\n", atoi("1234"));//1234
    printf("%d\n", atoi("-12.34"));//-12
    printf("%d\n", atoi("123456789999999999"));//-519087105

}

void strlenM() {
    char c[] = "sdfsdfsf";
    printf("���鳤�ȣ�%d\n", strlen(c));//8
    printf("�����С��%d\n", sizeof(c));//9  �����С�����˽�����\0,���Աȳ��ȴ�1
    char *cc = "lsdkfkfjl";
    printf("���鳤�ȣ�%d\n", strlen(cc));//9
    printf("�����С��%d\n", sizeof(cc));//8  ���������ָ��ô�С��64λϵͳռ8���ֽ�

    int i = 2;
    int *pi = &i;
    printf("%d\n", sizeof(pi));
}

void scanfM() {
    char c;
    int i;
    int d;
    scanf("%c%d%x", &c, &i, &d);
    printf("����c��ֵ��%c\n", c);
    printf("����i��ֵ��%d\n", i);
    printf("����j��ֵ��%#X(%d)\n", d, d);
}

void powM() {
    double result = pow(2, 31) - 1;
    printf("4���ֽڱ�ʾ���������%f\n", result);//С����ʽ���
    printf("4���ֽڱ�ʾ���������%e\n", result);//ָ��+e���
    printf("4���ֽڱ�ʾ���������%E\n", result);//ָ��+E���
    printf("4���ֽڱ�ʾ���������%g\n", result);//�� %f �� %e �н϶̵����������
    printf("4���ֽڱ�ʾ���������%G\n", result);//�� %f �� %E �н϶̵����������

}

void getChar() {
    int count = 0;
    printf("������һ���ַ���:");
    while (getchar() != '\n'){
        count += 1;
    }
    printf("�ַ��������ǣ�%d\n", count);
}

void sizeofMethod() {
    printf("char ����%d\n", sizeof(char));//1�ֽ�
    printf("short ����%d\n", sizeof(short));//2�ֽ�

    printf("int ����%d\n", sizeof(int));//4�ֽ�
    printf("short int ����%d\n", sizeof(short int));//2�ֽ�
    printf("long int ����%d\n", sizeof(long int));//4�ֽ�
    printf("long long int ����%d\n", sizeof(long long int));//8�ֽ�

    printf("long ����%d\n", sizeof(long));//4�ֽ�

    printf("float ����%d\n", sizeof(float));//4�ֽ�
    printf("double ����%d\n", sizeof(double));//8�ֽ�
    printf("long double ����%d\n", sizeof(long double));//16�ֽ�

    printf("_Bool ����%d\n", sizeof(_Bool));//1�ֽ�
}


