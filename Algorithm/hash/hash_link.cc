/*求质数*/

// for(int i = 100000;;i++){
//     bool flag = true;
//     for(int j = 2;j * j <= i;j++){
//         if(i % j == 0){
//             flag = false;
//             break;
//         }
//     }
//     if(flag){
//           printf("%d",i);
//           break;
//     }
// }
// return 0;


// #include <iostream>
// #include <cstring>
// using namespace std;
// const int N = 1e5 + 3; 

// int h[N]; // 哈希表中的槽
// int e[N],ne[N]; // 拉链法解决重复元素(处理冲突)
// int idx;

// void insert(int x){
//   int k = (x % N + N) % N; // 最终产生一个正哈希值,是一个下标,用来索引k位置上的槽.

//   e[idx] = x;
//   ne[idx] = h[k]; // h[k]存的是链表上第一个值的位置,相当于每条链表的head
//   h[k] = idx++; // 每个槽对应一个链表位置
// } 

// bool find(int x){
//   int k = (x % N + N) % N;
//   for(int i = h[k];i != -1;i = ne[i])
//     if(e[i] == x)
//       return true;
  
//   return false;
// }

// int main(){
//   int n;
//   scanf("%d",&n);

//   memset(h,-1,sizeof h); // 按照字节对内存块进行初始化
//   char op[2];
//   int x;
//   while(n--){
//     scanf("%s%d",op,&x);
//     if(*op == 'I'){
//       insert(x);
//     }else{
//       if(find(x)){
//         printf("Yes\n");
//       }else{
//         printf("No\n");
//       }
//     }
//   }
//   return 0;
// }

// #include <iostream>
// #include <cstring>
// using namespace std;

// const int N = 100003;
// int p[N]; // 槽

// int e[N];
// int ne[N];
// int n,idx;

// void insert(int x){
//   int k = (x % N + N) % N;

//   e[idx] = x;
//   ne[idx] = p[k];
//   p[k] = idx;
//   idx++;
// }

// bool query(int x){
//   int k = (x % N + N) % N;
//   bool flag = false;
//   for(int i = p[k];i != -1;i = ne[i]){
//     if(e[i] == x){
//       flag = true;
//     }
//   }
//   return flag;
// }

// int main(){
//   memset(p,-1,sizeof p);
//   scanf("%d",&n); 

//   char op[2];
//   int x;
//   while(n--){
//     scanf("%s%d",op,&x);
//     if(op[0] == 'I'){
//       insert(x);
//     }
//     else {
//       if(query(x)) printf("Yes\n");
//       else printf("No\n");
//     }
//   }
//   return 0;
// }

/*
#include <iostream>
#include <cstring>
using namespace std;

const int N = 100003;
int n,idx;
int e[N];
int ne[N];
int p[N];

void insert(int x){
  int k = (x % N + N) % N;

  e[idx] = x;
  ne[idx] = p[k];
  p[k] = idx;
  idx++;
}

bool query(int x){
  int k = (x % N + N) % N;

  for(int i = p[k];i != -1;i = ne[i]){
    if(e[i] == x){
      return true;
    }
  }
  return false;
}

int main(){
  memset(p,-1,sizeof p);

  scanf("%d",&n);

  char op[2];
  int x;

  while(n--){
    scanf("%s%d",op,&x);
    if(op[0] == 'I'){
      insert(x);
    }else{
      if(query(x)){
        printf("Yes\n");
      }else{
        printf("No\n");
      }
    }
  }
  return 0;
}*/


#include <cstring>
#include <iostream>
using namespace std;

const int N = 100003;
int n,idx;
int p[N],ne[N],e[N];

void insert(int x){
  int t = (x % N + N) % N; // 这条语句就将范围在-10e9 ~ 10e9的数字缩小到0 ~ 100002内

  e[idx] = x; // 这里需要取真正的数字
  ne[idx] = p[t];
  p[t] = idx;
  idx++;
}

bool query(int x){
  int t = (x % N + N) % N;
  
  for(int i = p[t];i != -1;i = ne[i]){ // p[]相当于每个头结点
    if(e[i] == x)
      return true;
  }
  return false;
}

int main(){
  memset(p,-1,sizeof p); // 因为相当于头结点,所以将头结点的指向全部置为0
  scanf("%d",&n);
  char op[2];
  while(n--){
    scanf("%s",op);
    if(*op == 'I'){
      int x;
      scanf("%d",&x);
      insert(x);
    }else{
      int x;
      scanf("%d",&x);
      if(query(x)){
        printf("Yes\n");
      }else{
        printf("No\n");
      }
    }
  }
  
  return 0;
}