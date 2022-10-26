// #include <iostream>
// using namespace std;
// /*用数组模拟链表*/

// // head 表示的是头结点的下标
// // e[i] 表示的是节点i的值
// // ne[i] 表示的是节点i的next指针
// // idx 存储已经用到了哪个点

// const int N = 1e5 + 10;
// int head,e[N],ne[N],idx;

// // 初始化
// void init(){
//     head = -1; 
//     idx = 0;
// }

// // 将x插到头节点后
// void add_to_head(int x){
//     e[idx] = x;
//     ne[idx] = head; // 用数组模拟链表,head存储的是头结点所在的数组下标
//     head = idx;
//     idx++;
// }

// // 将x插到第k个点后面
// void add(int k,int x){
//     e[idx] = x;
//     ne[idx] = ne[k];
//     ne[k] = idx;
//     idx++;
// }

// // 将下标是k的点的后一个元素删掉
// void remove(int k){
//     ne[k] = ne[ne[k]];
// }

// int main(){
//     int m;
//     cin >> m;
//     init();
//     while(m--){
//         int k,x;
//         char op;
//         cin >> op;
//         if(op == 'H'){
//             cin >> x;
//             add_to_head(x);
//         }else if(op == 'D'){
//             cin >> k;
//             if(!k)
//                 head = ne[head];
//             else
//                 remove(k-1);
//         }else{
//             cin >> k >> x;
//             add(k-1,x);
//         }
//     }

//     for(int i = head;i != -1;i = ne[i]){
//         cout << e[i] << ' ';
//     }
//     cout << endl;
//     return 0;
// }


// #include <iostream>
// using namespace std;

// const int N = 1e5 + 10;
// int head,idx;
// int e[N],ne[N]; // e[N]保存链表中的真实数据,ne[N]维护链表的next位置
// int m;

// void init(){
//     head = -1; // head保存的是头结点的位置
//     idx = 0;
// }

// // 向链表头插入一个数字
// void add_to_head(int x){
//     e[idx] = x;
//     ne[idx] = head; // 头结点转让
//     head = idx; 
//     idx++;
// }

// // 在k的位置后面添加一个x
// void add(int k,int x){
//     e[idx] = x;
//     ne[idx] = ne[k];
//     ne[k] = idx;
//     idx++;
// }

// // 删除位置k后的一个数字
// void remove(int k){
//     ne[k] = ne[ne[k]];
// }

// int main(){
//     cin >> m;
//     init();
//     while(m--){
//         char op;
//         int k,x;
//         cin >> op;
//         if(op == 'H'){
//             cin >> x;
//             add_to_head(x);
            
//         }else if(op == 'D'){
//             cin >> k;
//             if(!k)
//                 head = ne[head];
//             else
//                 remove(k-1);
//         }else{
//             cin >> k >> x;
//             add(k-1,x);
//         }
//     }

//     for(int i = head;i != -1;i = ne[i]){
//         cout << e[i] << ' ';
//     }
//     return 0;
// }


// #include <iostream>
// using namespace std;

// const int N = 1e5 + 10;

// int m;
// int e[N],ne[N]; // ne用来存储链表的指针
// int idx,head;

// void init(){
//     idx = 1;
//     ne[0] = -1; // 直接将第一个元素作为头指针
// }

// void add(int k,int x){
//     e[idx] = x;
//     ne[idx] = ne[k];
//     ne[k] = idx;
//     idx++;
// }

// void remove(int k){
//     ne[k] = ne[ne[k]];
// }

// int main(){
//     cin >> m;

//     init();

//     for(int i = 0;i < m;i++){
//         char op;
//         int k,x;
//         cin >> op;

//         if(op == 'H'){
//             cin >> x;
//             add(0,x);
//         }else if(op == 'D'){
//             cin >> k;
//             remove(k);
//         }else{
//             cin >> k >> x;
//             add(k,x);
//         }
//     }

//     for(int i = ne[0];i != -1;i = ne[i]){
//         cout << e[i] << ' ';
//     }

//     return 0;
// }


// #include <iostream>
// using namespace std;

// int m; // 操作次数
// const int N = 1e5 + 10;
// int e[N],ne[N]; // 分别为元素数组和指针数组

// int head;
// int idx;

// void init(){
//   head = -1;
//   idx = 0;
// }

// void add_to_head(int x){
//   e[idx] = x;
//   ne[idx] = head;
//   head = idx;
//   idx++;
// }

// // 在位置k后加入元素x
// void add(int k,int x){
//   e[idx] = x;
//   ne[idx] = ne[k];
//   ne[k] = idx;
//   idx++;
// }

// // 删除位置k后的元素
// void remove(int k){
//   ne[k] = ne[ne[k]];
// }


// int main(){
//   init();
//   char c;
//   int x,k;
//   cin >> m;
 
//   while(m--){
//     cin >> c;
//     if(c == 'H'){
//       cin >> x;
//       add_to_head(x);
//     }else if(c == 'D'){
//       cin >> k;
//       if(k == 0)
//         head = ne[head];
//       else
//         remove(k-1);
//     }else{
//       cin >> k >> x; // 这里的输入需要符合题目要求
//       add(k-1,x);
//     }
//   }
  
//   for(int i = head;i != -1;i = ne[i]){
//     cout << e[i] << ' ';
//   }

//   return 0;
// }

// #include <iostream>
// using namespace std;

// int m; // 操作次数
// const int N = 1e5 + 10;
// int e[N],ne[N]; // 分别为元素数组和指针数组

// int head;
// int idx;

// void init(){
//   ne[0] = -1;
//   idx = 1;
// }

// // 在位置k后加入元素x
// void add(int k,int x){
//   e[idx] = x;
//   ne[idx] = ne[k];
//   ne[k] = idx;
//   idx++;
// }

// // 删除位置k后的元素
// void remove(int k){
//   ne[k] = ne[ne[k]];
// }

// int main(){
//   init();
//   char c;
//   int x,k;
//   cin >> m;
 
//   while(m--){
//     cin >> c;
//     if(c == 'H'){
//       cin >> x;
//       add(0,x);
//     }else if(c == 'D'){
//       cin >> k;
//       remove(k);
//     }else{
//       cin >> k >> x; // 这里的输入需要符合题目要求
//       add(k,x);
//     }
//   }
  
//   for(int i = ne[0];i != -1;i = ne[i]){
//     cout << e[i] << ' ';
//   }

//   return 0;
// }


#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int m;
int e[N],ne[N];
int idx;

void init(){
  ne[0] = -1; // 加入头结点,统一头结点的一些操作
  idx = 1;
}

void insert(int k,int x){ 
  e[idx] = x;
  ne[idx] = ne[k];
  ne[k] = idx;
  idx++;
}

void remove(int k){
  ne[k] = ne[ne[k]];
}

int main(){
  int k,x;
  scanf("%d",&m);
  char op[5];
  init();
  while(m--){
    scanf("%s",op);
    if(*op == 'H'){
      int x;
      scanf("%d",&x);
      insert(0,x);
    }else if(*op == 'D'){
      int k;
      scanf("%d",&k);
      remove(k);
    }else{
      int k,x;
      scanf("%d%d",&k,&x);
      insert(k,x);
    }
  }

  for(int i = ne[0];i != -1;i = ne[i]){
    printf("%d ",e[i]);
  }
  return 0;
}