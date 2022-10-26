// #include <iostream>
// using namespace std;

// int n,k;
// const int N = 1e6 + 10;
// int q[N];
// int queue[N];
// int front,rear;


// int main(){
//   front = rear = 0;
//   scanf("%d%d",&n,&k);

//   for(int i = 0;i < n;i++){
//     scanf("%d",&q[i]);
//   }

//   for(int i = 0;i < n;i++){
//     if(front != rear && i - k + 1 > queue[front]) front++;

//     while(front != rear && q[queue[rear-1]] >= q[i]) rear--;

//     queue[rear++] = i;

//     if(i - k + 1 >= 0) cout << q[queue[front]] << ' ';
//   }

//   cout << endl;
//   rear = front = 0;

//   for(int i = 0;i < n;i++){
//     if(front != rear && i - k + 1 > queue[front]) front++;

//     while(front != rear && q[queue[rear-1]] <= q[i]) rear--;

//     queue[rear++] = i;

//     if(i - k + 1 >= 0) cout << q[queue[front]] << ' ';
//   }
// }

// #include <iostream>
// using namespace std;

// const int N = 1e6 + 10;
// int n,k,q[N],queue[N];
// int front = 0; // front = rear = -1可能会导致出现取不到数的问题
// int rear = 0;

// int main(){
//   scanf("%d%d",&n,&k);

//   for(int i = 0;i < n;i++){
//     scanf("%d",&q[i]);
//   }

//   for(int i = 0;i < n;i++){
//     // 队列保证不为空,并且没有超出当前滑动窗口
//     if(front != rear && queue[front] < i-k+1) front++;

//     while(front != rear && q[queue[rear-1]] >= q[i]) rear--;

//     queue[rear++] = i;

//     if(i - k + 1 >= 0){
//       printf("%d ",q[queue[front]]);
//     }
//   }

//   printf("\n");

//     front = rear = 0;

//     for(int i = 0;i < n;i++){
//     // 队列保证不为空,并且没有超出当前滑动窗口
//     if(front != rear && queue[front] < i-k+1) front++;

//     while(front != rear && q[queue[rear-1]] <= q[i]) rear--;

//     queue[rear++] = i;

//     if(i - k + 1 >= 0){
//       printf("%d ",q[queue[front]]);
//     }
//   }
// }


#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int n,m,k;
int queue[N],q[N];

int main(){
  int front,rear,k;
  front = rear = 0;
  scanf("%d%d",&n,&k);
  for(int i = 0;i < n;i++){
    scanf("%d",&q[i]);
  }

  for(int i = 0;i < n;i++){
    if(front != rear && i-k+1 > queue[front]) front++;

    while(front != rear && q[queue[rear-1]] >= q[i]) rear--;

    queue[rear++] = i;

    if(i-k+1 >= 0){
      printf("%d ",q[queue[front]]);
    }
  }

    printf("\n");

    front = rear = 0;
    for(int i = 0;i < n;i++){
    if(front != rear && i-k+1 > queue[front]) front++;

    while(front != rear && q[queue[rear-1]] <= q[i]) rear--;

    queue[rear++] = i;

    if(i-k+1 >= 0){
      printf("%d ",q[queue[front]]);
    }
  }

  return 0;
}