// #include <iostream>
// using namespace std;

// int n,top = -1;
// const int N = 1e5 + 10;
// int stack[N];

// int main(){
//     cin >> n;
//     for(int i = 0;i < n;i++){
//         int x;
//         cin >> x;
//         while(top >= 0 && stack[top] >= x) top--; // 时刻注意只有当if(x),当x == 0才是false,其他情况都是true
//         if(top >= 0)
//             cout << stack[top] << ' ';
//         else
//             cout << -1 << ' ';
//         stack[++top] = x;
//     }
//     return 0;
// }

// #include <iostream>
// using namespace std;

// int n;
// const int N = 1e5 + 10;
// int stk[N];
// int a[N];
// int top = -1;

// int main(){
//     scanf("%d",&n);

//     for(int i = 0;i < n;i++){
//         scanf("%d",&a[i]);
//     }

//     for(int i = 0;i < n;i++){
//         while(top != -1 && stk[top] >= a[i]) top--; // 枚举到的这个元素小于栈顶,栈中的数字就不需要了

//         if(top != -1){
//             cout << stk[top] << ' ';
//         }else{
//             cout << "-1" << ' ';
//         }

//         stk[++top] = a[i];
//     }
//     return 0;
// }


#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int stk[N];
int n;
int q[N];
int top = -1;


int main(){
    scanf("%d",&n);
    
    for(int i = 0;i < n;i++){
        scanf("%d",&q[i]);
    }

    for(int i = 0;i < n;i++){
        while(top != -1 && stk[top] >= q[i]) top--; // 注意这里的第二个条件是>=

        if(top != -1){
            cout << stk[top] << ' ';
        }else{
            cout << "-1" << ' ';
        }

        stk[++top] = q[i];
    }
    return 0;
}
