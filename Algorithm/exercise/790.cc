// #include <iostream>
// using namespace std;

// double sqrt3(double x){
//   return x * x * x;
// }

// int main(){
//   double n; // n的范围是[-10000,10000]
//   double l = -10000,r = 10000;
//   cin >> n;
  
//   while(r - l >= 1e-7){
//     double mid = (l + r) / 2; // 只有整数有移位操作
//     if(sqrt3(mid) > n){
//       r = mid;
//     }else{
//       l = mid;
//     }
//   }

//   printf("%.6f",l);
// }

#include <iostream>
using namespace std;

double l = -10000,r = 10000;
double n;

int main(){
  scanf("%lf",&n);
  double mid;
  while(r - l > 1e-8){
    mid = (r + l) / 2;
    if(mid * mid * mid > n) r = mid;
    else l = mid;
  }
  printf("%.6f",mid);
  return 0;
}
