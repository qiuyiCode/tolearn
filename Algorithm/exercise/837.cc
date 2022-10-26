// #include <iostream>
// #include <cstring>
// using namespace std;

// const int N = 1e5 + 10;
// int n,m,idx;
// int p[N],cnt[N];

// int find(int x){
//   if(p[x] != x) p[x] = find(p[x]);
//   return p[x];
// }

// int main(){
//   scanf("%d%d",&n,&m);
//   for(int i = 0;i < n;i++){
//      p[i] = i;
//      cnt[i] = 1;
//   }

//   char op[10];
//   int a,b;
//   while(m--){
//     scanf("%s",op);
//     if(!strcmp(op,"C")){ // 是两个集合合并,别总想成两个点

//       scanf("%d%d",&a,&b);
//       if(find(a) != find(b))
//         cnt[find(b)] += cnt[find(a)];
//       p[find(a)] = p[find(b)];

//     }else if(!strcmp(op,"Q1")){
//       scanf("%d%d",&a,&b);
//       if(find(a) == find(b)){
//         printf("Yes\n");
//       }else{
//         printf("No\n");
//       }
//     }else{
//       scanf("%d",&a);
//       printf("%d\n",cnt[find(a)]);
//     }
//   }

//   return 0;
// }



#include <cstring>
#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n,m;
int p[N];
int cnt[N];

int find(int x){
  if(p[x] != x) p[x] = find(p[x]);
  return p[x];
}

int main(){
  scanf("%d%d",&n,&m);

  for(int i = 0;i < n;i++){
    p[i] = i; // 将自身加入并查集
    cnt[i] = 1;
  }

  char op[10];
  int a,b;

  while (m--){
    scanf("%s",op);
    if(!strcmp(op,"C")){
      scanf("%d%d",&a,&b);  
      if(find(a) != find(b))
        cnt[find(b)] += cnt[find(a)];
      p[find(a)] = p[find(b)];
    }else if(!strcmp(op,"Q1")){
      scanf("%d%d",&a,&b);
      if(find(a) == find(b)){
        printf("Yes\n");
      }else{
        printf("No\n");
      }
    }else{
      scanf("%d",&a);
      printf("%d\n",cnt[find(a)]);
    }
  }

  return 0; 
}