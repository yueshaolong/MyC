#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    return 0;
}


