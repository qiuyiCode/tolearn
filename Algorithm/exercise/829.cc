#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int m;
int queue[N];
int front = 0,rear = 0;

int main(){
  scanf("%d",&m);

  string op;
  int x;
  while(m--){
    cin >> op;
    if(op == "push"){
      scanf("%d",&x);
      queue[rear++] = x;
    }else if(op == "pop"){
      front++;
    }else if(op == "empty"){
      if(rear == front){
        printf("YES\n");
      }else{
        printf("NO\n");
      }
    }else{
      printf("%d\n",queue[front]);
    }
  }

  return 0;
}