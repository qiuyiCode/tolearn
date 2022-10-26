// #include <iostream>
// using namespace std;

// int n,m,q;
// const int N = 1010;
// int a[N][N],s[N][N];

// int main(){
//     scanf("%d%d%d",&n,&m,&q);

//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= m;j++){
//             scanf("%d",&a[i][j]);
//         }
//     }

//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= m;j++){
//             s[i][j] = a[i][j] + s[i][j-1] + s[i-1][j] - s[i-1][j-1]; // 画图推导,用a[i][j]推导
//         }
//     }

//     while(q--){
//         int x1,y1,x2,y2;
//         scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
//         int rst = s[x2][y2] - s[x1-1][y2] - s[x2][y1-1] + s[x1-1][y1-1]; // s[x][y]只包含同行、同列以及左上方的元素
//         cout << rst << endl;
//     }
//     return 0;
// }



// #include <iostream>
// using namespace std;

// int n,m,q;
// const int N = 1010;
// int a[N][N],s[N][N];

// int main(){
//     scanf("%d%d%d",&n,&m,&q);

//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= m;j++){
//             scanf("%d",&a[i][j]);
//             s[i][j] = a[i][j] + s[i-1][j] + s[i][j-1] -s[i-1][j-1]; // 创建二维前缀和
//         }
//     }

//     while(q--){
//         int x1,y1,x2,y2;
//         scanf("%d%d%d%d",&x1,&y1,&x2,&y2);

//         printf("%d\n",s[x2][y2] - s[x1-1][y2] - s[x2][y1-1] + s[x1-1][y1-1]); // 通过图像计算前缀和
//     }
//     return 0;
// }


#include <iostream>
using namespace std;

int n,m,q;
const int N = 1010,M = 1010;
int a[N][M],s[N][M];

int main(){
  scanf("%d%d%d",&n,&m,&q);

  for(int i = 1;i <= n;i++){
    for(int j = 1;j <= m;j++){
      scanf("%d",&a[i][j]);
      s[i][j] = a[i][j] + s[i][j-1] + s[i-1][j] - s[i-1][j-1];
    }
  }

  int x1,y1,x2,y2;
  while(q--){
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    printf("%d\n",s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1]);
  }

  return 0;
}