// #include <iostream>
// using namespace std;

// const int N = 1e5 + 10;
// int e[N],l[N],r[N],idx;
// int m;

// // 初始化
// void init(){
//     // 0 表示左端点
//     // 1 表示右端点
//     r[0] = 1;
//     l[1] = 0;
//     idx = 2;
// }

// // 在位置k的后面添加一个元素x
// void add(int k,int x){
//     // e[idx] = x;
//     // r[idx] = r[k];
//     // l[idx] = k;
//     // r[k] = idx; // 这里更改了r[k],影响了下面的l[r[k]]
//     // l[r[k]] = idx;
//     // idx++;
//     e[idx] = x;
//     l[idx] = k;
//     r[idx] = r[k];
//     l[r[k]] = idx;
//     r[k] = idx;
//     idx++;
// }

// // 删除第k个点
// void remove(int k){
//     r[l[k]] = r[k];
//     l[r[k]] = l[k];
// }

// int main(){
//     cin >> m;

//     init();

//     while(m--){
//         string op;
//         int k,x;
//         cin >> op;
//         if(op == "L"){
//             cin >> x;
//             add(0,x);
//         }else if(op == "R"){
//             cin >> x;
//             add(l[1],x);
//         }else if(op == "D"){
//             cin >> k;
//             remove(k+1);
//         }else if(op == "IL"){
//             cin >> k >> x;
//             add(l[k+1],x);
//         }else{
//             cin >> k >> x;
//             add(k+1,x);
//         }
//     }

//     for(int i = r[0];i != 1;i = r[i]){
//         cout << e[i] << ' ';
//     }

//     return 0;
// }

// #include <iostream>
// using namespace std;

// const int N = 1e5 + 10;
// int l[N],r[N]; // 分别维护左链表与右链表
// int e[N]; // 元素数组
// int idx;
// int m;

// void init(){
//     l[1] = 0; // 尾节点
//     r[0] = 1; // 头节点
//     idx = 2;
// }

// // 往k位置后添加一个元素
// void add(int k,int x){
//     e[idx] = x;
//     r[idx] = r[k];
//     l[idx] = l[r[k]];
//     l[r[k]] = idx;
//     r[k] = idx;
//     idx++;
// }

// // 删除第k个元素,单链表没有前项,所以不能删除第k个
// void remove(int k){
//     r[l[k]] = r[k];
//     l[r[k]] = l[k];
// }


// int main(){
//     cin >> m;
//     init();
//     while(m--){
//         string op;
//         int k,x;

//         cin >> op;
//         if(op == "L"){
//             cin >> x;
//             add(0,x);
//         }else if(op == "R"){
//             cin >> x;
//             add(l[1],x); 
//         }else if(op == "D"){
//             cin >> k;
//             remove(k+1);
//         }else if(op == "IL"){
//             cin >> k >> x;
//             add(l[k+1],x);
//         }else{
//             cin >> k >> x;
//             add(k+1,x);
//         }
//     }

//     for(int i = r[0];i != 1;i = r[i]){
//         cout << e[i] << ' ';
//     }

//     return 0;
// }


// #include <iostream>
// using namespace std;

// int m;
// const int N = 1e5 + 10;
// int idx;
// int e[N];
// int l[N],r[N];

// void init(){
//     r[0] = 1; // 头节点
//     l[1] = 0; // 尾节点
//     idx = 2;
// }

// void add(int k,int x){
//     e[idx] = x;
//     r[idx] = r[k];
//     l[idx] = l[r[k]];
//     l[r[k]] = idx;
//     r[k] = idx;
//     idx++;
// }

// void remove(int k){
//     r[l[k]] = r[k];
//     l[r[k]] = l[k];
// }

// int main(){
//     init();
//     string s;
    
//     scanf("%d",&m);

//     while(m--){
//         cin >> s;
//         if(s == "L"){
//             int x;
//             cin >> x;
//             add(0,x);
//         }else if(s == "R"){
//             int x;
//             cin >> x;
//             add(l[1],x);
//         }else if(s == "D"){
//             int k;
//             cin >> k;
//             remove(k+1);
//         }else if(s == "IL"){
//             int k,x;
//             cin >> k >> x;
//             add(l[k+1],x);
//         }else{
//             int k,x;
//             cin >> k >> x;
//             add(k+1,x);
//         }
//     }

//     for(int i = r[0];i != 1;i = r[i]){
//         cout << e[i] << ' ';
//     }

//     return 0;
// }


#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;
int m,idx;
int e[N],l[N],r[N];

void init(){
  idx = 2;
  l[1] = 0;
  r[0] = 1;
}

void insert(int k,int x){
  e[idx] = x;
  r[idx] = r[k];
  l[idx] = l[r[k]];
  l[r[k]] = idx;
  r[k] = idx;
  idx++;
} 

void remove(int k){
  r[l[k]] = r[k];
  l[r[k]] = l[k];
}

int main(){
  init();
  scanf("%d",&m);

  char op[10];
  while(m--){
    scanf("%s",op);
    if(!strcmp(op,"L")){
      int x;
      scanf("%d",&x);
      insert(0,x); // 这里不能是r[0],r[0]是链表中第一个元素,insert是将元素插入到k位置后面,0位置是头结点,insert(0,x)即为向头结点后插入一个元素
    }else if(!strcmp(op,"R")){
      int x;
      scanf("%d",&x);
      insert(l[1],x);
    }else if(!strcmp(op,"D")){
      int k;
      scanf("%d",&k);
      remove(k+1);
    }else if(!strcmp(op,"IL")){
      int k,x;
      scanf("%d%d",&k,&x);
      insert(l[k+1],x); // 这里不能是k,因为是链表,需要用链找到上一个元素
    }else{
      int k,x;
      scanf("%d%d",&k,&x);
      insert(k+1,x);
    }
  }

  for(int i = r[0];i != 1;i = r[i]){
    printf("%d ",e[i]);
  }

  return 0;
}