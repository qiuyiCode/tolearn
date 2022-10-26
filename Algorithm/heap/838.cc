// #include <iostream>
// #include <algorithm>
// using namespace std;

// const int N = 1e5 + 10;
// int n,m;
// int heap[N],sz; // sz是heap的元素个数

// /*堆能够支持的操作
//   1.插入一个数 heap[++size] = x;up(size);
//   2.求集合当中的最小值 heap[1]
//   3.删除最小值 heap[1] = heap[size];size--;down(1)

// // STL(优先队列)支持1,2,3不支持4,5

//   4.删除任意一个元素 heap[k] = heap[size];size--;down(k);up(k); // down和up只会执行一个
//   5.修改任意一个元素 heap[k] = x;down(k);up(k)
// */

// /*
//   堆是一个完全二叉树
//   小根堆:递归定义,父节点小于等于子节点的值,根节点即为整个数据结构的最小值
// */

// /*
//   两个基本操作:down(),up()
//   用来维护堆的结构
// */

// /*用一个数组模拟,下标从1开始*/

// void down(int u){
//   // 首先判断u是不是父子之间的最小值,用t表示
//   int t = u;
//   // 判断有没有左儿子,并且左儿子是否小于它的父亲
//   if(u * 2 <= sz && heap[2*u] < heap[t]) t = 2 * u;
//   // 判断有没有右儿子,并且右儿子是否小于它的父亲
//   if(u * 2 + 1 <= sz && heap[2*u+1] < heap[t]) t = 2 * u + 1;

//   if(u != t){
//     swap(heap[u],heap[t]);
//     down(t); // 递归
//   }
// }

// /*----------------up操作----------------*/

// // void up(int u){
// //   while(u / 2 && heap[u / 2] > heap[u]){
// //     swap(heap[u/2],heap[u]);
// //     u /= 2;
// //   }
// // }

// int main(){
//   scanf("%d%d",&n,&m);

//   for(int i = 1;i <= n;i++){
//     scanf("%d",&heap[i]);
//   }
//   sz = n;

//   // 画图模拟,倒数第二层最后下降一层,以此类推.
//   for(int i = n / 2; i; i--) down(i);

//   while(m--){
//     printf("%d ",heap[1]);
//     heap[1] = heap[sz];
//     sz--;
//     down(1);
//   }

//   return 0;
// }


// #include <iostream>
// #include <algorithm>
// using namespace std;

// const int N = 1e5 + 10;
// int heap[N];
// int n,m,sz;

// void down(int u){
//   int t = u;
  
//   if(sz >= 2 * u && heap[t] > heap[2*u]) t = 2 * u;
//   if(sz >= 2 * u + 1 && heap[t] > heap[2*u+1]) t = 2 * u + 1;
  
//   if(t != u){
//     swap(heap[t],heap[u]);
//     down(t);
//   }
// }

// int main(){
//   scanf("%d%d",&n,&m);

//   for(int i = 1;i <= n;i++){
//     scanf("%d",&heap[i]);
//   }

//   sz = n;

//   for(int i = sz / 2;i;i--) down(i); // 创建堆

//   while(m--){
//     printf("%d ",heap[1]);
//     heap[1] = heap[sz];
//     sz--;
//     down(1);
//   }

//   return 0;
// }

// #include <iostream>
// #include <algorithm>
// using namespace std;

// const int N = 1e5 + 10;
// int n,m,sz;
// int heap[N];

// void down(int u){
//   int t = u;
//   if(sz >= 2*u && heap[t] > heap[2*u]) t = 2*u;
//   if(sz >= 2*u+1 && heap[t] > heap[2*u+1]) t = 2*u+1;

//   if(t != u){
//     swap(heap[t],heap[u]);
//     down(t);
//   }
// }

// int main(){
//   scanf("%d%d",&n,&m);
//   sz = n;

//   for(int i = 1;i <= n;i++){
//     scanf("%d",&heap[i]);
//   }

//   for(int i = n / 2;i;i--) down(i);
  
//   while(m--){
//     printf("%d ",heap[1]);
//     heap[1] = heap[sz];
//     sz--;
//     down(1);
//   }

//   return 0;
// }


// #include <iostream>
// #include <algorithm>
// using namespace std;

// const int N = 1e5 + 10;
// int n,m,sz;
// int heap[N];

// void down(int u){
//   int t = u;
//   if(sz >= 2 * u && heap[t] > heap[2*u]) t = 2*u;
//   if(sz >= 2 * u + 1 && heap[t] > heap[2*u+1]) t = 2*u+1;
//   if(t != u){
//     swap(heap[t],heap[u]);
//     down(t);
//   }
// }

// int main(){
//   scanf("%d%d",&n,&m);
//   sz = n;

//   for(int i = 1;i <= n;i++) scanf("%d",&heap[i]);

//   for(int i = n / 2;i;i--) down(i);

//   while(m--){
//     printf("%d ",heap[1]);
//     heap[1] = heap[sz];
//     sz--;
//     down(1);
//   }
//   return 0;
// }


// #include <iostream>
// using namespace std;

// const int N = 1e5 + 10;
// int heap[N];
// int n,m;
// int sz;

// void down(int u){
//   int t = u;
//   if(u * 2 <= sz && heap[u*2] < heap[t]) t = u * 2;
//   if(u * 2 + 1 <= sz && heap[u*2+1] < heap[t]) t = u * 2 + 1;
//   if(t != u){
//     swap(heap[t],heap[u]);
//     down(t);
//   }
// }

// int main(){
//   scanf("%d%d",&n,&m);

//   sz = n;

//   for(int i = 1;i <= n;i++){
//     scanf("%d",&heap[i]);
//   } 

//   for(int i = n / 2;i;i--){ // 建立堆
//     down(i);
//   }

//   while(m--){
//     printf("%d ",heap[1]);
//     heap[1] = heap[sz];
//     sz--;
//     down(1);
//   }
//   return 0;
// }

/*
#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n,m,sz;
int heap[N];

void down(int u){
  int t = u;
  if(u * 2 <= sz && heap[u*2] < heap[t]) t = u * 2;
  if(u * 2 + 1 <= sz && heap[u*2+1] < heap[t]) t = u * 2 + 1;

  if(t != u){
    swap(heap[t],heap[u]);
    down(t);
  }
}

int main(){
  scanf("%d%d",&n,&m);
  sz = n;
  
  for(int i = 1;i <= n;i++){
    scanf("%d",&heap[i]);
  }

  for(int i = n / 2;i;i--) down(i);

  while(m--){
    printf("%d ",heap[1]);
    heap[1] = heap[sz];
    sz--;
    down(1);
  }

  return 0;
}
*/
#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n,m,sz;
int heap[N];

void down(int u){
  int t = u;
  if(u*2 <= sz && heap[u*2] < heap[t]) t = u * 2;
  if(u*2+1 <= sz && heap[u*2+1] < heap[t]) t = u * 2 + 1;
  
  if(u != t){
    swap(heap[u],heap[t]);
    down(t);
  }
}

int main(){
  scanf("%d%d",&n,&m);
  sz = n;
  for(int i = 1;i <= n;i++){
    scanf("%d",&heap[i]);
  }

  for(int i = n / 2;i;i--){
    down(i);
  }

  while(m--){
    printf("%d ",heap[1]);
    heap[1] = heap[sz];
    sz--;
    down(1);
  }

  return 0;
}