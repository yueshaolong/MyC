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

union Date{

};

int main() {
    printf("Hello, World!\n�ҵ�C\n");

//    str();
//    strr();
    strarr();

    union Date date;
    return 0;
}