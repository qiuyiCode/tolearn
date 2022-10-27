// // 先预处理出来字符串的前缀哈希
// // str = "abcabcdabcc"
// // h[0] = "",h[1] = "a",h[2] = "ab",h[3] = "abc"....

// #include <iostream>
// using namespace std;
// typedef unsigned long long ULL;
// const int N = 1e5 + 10;
// int n,m;
// const int p = 131; // 或者p = 13331
// ULL str_hash[N];
// ULL pow[N];

// ULL get(int l,int r){
//   return str_hash[r] - str_hash[l-1] * pow[r-l+1];
// }

// int main(){
//   scanf("%d%d",&n,&m);
//   char str[N];
//   scanf("%s",str+1);
//   pow[0] = 1;
//   for(int i = 1;i <= n;i++){ // i必须从1开始编号,如果从0开始则会出现哈希值重复的现象,如a,aa
//     pow[i] = pow[i-1] * p;
//     str_hash[i] = str_hash[i-1] * p + str[i];
//   }

//   int l1,r1,l2,r2;
  
//   while(m--){
//     scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
//     // ULL l = str_hash[r1] - str_hash[l1-1] * pow[r1-l1+1]; // 123456789,已知1-6,求4-6
//     // ULL r = str_hash[r2] - str_hash[l2-1] * pow[r2-l2+1];

//     if(get(l1,r1) == get(l2,r2))
//       printf("Yes\n");
//     else
//       printf("No\n");
//   }

//   return 0;
// }
/*
#include <iostream>
using namespace std;
typedef unsigned long long ULL;

int n,m,p = 131;
const int N = 1e5 + 10;
ULL str_hash[N],pow[N];

ULL get(int l,int r){
  return str_hash[r] - str_hash[l-1] * pow[r-l+1];
}

int main(){
  scanf("%d%d",&n,&m);
  char str[N];
  scanf("%s",str+1); // str是str[0],那么str+1即为从str[1]开始存储字符串

  pow[0] = 1;
  for(int i = 1;i <= n;i++){
    str_hash[i] = str_hash[i-1] * p + str[i];
    pow[i] = pow[i-1] * p;
  }

  while(m--){
    int l1,r1,l2,r2;
    scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
    if(get(l1,r1) == get(l2,r2))   // 为什么pow(p,r-l+1)不行呢 ? 因为可能数太大了,可能溢出,pow返回的是一个double类型的数
      printf("Yes\n"); 
    else
      printf("No\n");
  }

  return 0;
}*/


#include <iostream>
using namespace std;
typedef unsigned long long ULL; 

const int N = 1e5 + 10;
int n,m;
int p = 131;
ULL a[N],pow[N]; // p存储字符串哈希,q存储需要的进位

ULL cacl(int l,int r){
  ULL res = a[r] - a[l-1] * pow[r-l+1];
  return res;
}

int main(){
  char str[N];
  scanf("%d%d",&n,&m);
  scanf("%s",str+1);

  pow[0] = 1;
  for(int i = 1;i <= n;i++){
    a[i] = a[i-1] * p + str[i];
    pow[i] = pow[i-1] * p;
  }  

  int l1,r1,l2,r2;
  while(m--){
    scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
    if(cacl(l1,r1) == cacl(l2,r2))
      printf("Yes\n");
    else
      printf("No\n");
  }

  return 0;
}