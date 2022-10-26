// #include <iostream>
// using namespace std;

// const int N = 1e5 + 10;
// int m;
// int queue[N];
// int rear = 0;
// int front = 0;

// int main(){
//   scanf("%d",&m);

//   while(m--){
//     string s;
//     int x;
//     cin >> s;
//     if(s == "push"){
//       cin >> x;
//       queue[rear++] = x;
//     }else if(s == "pop"){
//       front++;
//     }else if(s == "empty"){
//       if(rear == front)
//         cout << "YES" << endl;
//       else
//         cout << "NO" << endl;
//     }else{
//       cout << queue[front] << endl;
//     }
//   }

//   return 0;
// }

#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;
int queue[N];

int main(){
  int front,rear,n;
  front = rear = 0;
  scanf("%d",&n);
  char op[10];

  while(n--){
    scanf("%s",op);
    if(!strcmp(op,"push")){
      int x;
      scanf("%d",&x);
      queue[rear++] = x;
    }else if(!strcmp(op,"pop")){
      front++;
    }else if(!strcmp(op,"empty")){
      if(rear == front)
        printf("YES\n");
      else
        printf("NO\n");
    }else{
      printf("%d\n",queue[front]);
    }
  }

  return 0;
}
