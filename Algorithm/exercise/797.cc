// #include <iostream>
// using namespace std;

// int n,m;
// const int N = 1e5 + 10;
// int s[N],a[N];

// void insert(int l,int r,int c){
//     a[l] += c;
//     a[r+1] -= c;
// }

// int main(){
//     scanf("%d%d",&n,&m);

//     for(int i = 1;i <= n;i++){
//         scanf("%d",&s[i]);
//     }

//     for(int i = 1;i <= n;i++){
//         insert(i,i,s[i]);
//     }

//     while(m--){
//         int l,r,c;
//         scanf("%d%d%d",&l,&r,&c);
//         insert(l,r,c);
//     }

//     for(int i = 1;i <= n;i++){
//         a[i] = a[i] + a[i-1];
//     }

//     for(int i = 1;i <= n;i++){
//         printf("%d ",a[i]);
//     }
//     return 0;
// }



// #include <iostream>
// using namespace std;

// int n,m;
// const int N = 1e5 + 10;
// int a[N],s[N];

// void insert(int i,int j,int x){
//     s[i] += x;
//     s[j+1] -= x; // [i,j]范围都需要+
// }

// int main(){
//     scanf("%d%d",&n,&m);

//     for(int i = 1;i <= n;i++){
//         scanf("%d",&a[i]);
//     }

//     for(int i = 1;i <= n;i++) insert(i,i,a[i]); //创建差分序列

//     while(m--){
//         int l,r,c;
//         scanf("%d%d%d",&l,&r,&c);
//         insert(l,r,c);
//     }

//     for(int i = 1;i <= n;i++){
//         a[i] = a[i-1] + s[i]; // 恢复原序列
//     }


//     for(int i = 1;i <= n;i++){
//         printf("%d ",a[i]);
//     }

//     return 0;
// }


// #include <iostream>
// using namespace std;

// int n,m;
// const int N = 1e5 + 10;
// int a[N],s[N];

// void insert(int i,int j,int x){
//     a[i] += x;
//     a[j+1] -= x; // [i,j]范围都需要+
// }

// int main(){
//     scanf("%d%d",&n,&m);

//     for(int i = 1;i <= n;i++){
//         scanf("%d",&s[i]);
//     }

//     for(int i = 1;i <= n;i++) insert(i,i,s[i]); //创建差分序列

//     while(m--){
//         int l,r,c;
//         scanf("%d%d%d",&l,&r,&c);
//         insert(l,r,c);
//     }

//     for(int i = 1;i <= n;i++){
//         s[i] = s[i-1] + a[i]; // 恢复原序列
//     }


//     for(int i = 1;i <= n;i++){
//         printf("%d ",s[i]);
//     }

//     return 0;
// }


#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int a[N],s[N];
int n,m;

void insert(int l,int r,int c){
  a[l] += c;
  a[r+1] -= c;
}

int main(){
  scanf("%d%d",&n,&m);

  for(int i = 1;i <= n;i++){
    scanf("%d",&s[i]);
  }
  
  for(int i = 1;i <= n;i++) insert(i,i,s[i]); // 求差分序列

  int l,r,c;
  while(m--){
    scanf("%d%d%d",&l,&r,&c);
    insert(l,r,c);
  }

  for(int i = 1;i <= n;i++){
    s[i] = s[i-1] + a[i];
  }

  for(int i = 1;i <= n;i++){
    printf("%d ",s[i]);
  }

  return 0;
}