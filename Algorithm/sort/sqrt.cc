// 求平方根
#include <iostream>
using namespace std;

int main(){
    float x,l,r,mid;
    scanf("%f",&x);
    l = 0,r = x;

    while(r - l > 1e-6){
        mid = (r + l) / 2;
        if(mid * mid > x)
            r = mid;
        else
            l = mid;
    }
    printf("%lf\n",l);
}