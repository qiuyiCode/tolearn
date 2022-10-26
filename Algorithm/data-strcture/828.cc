// #include <iostream>
// using namespace std;

// const int N = 1e5 + 10;
// int stk[N];
// int m;
// int top = -1;

// int main(){
//   scanf("%d",&m);

//   while(m--){
//     int k,x;
//     string str;
//     cin >> str;
//     if(str == "push"){
//       cin >> x;
//       stk[++top] = x;
//     }else if(str == "pop"){
//       top--;
//     }else if(str == "empty"){
//       if(top == -1)
//         cout << "YES" << endl;
//       else
//         cout << "NO" << endl;
//     }else{
//       cout << stk[top] << endl;
//     }
//   }

//   return 0;
// }


#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;
int stk[N];
int top = -1;

int main(){
  char op[10];
  int m;
  scanf("%d",&m);

  while(m--){
    scanf("%s",op);
    if(!strcmp(op,"push")){
      int x;
      scanf("%d",&x);
      stk[++top] = x;
    }else if(!strcmp(op,"pop")){
      top--;
    }else if(!strcmp(op,"empty")){
      if(top == -1)
        printf("YES\n");
      else
        printf("NO\n");
    }else{
      printf("%d\n",stk[top]);
    }
  }

  return 0;
}