// #include <iostream>
// using namespace std;

// const int N = 1e5 + 10;
// int stk[N];
// int q[N];
// int n;
// int top = -1;

// int main(){
//   scanf("%d",&n);

//   for(int i = 0;i < n;i++){
//     scanf("%d",&q[i]);
//   }

//   for(int i = 0;i < n;i++){
//     while(top != -1 && stk[top] >= q[i]) top--;

//     if(top == -1) cout << "-1" << ' ';
//     else cout << stk[top] << ' ';
    
//     stk[++top] = q[i];
//   }

//   return 0;
// }



#include <iostream>
using namespace std;

int n;
const int N = 1e5 + 10;
int q[N];
int stk[N];
int top = -1;

int main(){
  scanf("%d",&n);
  for(int i = 0;i < n;i++){
    scanf("%d",&q[i]);
  }

  for(int i = 0;i < n;i++){
    while(top != -1 && stk[top] >= q[i]) top--;

    if(top != -1){
      printf("%d ",stk[top]);
    }else{
      printf("-1 ");
    }

    stk[++top] = q[i];
  } 

  return 0; 
}
