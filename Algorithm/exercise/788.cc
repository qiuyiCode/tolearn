// #include <iostream>
// using namespace std;

// const int N = 1e5 + 10;
// typedef long long LL; // 逆序对数量可能比int大
// int q[N],tmp[N];
// int n;


// LL merge_sort(int l,int r){
//     if(l >= r) return 0;

//     int mid = l+r >> 1;
//     LL res = merge_sort(l,mid) + merge_sort(mid+1,r);

//     int k = 0,i = l,j = mid+1;
//     while(i <= mid && j <= r){
//         if(q[i] <= q[j]) tmp[k++] = q[i++];
//         else {
//             tmp[k++] = q[j++];
//             res += mid - i + 1;
//         }
//     }

//     while(i <= mid) tmp[k++] = q[i++];
//     while(j <= r) tmp[k++] = q[j++];

//     for(int i = l,j = 0;i <= r;i++,j++){
//         q[i] = tmp[j];
//     }
//     return res;
// }

// int main(){
//     scanf("%d",&n);
//     for(int i = 0;i < n;i++){
//         scanf("%d",&q[i]);
//     }

//     cout << merge_sort(0,n-1);
//     return 0;
// }


#include <iostream>
using namespace std;

typedef long long LL;

const int N = 1e5 + 10;
int n;
int q[N],t[N];

LL merge_sort(int q[],int l,int r){                      
    if(l >= r) return 0;
    int mid = l + r >> 1;
    LL res = merge_sort(q,l,mid) + merge_sort(q,mid+1,r);
    
    int i = l,j = mid+1,k = 0;
    while(i <= mid && j <= r){
        if(q[i] <= q[j]) t[k++] = q[i++];
        else{
            res += mid - i + 1; // mid前面的都已经排好了
            t[k++] = q[j++];
        }
    }

    while(i <= mid) t[k++] = q[i++];
    while(j <= r) t[k++] = q[j++];

    for(int i = l,j = 0;i <= r;i++,j++){
        q[i] = t[j];
    }
    return res;
}

int main(){
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        scanf("%d",&q[i]);
    }

    LL res = merge_sort(q,0,n-1);

    printf("%ld",res);

    return 0;
}
