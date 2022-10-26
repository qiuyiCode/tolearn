// #include <iostream>
// using namespace std;

// int n,k;
// const int N = 1e5 + 10;
// int q[N];

// void swap(int &a,int &b){
//   int tmp = a;
//   a = b;
//   b = tmp;
// }

// void quick_sort(int q[],int l,int r){
//   if(l >= r) return;

//   int pivot = q[l + r >> 1];
//   int i = l-1,j = r+1;

//   while(i < j){
//     do i++;while(q[i] < pivot);
//     do j--;while(q[j] > pivot);

//     if(i < j){
//       swap(q[i],q[j]);
//     }
//   }

//   quick_sort(q,l,j);
//   quick_sort(q,j+1,r);
// }

// int main(){
//   scanf("%d%d",&n,&k);

//   for(int i = 0;i < n;i++){
//     scanf("%d",&q[i]);
//   }

//   quick_sort(q,0,n-1);

//   printf("%d\n",q[k-1]);
  
//   return 0;
// }


#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n,k;
int q[N];

void quick_sort(int q[],int l,int r){
  if(l >= r) return;

  int pivot = q[l + r >> 1];
  int i = l-1,j = r+1;
  while(i < j){
    do i++;while(q[i] < pivot);
    do j--;while(q[j] > pivot);

    if(i < j)
      swap(q[i],q[j]);
  }
  quick_sort(q,l,j);
  quick_sort(q,j+1,r);
}

int main(){
  scanf("%d%d",&n,&k);

  for(int i = 0;i < n;i++){
    scanf("%d",&q[i]);
  }

  quick_sort(q,0,n-1);

  printf("%d",q[k-1]);
}
