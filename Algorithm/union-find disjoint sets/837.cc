/*#include <iostream>
using namespace std;

int n,m;
const int N = 1e5 + 10;
int p[N],sz[N];

int find(int x){
  if(p[x] != x) p[x] = find(p[x]);
  return p[x];
}

int main(){
  scanf("%d%d",&n,&m);
  int a,b;
  char str[3];

  for(int i = 0; i < n; i++){
    p[i] = i;
    sz[i] = 1; // 最初的集合中只有一个点
  }

  while(m--){
    scanf("%s",str);

    if(str[0] == 'C'){
      scanf("%d%d",&a,&b);
      if(find(a) == find(b)) continue;
      sz[find(b)] += sz[find(a)];
      p[find(a)] = find(b);
    }else if(str[1] == '1'){
      scanf("%d%d",&a,&b);
      if(find(a) == find(b)){
        cout << "Yes" << endl;
      }else{
        cout << "No" << endl;
      }
    }else{
      scanf("%d",&a);
      printf("%d\n",sz[find(a)]);
    }
  }

  return 0;
}
*/

#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;
int p[N],cnt[N];
int n,m;


int find(int x){
  if(p[x] != x) p[x] = find(p[x]);
  return p[x];
}

int main(){
  scanf("%d%d",&n,&m);

  for(int i = 0;i < n;i++){
    p[i] = i;
    cnt[i] = 1; // 当集合中只有一个元素,次数为1
  }
  
  char op[10];
  int a,b;
  while(m--){
    scanf("%s",op);

    if(!strcmp(op,"C")){
      scanf("%d%d",&a,&b);
      if(find(a) != find(b)){ // 只要连到同一个父节点,则在同一个并查集中
        cnt[find(b)] += cnt[find(a)];
        p[find(a)] = p[find(b)];
      }else{
        continue;
      }
    }else if(!strcmp(op,"Q1")){
        scanf("%d%d",&a,&b);
        if(p[find(a)] == p[find(b)]){
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
