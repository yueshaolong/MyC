#include <iostream>
#include <iomanip>
//命名空间，standard标准的命名空间，就可以缩写
using namespace std;

int main() {
    //如果没有上面的using语句，就应该是下面写法  ::表示从属关系，cout是属于std的，endl是属于std的
    // << 表示插入运算符（这里是重载运算符），插入到输出流里；
    // end line 相当于\n，但有区别：\n就只是换行；endl第一是换行，第二是把缓冲区全输出，flush的动作
    std::cout << "Hello World!" << std::endl;
    //加入命名空间后的简写
    cout << "Hello world!\n" << endl;
    cout << "hello" << " " << "world!" << endl;
    cout << INT_MAX << endl;
    cout << LONG_MAX << endl;
    cout << LONG_MIN << endl;
    cout << LONG_LONG_MAX << endl;
    cout << LONG_LONG_MIN << endl;

    int sa = 2500;
    cout << "小明的月薪是：" << sa << endl;

    float f = 123.123456789f;
    cout << f << endl;//123.123,精度是6到7位

    //怎么控制显示精度
    //1.强制以小数形式显示
    cout << fixed;
    //2.控制显示精度,小数点后面要显示几位
    cout << setprecision(10);
    double d = 10.0/3;
    cout << d << endl;//3.3333333333 小数点后显示10位

    //固定以小数方式显示，并保留小数点后两位。作用域为这句话以下所有的cout
    cout << fixed << setprecision(2);

    //setw设置宽度，相当于间隔宽度.作用域只限后面跟着的那个字符
    cout << "**" << setw(8) << "&&&&" << setw(8) << "%" << endl;//**    &&&&       %
    return 0;
}