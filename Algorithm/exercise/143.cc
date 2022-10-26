// #include <iostream>
// using namespace std;

// const int N = 1e5 + 10;
// const int M = 31 * N; // 为什么M = 31 * N ?  
// int trie[M][2];
// int n,idx;
// int q[N];

// void insert(int x){
//   int u = 0;
//   for(int i = 30;i >= 0;i--){ // 每个数字不超过31位,最多存储31位即可,从最高位开始存储
//     int c = x >> i & 1; // 这一位是0还是1 ?
//     if(!trie[u][c]) trie[u][c] = ++idx;
//     u = trie[u][c];
//   }
// }

// int search(int x){ // 从头开始找与x异或最长的串
//   int cnt = 0;
//   int u = 0;
//   for(int i = 30;i >= 0;i--){
//     int c = x >> i & 1;
    
//     if(trie[u][!c]){  // 异或位存在
//        cnt = 1 + cnt * 2; // 跟十进制计算一样,计算当前的异或值
//        u = trie[u][!c];
//     }
//     else{ // 异或位不存在,只能选择另一个分支继续查找并计算,既然前面已经匹配了,所以不用担心后面的分支出现空白
//       cnt = cnt * 2 + 0;
//       u = trie[u][c];
//     } 
//   }
//   return cnt; // 返回最终的异或值
// }

// int main(){ 
//   scanf("%d",&n);
  
//   for(int i = 0;i < n;i++){
//     scanf("%d",&q[i]);
//     insert(q[i]);
//   }

//   int c = 0;
//   for(int i = 0;i < n;i++){
//     c = max(c,search(q[i])); // 每次判断最大值
//   }

//   printf("%d",c);
// }   


// #include <iostream>
// using namespace std;

// const int N = 1e5 + 10,M = 31 * N;
// int trie[M][2];
// int idx;
// int p[N];

// void insert(int x){
//   int u = 0;
//   for(int i = 30;i >= 0;i--){ // 每个数字最大不超过31位,所以为每个数字都保存31位
//     int c = x >> i & 1;
//     if(!trie[u][c]) trie[u][c] = ++idx;
//     u = trie[u][c];
//   }
// }

// int search(int x){
//   int u = 0,res = 0;
//   for(int i = 30;i >= 0;i--){
//     int c = x >> i & 1;
//     if(trie[u][!c]){
//       res = res * 2 + 1; // 注意这里不是res += res * 2 + 1
//       u = trie[u][!c];
//     }else{ // 前面都已经匹配上了,所以不用担心分支不存在的情况
//       res *= 2;
//       u = trie[u][c];
//     }
//   }
//   return res;
// }


// int main(){
//   int n;
//   scanf("%d",&n);

//   for(int i = 0;i < n;i++){
//     scanf("%d",&p[i]);
//     insert(p[i]);   
//   }

//   int res = 0;
//   for(int i = 0;i < n;i++){
//     res = max(res,search(p[i]));
//   }

//   printf("%d",res);

//   return 0;
// }


#include <iostream>
using namespace std;

const int N = 1e5 + 10;
const int M = N * 31;

int trie[M][2],q[N];
int n,idx;

void insert(int u){
  int p = 0;
  for(int i = 30;i >= 0;i--){
    int c = u >> i & 1;
    if(!trie[p][c]) trie[p][c] = ++idx;
    p = trie[p][c];
  }
}

int search(int u){
  int p = 0,t = 0;
  for(int i = 30;i >= 0;i--){
    int c = u >> i & 1;
    if(trie[p][!c]){
      t = t * 2 + 1;
      p = trie[p][!c]; 
    }else{
      t = t * 2;
      p = trie[p][c];
    }
  }
  return t;
}

int main(){
  scanf("%d",&n);
  for(int i = 0;i < n;i++){
    scanf("%d",&q[i]);
    insert(q[i]);
  }

  int res = 0;
  for(int i = 0;i < n;i++){
    res = max(res,search(q[i]));
  }

  printf("%d",res);
  return 0;
}



