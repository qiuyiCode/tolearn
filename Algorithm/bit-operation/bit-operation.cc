#include <iostream>
using namespace std;

int main(){
    int n = 10;
    // 能够计算一个数字作为二进制数中的第k位为几:n >> k & 1
    
    // 知道准确数字所表示的二进制个数,能够输出二进制表示
    for(int i = 3;i >= 0;i--){
        cout << (n >> i & 1);
    }

    /*
        lowbit(x):返回x的最后一位1,返回的是一个二进制数
        x = 1010 lowbit(x) = 10
        x = 101000 lowbit(x) = 1000
        lowbit(x) = x & -x; 即x & (~x + 1);
    */
}