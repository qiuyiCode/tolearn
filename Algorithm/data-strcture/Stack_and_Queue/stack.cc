// #include <iostream>
// #include <string>
// using namespace std;

// const int N = 1e5 + 10;
// int stack[N];
// int m;
// int top;

// void init(){
//     top = -1;
// }

// void empty(){
//     if(top == -1)
//         cout << "YES" << endl;
//     else
//         cout << "NO" << endl;
// }

// void push(int x){
//     stack[++top] = x;
// }

// void pop(){
//     top--;
// }

// void query(){
//     cout << stack[top] << endl;;
// }

// int main(){
//     string str;
//     int x;
//     cin >> m;
//     init();
//     while(m--){
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
// }

#include <iostream>
using namespace std;

int m;
const int N = 1e5 + 10;
int stack[N];
int top = -1;

int main(){
    scanf("%d",&m);
    for(int i = 0;i < m;i++){
        string str;
        cin >> str;
        if(str.substr(0,4) == "push"){
            int x;
            cin >> x;
            stack[++top] = x;
        }else if(str == "pop"){
            top--;
        }else if(str == "empty"){
            if(top == -1) cout << "YES" << endl;
            else cout << "NO" << endl;
        }else{
            cout << stack[top] << endl;
        }
    }   
}