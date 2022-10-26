// #include <iostream>
// using namespace std;

// const int N = 1e5 + 10;
// int queue[N];
// int m;
// int front,rear;

// void init(){
//     front = 0; // 先进来的元素,在数组前面
//     rear = 0; // 后进来的元素,每次进一个就 + 1
// }

// void push(int x){
//     queue[rear++] = x;
// }

// void pop(){
//     front++;
// }

// void empty(){
//     if(front == rear){
//         cout << "YES" << endl;
//     }else{
//         cout << "NO" << endl;
//     }
// }

// void query(){
//     cout << queue[front] << endl;
// }

// int main(){
//     cin >> m;
//     while(m--){
//         string str;
//         int x;
//         cin >> str;
//         if(str.substr(0,4) == "push"){
//             cin >> x;
//             push(x);
//         }else if(str == "pop"){
//             pop();
//         }else if(str == "empty"){
//             empty();
//         }else{
//             query();
//         }
//     }
//     return 0;
// }


// #include <iostream>
// using namespace std;

// int m;
// const int N = 1e5 + 10;
// int queue[N];
// int front,rear; // 队头和队尾

// void init(){
//     front = rear = 0;
// }

// void empty(){
//     if(front == rear){
//         cout << "YES" << endl;
//     }else{
//         cout << "NO" << endl;
//     }
// }

// void push(int x){
//     queue[rear++] = x;
// }

// void pop(){
//     front++;
// }

// void query(){
//     cout << queue[front] << endl;
// }

// int main(){
//     init();
//     string str;
//     int x;
//     scanf("%d",&m);
//     while(m--){
//         cin >> str;
//         if(str.substr(0,4) == "push"){
//             scanf("%d",&x);
//             push(x);
//         }else if(str == "empty"){
//             empty();
//         }else if(str == "pop"){
//             pop();
//         }else{
//             query();
//         }
//     }
//     return 0;
// }



// #include <iostream>
// using namespace std;

// int m;
// const int N = 1e5 + 10;
// int queue[N];
// int front = 0,rear = 0; // 队头和队尾


// int main(){
//     scanf("%d",&m);
//     while(m--){
//         string str;
//         cin >> str;

//         if(str.substr(0,4) == "push"){
//             int x;
//             scanf("%d",&x);
//             queue[rear++] = x;
//         }else if(str == "pop"){
//             front ++;
//         }else if(str == "empty"){
//             if(front == rear)
//                 cout << "YES" << endl;
//             else
//                 cout << "NO" << endl;
//         }else{
//             cout << queue[front] << endl;
//         }
//     }
//     return 0;
// }


#include <iostream>
using namespace std;

int m;
const int N = 1e5 + 10;
int queue[N];
int front = 0,rear = -1; // 队头和队尾

int main(){
    scanf("%d",&m);
    while(m--){
        string str;
        cin >> str;

        if(str.substr(0,4) == "push"){
            int x;
            scanf("%d",&x);
            queue[++rear] = x;
        }else if(str == "pop"){
            front ++;
        }else if(str == "empty"){
            if(front > rear)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }else{
            cout << queue[front] << endl;
        }
    }
    return 0;
}
