#include <iostream>
using namespace std;
#define N 50010

int n,m;
int p[N],d[N];

int find(int x){
  if(x != p[x]){
    int t = find(p[x]);
    d[x] += d[p[x]];
    p[x] = t;
  } 
  return p[x];
}

int main(){
  scanf("%d%d",&n,&m);
  for(int i = 1;i <= n;i++) p[i] = i;

  // 假话的个数
  int res = 0; 

  while(m--){
    int t,x,y;
    scanf("%d%d%d",&t,&x,&y);

    if(x > n || y > n){ // 假话
      res++;
    }else{
      int px = find(x),py = find(y);
      if(t == 1){
        if(px == py && (d[x] - d[y]) % 3){ // 在同一个集合
          res++;
        }else if(px != py){ // 不在一个集合里
          p[px] = py;
          d[px] = d[y] - d[x];
        }
      }else{
        if(px == py && (d[x] - d[y] - 1) % 3){
          res++;
        }else if(px != py){
          p[px] = py;
          d[px] = d[y] + 1 - d[x];
        }
      }
    }
  }

  printf("%d\n",res);
  return 0;
}