#include <iostream>
using namespace std;

const int K = 1e5 + 10;
const int N = 5e4 + 10;
int k,n;
int p[K],q[K];
int count;

// 建立共存同类并查集
int find_tl(int x){
  if(x != p[x]) p[x] = find_tl(p[x]);
  return p[x];
}

// 建立食物链捕食并查集
int find_bs(int x){
  if(x != q[x]) q[x] = find_bs(q[x]);
  return q[x];
}

int main(){
  scanf("%d%d",&n,&k);
  int D,X,Y;

  for(int i = 0;i < n;i++){  // 建立初始并查集
    p[i] = i;
    q[i] = i;
  } 

  while(k--){
    scanf("%d%d%d",&D,&X,&Y);
    if(X > N || Y > N){ // X或者Y比N大,假话
      count++;
      continue;
    }

    if(D == 1){  // X和Y是同类

      if(X == Y && find_tl(X) != find_tl(Y)){
        continue;
      }

      if(find_bs(X) == find_bs(Y)){ // 找到了食物链关系,和前面的话冲突,假话
        count++;
        continue;
      }

      p[find_tl(X)] = find_tl(Y);
    }else{
      // X吃Y
      if(X == Y){ // X吃X,假话
        count++;
        continue;
      }

      if(find_tl(X) == find_tl(Y)){ // 找到了同类关系,和前面的话冲突,假话
        count++;
        continue;
      }

      q[find_bs(X)] = find_bs(Y);
    }
  }

  printf("%d",count);
}