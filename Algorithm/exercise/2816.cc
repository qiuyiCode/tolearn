// // #include <iostream>
// // using namespace std;

// // int n,m;

// // const int N = 1e5 + 10;
// // int A[N],B[N];

// // int main(){
// //     cin >> n >> m;

// //     for(int i = 0;i < n;i++){ 
// //         cin >> A[i];
// //     }
    
// //     for(int j = 0;j < m;j++){
// //         cin >> B[j];
// //     }

// //     int i = 0;
// //     for(int j = 0;j < m;j++){
// //         if(i < n && A[i] == B[j]) i++;
// //     }
// //     if(i == n)
// //         puts("Yes");
// //     else
// //         puts("No");
// //     return 0;
// // }

// #include <iostream>
// using namespace std;

// int n,m;

// const int N = 1e5 + 10;
// int A[N],B[N];

// int main(){
//     scanf("%d%d",&n,&m);

//     for(int i = 0;i < n;i++){
//         cin >> A[i];
//     }

//     for(int j = 0;j < m;j++){
//         cin >> B[j];
//     }

//     int j = 0;
//     for(int i = 0;i < m;i++){
//         if(j < n && B[i] == A[j]) j++;
//     }   

//     if(j == n)
//         puts("Yes");
//     else 
//         puts("No");

//     return 0;
// }

#include <iostream>
using namespace std;

int n,m;
const int N = 1e5 + 10;
int a[N],b[N];

int main(){
    scanf("%d%d",&n,&m);

    for(int i = 0;i < n;i++){
        scanf("%d",&a[i]);
    }

    for(int i = 0;i < m;i++){
        scanf("%d",&b[i]);
    }

    int i = 0;

    for(int j = 0;j < m;j++){
        if(i <= j && a[i] == b[j]) i++;

        if(i == n)
            break;
    }

    if(i == n)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}