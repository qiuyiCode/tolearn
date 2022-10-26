// #include <iostream>
// #include <cstring>
// using namespace std;

// const int N = 1e5 + 10;

// int heap[N],ph[N],hp[N]; // ph[k]存的是往堆中插入的第k个数在堆中的下标是什么,hp[k]存的是堆中下标为k的数是往堆中插入的第几个数

// int n,sz;

// /*堆中两个数字交换,则这个位置对应的插入的数字次序改变,相应的插入的数字在堆中的下标也发生了改变
//   1.swap(hp[a],hp[b])

// */
// void heap_swap(int a,int b){
//   swap(ph[hp[a]],ph[hp[b]]); // 首先修改元素在堆中的下标
//   swap(hp[a],hp[b]); // 之后修改元素的插入次序
//   swap(heap[a],heap[b]);
// }

// void down(int u){
//   int min = u; // min为最小值下标
//   if(sz >= 2 * u && heap[min] > heap[2*u]) min = 2 * u;
//   if(sz >= 2 * u + 1 && heap[min] > heap[2*u+1]) min = 2 * u + 1;

//   if(min != u){
//     heap_swap(min,u);
//     down(min);
//   }
// }

// void up(int u){
//   while(u / 2 && heap[u] < heap[u/2]){
//     heap_swap(u,u/2);
//     u /= 2;
//   }
// }

// int main(){
//   scanf("%d",&n);
//   char op[3];

//   int m = 0;
//   while(n--){
//     scanf("%s",op);
//     if(!strcmp(op,"I")){
//       int x;
//       scanf("%d",&x);
//       sz++,m++; // 下标从1开始,先加再操作
//       heap[sz] = x;
//       hp[sz] = m,ph[m] = sz;
//       up(sz);
//     }else if(!strcmp(op,"PM")){
//       printf("%d\n",heap[1]);
//     }else if(!strcmp(op,"DM")){
//       heap_swap(1,sz);
//       sz--;
//       down(1);
//     }else if(!strcmp(op,"D")){
//       int k;
//       scanf("%d",&k);
//       k = ph[k];
//       heap_swap(sz,k); // 这一步之后ph[k]已经变化了,所以必须记录ph[k]
//       sz--;
//       down(k);
//       up(k);
//     }else{
//       int k,x;
//       scanf("%d%d",&k,&x);
//       k = ph[k];
//       heap[k] = x;
//       down(k),up(k);
//     }
//   }

//   return 0;
// }

// #include <iostream>
// #include <cstring>
// using namespace std;

// const int N = 1e5 + 10;
// int heap[N],hp[N],ph[N];
// int n,k_now;
// int sz;

// /*
//   ph[k]存的是往堆中插入的第k个数在堆中的下标是什么
//   hp[k]存的是堆中下标为k的数是往堆中插入的第几个数
// */

// void heap_swap(int a,int b){
//   // 先换一下两个数字在堆中存储的位置
//   swap(ph[hp[a]],ph[hp[b]]);
//   // 再换一下现在存储的位置是插入的第几个数字
//   swap(hp[a],hp[b]);
//   swap(heap[a],heap[b]);
// }

// void down(int u){
//   int t = u;
//   if(u * 2 <= sz && heap[u*2] < heap[t]) t = u * 2;
//   if(u * 2 + 1 <= sz && heap[u*2+1] < heap[t]) t = u * 2 + 1;

//   if(t != u){
//     heap_swap(t,u); // 上面的heap_swap已经实现了元素的交换,直接传入下标参数即可
//     down(t);
//   }
// }

// void up(int u){
//   while(u / 2 && heap[u] < heap[u / 2]){
//     heap_swap(u,u/2);
//     u /= 2; // u需要变化
//   }
// }

// int main(){
//   scanf("%d",&n);

//   char op[10];
//   int k,x;

//   while(n--){
//     scanf("%s",op);

//     if(!strcmp(op,"I")){
//       int x;
//       scanf("%d",&x);
//       sz++,k_now++;
//       heap[sz] = x;
//       hp[sz] = k_now;
//       ph[k_now] = sz;
//       up(sz); // 插入之后,需要维护堆结构
//     }else if(!strcmp(op,"PM")){
//       printf("%d\n",heap[1]);
//     }else if(!strcmp(op,"DM")){
//       heap_swap(1,sz);
//       sz--;
//       down(1);
//       up(1);
//     }else if(!strcmp(op,"D")){
//       int k;
//       scanf("%d",&k);
//       int c = ph[k];
//       heap_swap(c,sz);
//       sz--;
//       down(c);
//       up(c);
//     }else{
//       int k,x;
//       scanf("%d%d",&k,&x);
//       int c = ph[k];
//       heap[c] = x;
//       down(c);
//       up(c);
//     }
//   }
//   return 0;
// }


// #include <iostream>
// #include <cstring>
// using namespace std;

// const int N = 1e5 + 10;
// int heap[N],hp[N],ph[N];
// int n,m,sz;

// /*
//   hp存的是堆中下标为k的数是第几个插入的数
//   ph存的是堆中第k个插入的数的下标是多少
// */
// void heap_swap(int a,int b){
//   swap(ph[hp[a]],ph[hp[b]]);
//   swap(hp[a],hp[b]);
//   swap(heap[a],heap[b]);
// }

// void down(int u){
//   int t = u;
//   if(u * 2 <= sz && heap[t] > heap[u*2]) t = u * 2;
//   if(u * 2 + 1 <= sz && heap[t] > heap[u*2+1]) t = u * 2 + 1;
//   if(t != u){
//     heap_swap(t,u);
//     down(t);
//   }
// }

// void up(int u){
//   while(u / 2 && heap[u/2] > heap[u]){
//     heap_swap(u,u/2);
//     u /= 2;
//   }
// }

// int main(){
//   scanf("%d",&n);
//   char op[10];

//   while(n--){
//     scanf("%s",op);
//     if(!strcmp(op,"I")){
//       int x;
//       scanf("%d",&x);
//       sz++,m++;
//       heap[sz] = x;
//       ph[m] = sz;
//       hp[sz] = m;
//       up(sz);
//     }else if(!strcmp(op,"PM")){
//       printf("%d\n",heap[1]);
//     }else if(!strcmp(op,"DM")){
//       heap_swap(1,sz);
//       sz--;
//       down(1);
//     }else if(!strcmp(op,"D")){
//       int k;
//       scanf("%d",&k);
//       int c = ph[k]; // 要删除数字的下标
//       heap_swap(c,sz);
//       sz--;
//       down(c);
//       up(c);
//     }else{  
//       int k,x;
//       scanf("%d%d",&k,&x);
//       int c = ph[k];
//       heap[c] = x;
//       down(c);
//       up(c);
//     }
//   }
//   return 0;
// }

#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;
int n,sz,m;
int heap[N],hp[N],ph[N];

void heap_swap(int a,int b){
  swap(ph[hp[a]],ph[hp[b]]);
  swap(hp[a],hp[b]);
  swap(heap[a],heap[b]);
}

void down(int u){
  int t = u;
  if(u*2 <= sz && heap[u*2] < heap[t]) t = u * 2;
  if(u*2+1 <= sz && heap[u*2+1] < heap[t]) t = u*2+1;
  
  if(t != u){
    heap_swap(u,t);
    down(t);
  }
}

void up(int u){
  while(u / 2 && heap[u/2] > heap[u]){
    heap_swap(u,u/2);
    u /= 2;
  }
}

int main(){
  scanf("%d",&n);

  char op[5];

  while(n--){
    scanf("%s",op);
    if(!strcmp(op,"I")){
      int x;
      scanf("%d",&x);
      sz++,m++;
      heap[sz] = x;
      ph[m] = sz;
      hp[sz] = m;
      up(sz);
    }else if(!strcmp(op,"PM")){
      printf("%d\n",heap[1]);
    }else if(!strcmp(op,"DM")){
      heap_swap(1,sz);
      sz--;
      down(1);
    }else if(!strcmp(op,"D")){
      int k;
      scanf("%d",&k);
      int t = ph[k];
      heap_swap(t,sz);
      sz--;
      down(t);
      up(t);
    }else{
      int k,x;
      scanf("%d%d",&k,&x);
      int t = ph[k];
      heap[t] = x;
      down(t);
      up(t);
    }
  }
  return 0;
}
