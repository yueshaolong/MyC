#include <iostream>
#include <iomanip>
//�����ռ䣬standard��׼�������ռ䣬�Ϳ�����д
using namespace std;

int main() {
    //���û�������using��䣬��Ӧ��������д��  ::��ʾ������ϵ��cout������std�ģ�endl������std��
    // << ��ʾ���������������������������������뵽������
    // end line �൱��\n����������\n��ֻ�ǻ��У�endl��һ�ǻ��У��ڶ��ǰѻ�����ȫ�����flush�Ķ���
    std::cout << "Hello World!" << std::endl;
    //���������ռ��ļ�д
    cout << "Hello world!\n" << endl;
    cout << "hello" << " " << "world!" << endl;
    cout << INT_MAX << endl;
    cout << LONG_MAX << endl;
    cout << LONG_MIN << endl;
    cout << LONG_LONG_MAX << endl;
    cout << LONG_LONG_MIN << endl;

    int sa = 2500;
    cout << "С������н�ǣ�" << sa << endl;

    float f = 123.123456789f;
    cout << f << endl;//123.123,������6��7λ

    //��ô������ʾ����
    //1.ǿ����С����ʽ��ʾ
    cout << fixed;
    //2.������ʾ����,С�������Ҫ��ʾ��λ
    cout << setprecision(10);
    double d = 10.0/3;
    cout << d << endl;//3.3333333333 С�������ʾ10λ

    //�̶���С����ʽ��ʾ��������С�������λ��������Ϊ��仰�������е�cout
    cout << fixed << setprecision(2);

    //setw���ÿ�ȣ��൱�ڼ�����.������ֻ�޺�����ŵ��Ǹ��ַ�
    cout << "**" << setw(8) << "&&&&" << setw(8) << "%" << endl;//**    &&&&       %
    return 0;
}