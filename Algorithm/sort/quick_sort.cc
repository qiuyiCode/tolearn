// #include <iostream>
// using namespace std;

// /*实现快排
//     1.确定边界
//     2.将数组以边界为准分成两部分
//     3.递归排序
// */

// const int N = 1e6 + 10;
// int q[N];
// int n;

// void swap(int &a,int &b){
//     int tmp;
//     tmp = a;
//     a = b;
//     b = tmp;
// }

// void quick_sort(int q[],int l,int r){
//     if(l >= r) return;
//     int pivot = q[(l+r) >> 1]; // 选择边界
//     int i = l-1,j = r+1;
//     while(i < j){
//         do i++;while(q[i] < pivot); // 不用do while,则可能出现q[i] == q[j]的情况,会导致死循环
//         do j--;while(q[j] > pivot);
//         if(i < j)
//             swap(q[i],q[j]);
//     }
//     quick_sort(q,l,j);
//     quick_sort(q,j+1,r);
// }

// int main(){
//     scanf("%d",&n);
//     for(int i = 0;i < n;i++){
//         scanf("%d",&q[i]);
//     }
//     quick_sort(q,0,n-1);
//     for(int i = 0;i < n;i++){
//         printf("%d ",q[i]);
//     }
//     return 0;
// }



// #include <iostream>
// using namespace std;
// const int N = 1e6 + 10;
// int n;
// int q[N];

// void swap(int &n1,int &n2){
// 	int tmp;
// 	tmp = n1;
// 	n1 = n2;
// 	n2 = tmp;
// }

// void quick_sort(int q[],int l,int r){
// 	if(l >= r) return;

// 	int pivot = q[(l+r) >> 1]; // pivot是一个元素
// 	int i = l-1,j = r+1;

// 	while(i < j){ // 数组如果是[3,3,1,3,3],则就有i == j的情况
// 		do i++;while(q[i] < pivot);
// 		do j--;while(q[j] > pivot);
//         if(i < j)
// 		    swap(q[i],q[j]);
// 	}
// 	quick_sort(q,l,j);
// 	quick_sort(q,j+1,r);
// }

// int main(){
// 	scanf("%d",&n);
// 	for(int i = 0;i < n;i++){
// 		scanf("%d",&q[i]);
// 	}

// 	quick_sort(q,0,n-1);

// 	for(int i = 0;i < n;i++){
// 		printf("%d ",q[i]);
// 	}

// 	return 0;
// }


// #include <iostream>
// using namespace std;

// const int N = 1e5 + 10;
// int n;
// int q[N];

// void swap(int &a,int &b){
// 	int tmp = a;
// 	a = b;
// 	b = tmp;
// }

// void quick_sort(int q[],int l,int r){
// 	if(l >= r) return;

// 	int pivot = q[(l+r) >> 1];
// 	int i = l - 1,j = r + 1;
// 	while(i < j){
// 		do i++; while(q[i] < pivot);
// 		do j--; while(q[j] > pivot);

// 		if(i < j){
// 			swap(q[i],q[j]);
// 		}
// 	}
// 	quick_sort(q,l,j);
// 	quick_sort(q,j+1,r);
// }

// int main(){
// 	scanf("%d",&n);

// 	for(int i = 0;i < n;i++){
// 		scanf("%d",&q[i]);
// 	}

// 	quick_sort(q,0,n-1);

// 	for(int i = 0;i < n;i++){
// 		printf("%d ",q[i]);
// 	}

// 	return 0;
// }

#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int q[N];
int n;

void swap(int &a,int &b){
	int tmp = a;
	a = b;
	b = tmp;
}

void quick_sort(int q[],int l,int r){
	if(l >= r) return;

	int pivot = q[l + r >> 1];
	int i = l-1,j = r+1;
	while(i < j){
		do i++; while(q[i] < pivot);
		do j--; while(q[j] > pivot);

		if(i < j){
			swap(q[i],q[j]);
		}
	}

	quick_sort(q,l,j);
	quick_sort(q,j+1,r);
}

int main(){	
	scanf("%d",&n);

	for(int i = 0;i < n;i++){
		scanf("%d",&q[i]);
	}	

	quick_sort(q,0,n-1);

	for(int i = 0;i < n;i++){
		printf("%d ",q[i]);
	}

	return 0;
}
