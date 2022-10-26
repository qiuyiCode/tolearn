// #include <iostream>
// using namespace std;

/*
    // 数的范围(找边界)
    
    // 二分查找
*/

// const int N = 1e6 + 10;
// int n,m;
// int q[N];
// int x;

/*
// 第一种,用来寻找左侧边界
int search1(int q[],int l,int r){
    int mid = (l+r) >> 1;
    while(l < r){
        if(q[mid] >= x) r = mid;
        else l = mid+1;
    }
    return l;
}
*/

/*
//第二种,用来寻找右侧边界
int search1(int q[],int l,int r){
    int mid = (l+r+1) >> 1;
    while(l < r){
        if(q[mid] <= x) l = mid;
        else r = mid-1;
    }
    return l;
}
*/

// int main(){
//     scanf("%d%d",&n,&m);
//     for(int i = 0;i < n;i++){
//         scanf("%d",&q[i]);
//     }

//     while(m--){ // 执行几轮
//         scanf("%d",&x);
//         int l = 0,r = n-1;
//         while(l < r){ // 左侧边界
//             int mid = (l+r) >> 1;
//             if(q[mid] >= x) r = mid;
//             else l = mid+1;
//         }

//         if(q[l] != x)
//             cout << "-1 -1" << endl;
//         else{
//             cout << l << ' ';
//             l = 0,r = n-1;
//             while(l < r){ // 右侧边界
//                 int mid = (l+r+1) >> 1;
//                 if(q[mid] <= x) l = mid;
//                     else r = mid-1;
//             }
//             cout << l << endl;
//         }
//     }
//     return 0;
// }


// #include <iostream>
// using namespace std;

// const int N = 1e6 + 10;
// int q[N];
// int n,m;

// int main(){
//     scanf("%d%d",&n,&m); // 数组长度和问询个数
//     for(int i = 0;i < n;i++){
//         scanf("%d",&q[i]);
//     }

//     while(m--){
//         int l = 0,r = n-1;

//         int x;
//         scanf("%d",&x);

//         while(l < r){ // 在这个循环中要更新mid
//             int mid = (l+r) >> 1;
//             if(q[mid] >= x) r = mid; // 这里是根据中点与所要寻找的数字比较,来更新边界
//             else l = mid + 1;
//         }
//         if(q[l] != x) // 找不到这个数字
//             cout << "-1 -1" << endl;
//         else{
//             cout << l << ' ';
//             l = 0,r = n - 1;
//             while(l < r){
//                 int mid = (l+r+1) >> 1;
//                 if(q[mid] <= x) l = mid;
//                 else r = mid -1;
//             }
//             cout << l << endl;
//         }
//     }
// }

#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n,m,k;
int q[N];

int main(){
    scanf("%d%d",&n,&m);

    for(int i = 0;i < n;i++){
        scanf("%d",&q[i]);
    }

    while(m--){
        scanf("%d",&k);
        int l = 0,r = n-1;
        while(l < r){
            int mid = (l+r) >> 1;
            if(q[mid] >= k) r = mid;
            else l = mid+1;
        }
        if(q[l] != k){
            cout << "-1 -1" << endl;
        }else{
            cout << l << ' ';
            int l = 0,r = n-1;
            while(l < r){
                int mid = (l+r+1) >> 1;
                if(q[mid] <= k) l = mid;
                else r = mid-1;
            }
            cout << l << endl;
        }
    }
    return 0;
}