/*并查集:
  1.将两个集合合并
  2.询问两个元素是否在同一个集合当中
*/

/*基本原理:
  每个集合用一棵树来表示,树根的编号就是整个集合的编号.
  每个节点存储其父节点,p[x]表示x的父节点.

  问题1:如何判断树根:if(p[x] == x)

  问题2:如何求x的集合编号:while(p[x] != x) x = p[x];
  优化:路径压缩,某条路径只需要找一次根节点,之后这条路径的所有子节点皆指向父节点

  问题3:如何合并两个集合:p[x]是x的集合编号,p[y]是y的集合编号.令p[x] = y或者p[y] = x;
*/
// #include <iostream>
// using namespace std;

// int n,m;
// const int N = 1e5 + 10;
// int p[N]; // 存储每个节点的父节点是谁

// int find(int x){ // 返回元素x的祖宗节点 + 路径压缩
//   if(p[x] != x) p[x] = find(p[x]);
//   return p[x];
// }

// int main(){
//   scanf("%d%d",&n,&m);

//   int a,b;
//   char str[2];

//   for(int i = 0; i < n; i++){
//     p[i] = i;
//   }

//   while(m--){
//     scanf("%s%d%d",str,&a,&b);

//     if(str[0] == 'M'){
//       p[find(a)] = find(b);
//     }else{
//       if(find(a) == find(b)){
//         cout << "Yes" << endl;
//       }else{
//         cout << "No" << endl;
//       }
//     }
//   }

//   return 0;
// }


// #include <iostream>
// using namespace std;

// const int N = 1e5 + 10;
// int n,m;
// int p[N];

// int find(int x){ // 查找x在哪个集合中,并做路径优化
//   if(p[x] != x) p[x] = find(p[x]);
//   return p[x];
// }

// int main(){
//   scanf("%d%d",&n,&m);
//   int a,b;
//   for(int i = 0;i < n;i++) p[i] = i; // 每个节点自成一个集合

//   char op[2];
//   while(m--){
//     scanf("%s%d%d",op,&a,&b);
//     if(op[0] == 'M'){
//       p[find(a)] = p[find(b)];
//     }else{
//       if(find(a) == find(b)) printf("Yes\n");
//       else printf("No\n");
//     }
//   }
//   return 0;
// }


// #include <iostream>
// using namespace std;

// const int N = 1e5 + 10;
// int p[N]; // 存储每棵树的根节点,代表一个集合
// int n,m;

// int find(int x){
//   if(p[x] != x) p[x] = find(p[x]); 
//   return p[x];
// }

// int main(){
//   scanf("%d%d",&n,&m);

//   for(int i = 0;i < n;i++)  p[i] = i;
    
//   char op[2];
//   int a,b;
//   while(m--){
//     scanf("%s%d%d",op,&a,&b);
    
//     if(op[0] == 'M'){
//       p[find(a)] = p[find(b)]; // 将根联系起来
//     }else{
//       if(find(a) == find(b))
//         printf("Yes\n");
//       else
//         printf("No\n");
//     }
//   }
//   return 0;
// }

/*
#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n,m;
int p[N];

int find(int x){
  if(p[x] != x) p[x] = find(p[x]);
  return p[x];
}

int main(){
  scanf("%d%d",&n,&m);

  for(int i = 0;i < n;i++) p[i] = i;

  char op[2];
  int a,b;
  while(m--){
    scanf("%s%d%d",op,&a,&b);

    if(op[0] == 'M'){
      p[find(a)] = p[find(b)];
    }
    else{
      if(find(a) == find(b))
        printf("Yes\n");
      else
        printf("No\n");
    }
  }

  return 0;
}
*/

#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int p[N];
int n,m;

int find(int u){
  if(p[u] != u) p[u] = find(p[u]);
  return p[u];
}

int main(){
  scanf("%d%d",&n,&m);

  for(int i = 0;i < n;i++) p[i] = i;

  char op[2];
  int a,b;
  while(m--){
    scanf("%s",op);
    if(*op == 'M'){
      scanf("%d%d",&a,&b);
      p[find(a)] = p[find(b)];
    }else{
      scanf("%d%d",&a,&b);
      if(p[find(a)] == p[find(b)]){
        printf("Yes\n");
      }else{
        printf("No\n");
      }
    }
  }

  return 0;
}






