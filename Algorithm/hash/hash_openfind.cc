// #include <iostream>
// #include <cstring>
// using namespace std;

// /*开放寻址法*/
// const int N = 200003;
// int h[N], flag = 0x3f3f3f3f; // 1061109567 > 数据范围,作为没有查找到这个位置的标志

// // 如果存在,返回位置.如果不存在,返回应该存储的位置
// int find(int x){
//   int k = (x % N + N) % N; // 保证在正区间

//   while(h[k] != flag && h[k] != x){ // 可能存在并且还未找到此数
//     k++;
//     if(k == N)
//       k = 0;
//   }
//   return k;
// }

// int main(){
//   int n,x;
//   scanf("%d",&n);
//   char op[2];
//   memset(h,0x3f,sizeof h);

//   while(n--){
//     scanf("%s%d",op,&x);
//     if(*op == 'I'){
//       scanf("%d",&x);
//       h[find(x)] = x;
//     }else{
//       scanf("%d",&x);
//       if(h[find(x)] != flag) printf("Yes\n");
//       else printf("No\n");
//     }
//   }
//   return 0;
// }


// 开放寻址法(保证是不会产生冲突的)
#include <iostream>
#include <cstring>
using namespace std;

const int N = 200003; // 要开原数据大小的2~3倍
int flag = 0x3f3f3f3f;
int p[N];
int n;

int find(int x){
  int k = (x % N + N) % N;
  while(p[k] != x && p[k] != flag){
    k++;
    if(k > N)
      k = 0;
  }
  return k;
}

int main(){
  memset(p,0x3f,sizeof p);
  scanf("%d",&n);
 
  char op[2];
  int x;

  while(n--){
    scanf("%s%d",op,&x);

    if(op[0] == 'I'){
      if(p[find(x)] == flag)
        p[find(x)] = x;
    }else{
      if(p[find(x)] == flag)
        printf("No\n");
      else
        printf("Yes\n");
    }
  }
  return 0;
}
