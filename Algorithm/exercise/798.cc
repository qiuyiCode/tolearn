// #include <iostream>
// using namespace std;

// const int N = 1010;
// int n,m,q;
// int s[N][N],a[N][N];

// void insert(int x1,int y1,int x2,int y2,int c){
//     a[x1][y1] += c;
//     a[x2+1][y1] -= c;
//     a[x1][y2+1] -= c;
//     a[x2+1][y2+1] += c;
// }

// int main(){
//     scanf("%d%d%d",&n,&m,&q);

//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= m;j++){
//             scanf("%d",&s[i][j]);
//         }
//     }

//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= m;j++){
//             insert(i,j,i,j,s[i][j]);
//         }
//     }

//     while(q--){
//         int x1,y1,x2,y2,c;
//         scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&c);
//         insert(x1,y1,x2,y2,c);
//     }

//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= m;j++){
//             a[i][j] = a[i][j] + a[i][j-1] + a[i-1][j] - a[i-1][j-1];
//         }
//     }

//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= m;j++){
//             cout << a[i][j] << ' ';
//         }
//         cout << endl;
//     }
//     return 0;
// }


// #include <iostream>
// using namespace std;

// int n,m,q;
// const int N = 1010;
// int a[N][N],s[N][N];

// void insert(int x1,int y1,int x2,int y2,int c){
//     s[x1][y1] += c;
//     s[x1][y2+1] -= c;
//     s[x2+1][y1] -=c;
//     s[x2+1][y2+1] += c;
// }

// /*a是原矩阵(即前缀和矩阵),s是差分矩阵,最后得结果是s操作完成后求前缀和*/

// int main(){
//     scanf("%d%d%d",&n,&m,&q);
//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= m;j++){
//             scanf("%d",&a[i][j]);
//         }
//     }

//     // 构造差分二维矩阵s
//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= m;j++){
//             insert(i,j,i,j,a[i][j]);
//         }
//     }

//     while(q--){
//         int x1,y1,x2,y2,c;
//         scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&c);
//         insert(x1,y1,x2,y2,c);
//     }

//     // 还原差分矩阵操作后的原矩阵
//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= m;j++){
//             a[i][j] = s[i][j] + a[i-1][j] + a[i][j-1] - a[i-1][j-1];
//         }
//     }

//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= m;j++){
//             printf("%d ",a[i][j]);
//         }
//         putc('\n',stdout);
//     }
// }

// #include <iostream>
// using namespace std;

// int n,m,q;
// const int N = 1010;
// int a[N][N],s[N][N];

// void insert(int x1,int y1,int x2,int y2,int c){
//     a[x1][y1] += c;
//     a[x1][y2+1] -= c;
//     a[x2+1][y1] -=c;
//     a[x2+1][y2+1] += c;
// }

// /*a是原矩阵(即前缀和矩阵),s是差分矩阵,最后得结果是s操作完成后求前缀和*/

// int main(){
//     scanf("%d%d%d",&n,&m,&q);
//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= m;j++){
//             scanf("%d",&s[i][j]);
//         }
//     }

//     // 构造差分二维矩阵s
//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= m;j++){
//             insert(i,j,i,j,s[i][j]);
//         }
//     }

//     while(q--){
//         int x1,y1,x2,y2,c;
//         scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&c);
//         insert(x1,y1,x2,y2,c);
//     }

//     // 还原差分矩阵操作后的原矩阵
//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= m;j++){
//             s[i][j] = a[i][j] + s[i-1][j] + s[i][j-1] - s[i-1][j-1];
//         }
//     }

//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= m;j++){
//             printf("%d ",s[i][j]);
//         }
//         putc('\n',stdout);
//     }
// }



#include <iostream>
using namespace std;

const int N = 1010;
int a[N][N],s[N][N];
int n,m,q;

void insert(int x1,int y1,int x2,int y2,int c){
  a[x1][y1] += c;
  a[x1][y2+1] -= c;
  a[x2+1][y1] -= c;
  a[x2+1][y2+1] += c;
}

int main(){
  scanf("%d%d%d",&n,&m,&q);
  for(int i = 1;i <= n;i++){
    for(int j = 1;j <= m;j++){
      scanf("%d",&s[i][j]);
      insert(i,j,i,j,s[i][j]);
    }
  }

  int l1,r1,l2,r2,c;
  while(q--){
    scanf("%d%d%d%d%d",&l1,&r1,&l2,&r2,&c);
    insert(l1,r1,l2,r2,c);
  } 

  for(int i = 1;i <= n;i++){
    for(int j = 1;j <= m;j++){
      s[i][j] = a[i][j] + s[i][j-1] + s[i-1][j] - s[i-1][j-1];
    }
  }

  for(int i = 1;i <= n;i++){
    for(int j = 1;j <= m;j++){
      printf("%d ",s[i][j]);
    }
    printf("\n");
  }

  return 0;
}