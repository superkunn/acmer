/*
1002. 写出这个数 (20)

时间限制
400 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
CHEN, Yue
读入一个自然数n，计算其各位数字之和，用汉语拼音写出和的每一位数字。

输入格式：每个测试输入包含1个测试用例，即给出自然数n的值。这里保证n小于10100。

输出格式：在一行内输出n的各位数字之和的每一位，拼音数字间有1 空格，但一行中最后一个拼音数字后没有空格。

输入样例：
1234567890987654321123456789
输出样例：
yi san wu

别人的代码敲了两遍收获不少

*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int len = s.length();

    int *a = new int [len];

    int sum = 0;

    string str[10] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};

    for(int i = 0; i < len; i++){
        a[i] = s[i] - '0';
        sum += a[i];
    }

    int *b = new int [len];
    int j = 0;
    if(sum == 0){
        cout<<"ling";
    }
    else{
        while(sum != 0){
            b[j++] = sum % 10;
            sum /= 10;
        }
    }

    for(int i = j-1;i >= 1; i--){
        cout<<str[b[i]]<<" ";
    }
    cout<<str[b[0]];
    delete [] a;
    delete [] b;




    return 0;
}
