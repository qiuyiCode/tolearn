// #include <iostream>
// using namespace std;

// /*
//     先递归,后归并,需要一个辅助数组
// */

// const int N = 1e6 + 10;
// int n;
// int q[N],tmp[N];

// void merge_sort(int q[],int l,int r){
//     if(l >= r) return;
//     int mid = (l+r) >> 1;
//     merge_sort(q,l,mid),merge_sort(q,mid+1,r);

//     int i = l,j = mid+1,k = 0;
//     while(i <= mid && j <= r){
//         if(q[i] <= q[j]) tmp[k++] = q[i++];
//         else tmp[k++] = q[j++];
//     }

//     while(i <= mid) tmp[k++] = q[i++];
//     while(j <= r) tmp[k++] = q[j++];
    
//     for(int i = l,j = 0;i <= r;i++,j++){
//         q[i] = tmp[j];
//     }
// }

// int main(){
//     scanf("%d",&n);
//     for(int i = 0;i < n;i++){
//         scanf("%d",&q[i]);
//     }

//     merge_sort(q,0,n-1);

//     for(int i = 0;i < n;i++){
//         printf("%d ",q[i]);
//     }
//     return 0;
// }

/*归并排序*/
/*
    1.先确定一个mid将数组分成左右两侧
    2.递归
    3.归并
*/
// #include <iostream>
// using namespace std;


// const int N = 1e6 + 10;
// int n;
// int q[N],tmp[N];

// void merge_sort(int q[],int l,int r){
//     if(l >= r) return;

//     int mid = (l+r) >> 1;

//     merge_sort(q,l,mid);
//     merge_sort(q,mid+1,r);

//     int i = l,j = mid+1,k = 0;

//     while(i <= mid && j <= r){
//         if(q[i] <= q[j]) tmp[k++] = q[i++];
//         else tmp[k++] = q[j++];
//     }

//     while(i <= mid) tmp[k++] = q[i++];
//     while(j <= r) tmp[k++] = q[j++];

//     for(i = l,j = 0;i <= r;i++,j++){
//         q[i] = tmp[j];
//     }
// }

// int main(){
//     scanf("%d",&n);

//     for(int i = 0;i < n;i++){
//         scanf("%d",&q[i]);
//     }

//     merge_sort(q,0,n-1);

//     for(int i = 0;i < n;i++){
//         printf("%d ",q[i]);
//     }

//     return 0;
// }


// #include <iostream>
// using namespace std;

// int n;
// const int N = 1e5 + 10;
// int q[N],tmp[N];

// void merge_sort(int q[],int l,int r){
//     if(l >= r)  return;

//     int mid = l + r >> 1;
//     merge_sort(q,l,mid);
//     merge_sort(q,mid+1,r);

//     int i = l,j = mid + 1,k = 0; // k需要在这里重置,每次递归都有一个k变量
//     while(i <= mid && j <= r){
//         if(q[i] <= q[j]) tmp[k++] = q[i++];
//         else tmp[k++] = q[j++];
//     }

//     while(i <= mid){
//         tmp[k++] = q[i++];
//     }

//     while(j <= r){
//         tmp[k++] = q[j++];
//     }

//     for(int i = l,j = 0;i <= r;i++,j++){
//         q[i] = tmp[j];
//     }
// }

// int main(){
//     scanf("%d",&n);

//     for(int i = 0;i < n;i++){
//         scanf("%d",&q[i]);
//     }

//     merge_sort(q,0,n-1);

//     for(int i = 0;i < n;i++){
//         printf("%d ",q[i]);
//     }

//     return 0;
// }

// #include <iostream>
// using namespace std;

// int n;
// const int N = 1e5 + 10;
// int q[N],tmp[N];
// int res = 0;

// void merge_sort(int q[],int l,int r){
//     if(l >= r) return;
    
//     int mid = l + r >> 1;
//     merge_sort(q,l,mid);
//     merge_sort(q,mid+1,r);

//     int i = l,j = mid + 1,k = 0;
//     while(i <= mid && j <= r){
//         if(q[i] <= q[j]) tmp[k++] = q[i++];
//         else tmp[k++] = q[j++];
//     }

//     while(i <= mid) tmp[k++] = q[i++];
//     while(j <= r) tmp[k++] = q[j++];

//     for(int i = l,j = 0;i <= r;i++,j++){
//         q[i] = tmp[j];
//     }
// }

// int main(){
//     scanf("%d",&n);

//     for(int i = 0;i < n;i++){
//         scanf("%d",&q[i]);
//     }

//     merge_sort(q,0,n-1);

//     // cout << res << endl;

//     for(int i = 0;i < n;i++){
//         printf("%d ",q[i]);
//     }

//     return 0;
// }


// #include <iostream>
// using namespace std;

// typedef long long LL;
// int n;
// const int N = 1e5 + 10;
// int q[N],tmp[N];
// LL res = 0;

// LL merge_sort(int q[],int l,int r){
//     if(l >= r) return 0;
    
//     int mid = l + r >> 1;
//     res = merge_sort(q,l,mid) + merge_sort(q,mid+1,r);

//     int i = l,j = mid + 1,k = 0;
//     while(i <= mid && j <= r){
//         if(q[i] <= q[j]){
//             tmp[k++] = q[i++];
//         }
//         else{
//             res += mid - i + 1;
//             tmp[k++] = q[j++];
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

//     merge_sort(q,0,n-1);

//     cout << res << endl;

//     return 0;
// }



#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n;
int q[N],t[N];

void merge_sort(int q[],int l,int r){
    if(l >= r) return;
    int mid = l + r >> 1;
    merge_sort(q,l,mid);
    merge_sort(q,mid+1,r);

    int i = l,j = mid+1,k = 0;
    while(i <= mid && j <= r){
        if(q[i] <= q[j]) t[k++] = q[i++];
        else t[k++] = q[j++];
    }

    while(i <= mid) t[k++] = q[i++];
    while(j <= r) t[k++] = q[j++];

    for(int i = l,j = 0;i <= r;i++,j++){
        q[i] = t[j];
    }
}

int main(){
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        scanf("%d",&q[i]);
    }

    merge_sort(q,0,n-1);

    for(int i = 0;i < n;i++){
        printf("%d ",q[i]);
    }

    return 0;
}
