#include <iostream>
using namespace std;

// 立方根,只有一个数字,可能是正,可能是负

double q(double a){
    return a * a * a;
}

int main(){
    double n,l,r;
    // cin >> n; // scanf不能控制输入精度
    scanf("%lf",&n);
    l = -10000,r = 10000;
    while(r - l >= 1e-7){
        double mid = (l+r) / 2;
        if(q(mid) >= n) r = mid;
        else l = mid;
    }
    printf("%.6f",l);
}


