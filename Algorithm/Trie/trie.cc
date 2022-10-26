// #include <iostream>
// using namespace std;

// /*Trie树:高效地存储和查找字符串集合的数据结构*/

// const int N = 1e5 + 10;
// int son[N][26],cnt[N],idx; // 下标是0的点,既是根节点,又是空节点
// char str[N];

// void insert(char str[]){ // 插入操作
//   int p = 0;
//   for(int i = 0; str[i]; i ++ ){
//     int u = str[i] - 'a';
//     if(!son[p][u]) son[p][u] = ++idx; // 有路就走过去,没有路建一条路也要走过去
//     p = son[p][u];
//   }
//   cnt[p]++;
// }

// int query(char str[]){
//   int p = 0;
//   for(int i = 0; str[i]; i ++ ){
//     int u = str[i] - 'a';
//     if(!son[p][u]) return 0;
//     p = son[p][u];
//   }
//   return cnt[p];
// }

// int main(){
//   int n;
//   scanf("%d",&n);
//   while(n--){
//     char op[2];
//     scanf("%s%s",op,str); // 会自动加入'\0'

//     if(op[0] == 'Q'){
//       printf("%d\n",query(str));
//     }else{
//       insert(str);
//     }
//   }
//   return 0;
// }


// #include <iostream>
// using namespace std;

// const int N = 1e5 + 10;
// int trie[N][26];
// int cnt[N];
// int idx;

// char str[N];

// void insert(char str[]){
//   int p = 0;
//   for(int i = 0; str[i]; i++){
//     int u = str[i] - 'a';
//     if(!trie[p][u]) trie[p][u] = ++idx;
//     p = trie[p][u];
//   }
//   cnt[p]++; // 单词个数 + 1
// }

// int query(char str[]){
//   int p = 0;
//   for(int i = 0; str[i]; i++){
//     int u = str[i] - 'a';
//     if(trie[p][u]) p = trie[p][u];
//     else return 0;
//   }
//   return cnt[p];
// }

// int main(){
//   int n;
//   scanf("%d",&n);
//   char op[2];
//   while(n--){
//     scanf("%s%s",op,str);
//     if(op[0] == 'I'){
//       insert(str);
//     }else{
//       printf("%d\n",query(str));
//     }
//   }

//   return 0;
// } 


// #include <iostream>
// using namespace std;

// const int N = 1e5 + 10;
// int trie[N][26],cnt[N];
// int n,idx;
// char str[N];

// void insert(char str[]){
//   int u = 0;
//   for(int i = 0;str[i];i++){
//     int p = str[i] - 'a';
//     if(!trie[u][p]) trie[u][p] = ++idx;
//     u = trie[u][p];
//   }
//   cnt[u]++;
// }

// int query(char str[]){
//   int u = 0;
//     for(int i = 0;str[i];i++){
//     int p = str[i] - 'a';
//     if(trie[u][p]) u = trie[u][p];
//     else return 0;
//   }
//   return cnt[u];
// }

// int main(){
//   scanf("%d",&n);
//   char op[2];

//   while(n--){
//     scanf("%s",op);
//     if(op[0] == 'I'){
//       scanf("%s",str);
//       insert(str);
//     }else{
//       scanf("%s",str);
//       printf("%d\n",query(str));
//     }
//   }
  
//   return 0;
// }



// #include <iostream>
// using namespace std;

// const int N = 1e5 + 10;
// int trie[N][26],cnt[N];
// int idx,n;
// char str[N];

// void insert(char s[]){
//   int u = 0;
//   for(int i = 0;s[i];i++){
//     int p = s[i] - 'a';
//     if(!trie[u][p]) trie[u][p] = ++idx;
//     u = trie[u][p];
//   }
//   cnt[u]++;
// }

// int query(char s[]){
//   int u = 0;
//   for(int i = 0;s[i];i++){
//     int p = s[i] - 'a';
//     if(trie[u][p]) u = trie[u][p];
//     else return 0;
//   }
//   return cnt[u];
// }

// int main(){
//   scanf("%d",&n);

//   char op[2];

//   while(n--){
//     scanf("%s",op);
//     if(op[0] == 'I'){
//       scanf("%s",str);
//       insert(str);
//     }
//     else{
//       scanf("%s",str);
//       printf("%d\n",query(str));
//     }
//   }
//   return 0;
// }



#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int trie[N][26];
int n,idx;
int cnt[N];

char str[N];

void insert(char str[]){
  int u = 0;
  for(int i = 0;str[i];i++){
    int t = str[i] - 'a'; // 用数字存储下每个字符
    if(!trie[u][t]) trie[u][t] = ++idx;
    u = trie[u][t];
  }
  cnt[u]++;
}

int query(char str[]){
  int u = 0;
  for(int i = 0;str[i];i++){
    int t = str[i] - 'a'; // 用数字存储下每个字符
    if(trie[u][t]) 
      u = trie[u][t];
    else{
      return 0;
    }
  }
  return cnt[u];
}

int main(){
  scanf("%d",&n);
  char op[2];
  while(n--){
    scanf("%s",op);
    if(*op == 'I'){
      scanf("%s",str);
      insert(str);
    }else{
      scanf("%s",str);
      printf("%d\n",query(str));
    }
  }

  return 0;
}
