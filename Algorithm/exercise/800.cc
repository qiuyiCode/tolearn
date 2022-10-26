// #include <iostream>
// using namespace std;

// const int N = 1e5 + 10;
// int n,m,x;
// int A[N],B[N];

// int find(int arr[],int l,int r,int x){
//     while(l < r){
//         int mid = (l + r + 1) >> 1;
//         if(arr[mid] < x) l = mid;
//         else r = mid - 1;
//     }
//     return l;
// }

// int find1(int l,int r,int x){
//     while(l <= r && B[l] != x){
//         int mid = l + r + 1 >> 1;
//         if(B[mid] <= x) l = mid;
//         else r = mid - 1;
//     }
//     if(l == r) return l;
//     else return -1;
// }

// int main(){
//     scanf("%d%d%d",&n,&m,&x);

//     for(int i = 0;i < n;i++){
//         scanf("%d",&A[i]);
//     }

//     for(int j = 0;j < m;j++){
//         scanf("%d",&B[j]);
//     }

//     // 分别找到A,B第一个小于x的数的位置
//     int A_r = find(A,0,n,x);
//     int B_r = find(B,0,m,x);
//     // cout << A_r << ' ' << B_r << endl;

//     for(int i = A_r;i >= 0;i--){
//         int B_find_sub = x - A[i];
//         int res = find1(0,B_r,B_find_sub);
//         if(res != -1){ // 找到了
//             cout << i << ' ' << res << endl;
//             break;
//         }else{
//             continue;
//         }
//     }
//     return 0;
// }

// #include <iostream>
// using namespace std;

// const int N = 1e5 + 10;
// int n,m,x;
// int A[N],B[N];

// int main(){
//     scanf("%d%d%d",&n,&m,&x);

//     for(int i = 0;i < n;i++){
//         scanf("%d",&A[i]);
//     }

//     for(int j = 0;j < m;j++){
//         scanf("%d",&B[j]);
//     }

    
//     for(int i = 0,j = m - 1;i < n;i++){ // 双指针
//         while(j >= 0 && A[i] + B[j] > x) j--;
        
//         if(j >= 0 && A[i] + B[j] == x)
//             cout << i << ' ' << j << endl;
//     }
//     return 0;
// }

// #include <iostream>
// using namespace std;

// int n,m,x;

// const int N = 1e5 + 10;
// int A[N],B[N];

// int main(){
//     scanf("%d%d%d",&n,&m,&x);

//     for(int i = 0;i < n;i++){
//         cin >> A[i];
//     }

//     for(int j = 0;j < m;j++){
//         cin >> B[j];
//     }

//     int j = m - 1;
//     for(int i = 0;i < n;i++){
//         while(j >= 0 && A[i] + B[j] > x) j--;

//         if(A[i] + B[j] == x)
//             cout << i << ' ' << j << endl;
//     }

//     return 0;
// }


// #include <iostream>
// using namespace std;

// int n,m,x;
// const int N = 1e5 + 10;
// int A[N],B[N];

// int main(){
//     scanf("%d%d%d",&n,&m,&x);

//     for(int i = 0;i < n;i++){
//         scanf("%d",&A[i]);
//     }

//     for(int i = 0;i < m;i++){
//         scanf("%d",&B[i]);
//     }

//     int j = m-1;
//     for(int i = 0;i < n;i++){
//         while(j >= 0 && A[i] + B[j] > x) j--;

//         if(A[i] + B[j] == x){
//             printf("%d %d",i,j);
//         }
//     }

//     return 0;
// }

// #include <iostream>
// using namespace std;

// const int N = 1e5 + 10;
// int n,m,x;
// int A[N],B[N];


// int main(){
//   scanf("%d%d%d",&n,&m,&x);

//   for(int i = 0;i < n;i++){
//     scanf("%d",&A[i]);
//   }

//   for(int i = 0;i < m;i++){
//     scanf("%d",&B[i]);
//   }

//   for(int i = 0,j = m-1;i < n;i++){
//     while(j >= 0 && A[i] + B[j] > x) j--;

//     if(A[i] + B[j] == x)
//     cout << i << ' ' << j;
//   }

//   return 0;
// }

#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n,m,x;
int q[N],p[N];

int main(){
  scanf("%d%d%d",&n,&m,&x);
  for(int i = 0;i < n;i++){
    scanf("%d",&q[i]);
  }

  for(int i = 0;i < m;i++){
    scanf("%d",&p[i]);
  }

  for(int i = 0,j = m - 1;i < n;i++){
    while(q[i] + p[j] > x) j--;

    if(q[i] + p[j] == x){
      printf("%d %d",i,j);
      break;
    }
      
  }
  return 0;
}