// #include <iostream>
// using namespace std;

// int n,m;
// const int N = 1e5 + 10;
// int a[N],s[N];

// int main(){
//     scanf("%d%d",&n,&m);

//     for(int i = 1;i <= n;i++){
//         scanf("%d",&a[i]);
//     }

//     // 前缀和数组
//     for(int i = 1;i <= n;i++){
//         s[i] = s[i-1] + a[i];
//     }

//     while(m--){
//         int l,r;
//         scanf("%d%d",&l,&r);
//         printf("%d\n",s[r] - s[l-1]);
//     }
//     return 0;
// }

// #include <iostream>
// using namespace std;

// int n,m;
// const int N = 1e5 + 10;
// int a[N],s[N];

// int main(){
//     scanf("%d%d",&n,&m);

//     for(int i = 1;i <= n;i++){
//         scanf("%d",&a[i]);
//         s[i] = s[i-1] + a[i];
//     }

//     while(m--){
//         int l,r;
//         scanf("%d%d",&l,&r);
//         printf("%d\n",s[r] - s[l-1]);
//     }
//     return 0;
// }

#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n,m;
int a[N],s[N];

int main(){
  scanf("%d%d",&n,&m);

  for(int i = 1;i <= n;i++){ // 从1开始统一了s[0]的计算过程
    scanf("%d",&a[i]);
  }

  for(int i = 1;i <= n;i++){
    s[i] = s[i-1] + a[i];
  }

  int l,r;
  while(m--){
    scanf("%d%d",&l,&r);
    printf("%d\n",s[r]-s[l-1]);
  }

  return 0;
}