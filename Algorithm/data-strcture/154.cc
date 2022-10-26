// #include <iostream>
// using namespace std;

// const int N = 1e6 + 10;
// int a[N];
// int k; // 滑动窗口大小
// int n;
// int queue[N];
// int front = 0,rear = 0; // 队头和队尾

// int main(){
//     scanf("%d%d",&n,&k);

//     for(int i = 0;i < n;i++){
//         scanf("%d",&a[i]);
//     }

//     for(int i = 0;i < n;i++){
//         // 判断队头是否已经滑出窗口
//         if(rear != front && i - k + 1 > queue[front]) front++;

//         while(rear != front && a[queue[rear-1]] >= a[i]) rear--;

//         queue[rear++] = i; 

//         if(i >= k - 1) printf("%d ",a[queue[front]]);
//     }   
    
//     cout << endl;
    
//     front = rear = 0;
//     for(int i = 0;i < n;i++){
//         // 判断队头是否已经滑出窗口
//         if(rear != front && i - k + 1 > queue[front]) front++;
    
//         while(rear != front && a[queue[rear-1]] <= a[i]) rear--;
    
//         queue[rear++] = i; 
    
//         if(i >= k - 1) printf("%d ",a[queue[front]]);
    
//     }  
//     return 0;
    
// }

// #include <iostream>
// using namespace std;

// const int N = 1e6 + 10;
// int queue[N];
// int front = 0,rear = 0;
// int n,k;
// int q[N];

// int main(){
//     scanf("%d%d",&n,&k);

//     for(int i = 0;i < n;i++){
//         scanf("%d",&q[i]);
//     }

//     for(int i = 0;i < n;i++){
//         // 保证在滑动窗口之内
//         if(front != rear && i - k + 1 > queue[front]) front++;
//         while(front != rear && q[queue[rear-1]] >= q[i]) rear--;

//         queue[rear++] = i;

//         // 每一轮输出
//         if(i - k + 1 >= 0) printf("%d ",q[queue[front]]);
//     }


//     cout << endl;
//     rear = front = 0;
//         for(int i = 0;i < n;i++){
//         // 保证在滑动窗口之内
//         if(front != rear && i - k + 1 > queue[front]) front++;
//         while(front != rear && q[queue[rear-1]] <= q[i]) rear--;

//         queue[rear++] = i;

//         // 每一轮输出
//         if(i - k + 1 >= 0) printf("%d ",q[queue[front]]);
//     }
// }


// #include <iostream>
// using namespace std;

// const int N = 1e6 + 10;
// int n,k;
// int queue[N],q[N];
// int front,rear;


// int main(){
//     front = rear = 0;
//     scanf("%d%d",&n,&k);

//     for(int i = 0;i < n;i++){
//         scanf("%d",&q[i]);
//     }

//     for(int i = 0;i < n;i++){
//         if(front != rear && i - k + 1 > queue[front]) front++;
//         while(front != rear && q[queue[rear-1]] >= q[i]) rear--;

//         queue[rear++] = i;

//         if(i - k + 1 >= 0) cout << q[queue[front]] << ' ';
//     }

//     cout << endl;
//     front = rear = 0;

//      for(int i = 0;i < n;i++){
//         if(front != rear && i - k + 1 > queue[front]) front++;
//         while(front != rear && q[queue[rear-1]] <= q[i]) rear--;

//         queue[rear++] = i;

//         if(i - k + 1 >= 0) cout << q[queue[front]] << ' ';
//     }
// }


// #include <iostream>
// using namespace std;

// const int N = 1e6 + 10;
// int n,k;
// int q[N];
// int queue[N];
// int front,rear;

// int main(){
//     front = rear = 0;
//     scanf("%d%d",&n,&k);

//     for(int i = 0;i < n;i++){
//         scanf("%d",&q[i]);
//     }

//     for(int i = 0;i < n;i++){
//         if(front != rear && queue[front] < i - k + 1) front++;
//         while(front != rear && q[queue[rear-1]] >= q[i]) rear--;

//         queue[rear++] = i;

//         if(i - k + 1 >= 0) cout << q[queue[front]] << ' ';
//     }

//     cout << endl;
//     front = rear = 0;

//     for(int i = 0;i < n;i++){
//         if(front != rear && queue[front] < i - k + 1) front++;
//         while(front != rear && q[queue[rear-1]] <= q[i]) rear--;

//         queue[rear++] = i;

//         if(i - k + 1 >= 0) cout << q[queue[front]] << ' ';
//     }

//     return 0;
// }

