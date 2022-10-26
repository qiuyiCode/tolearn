// #include <iostream>
// using namespace std;

// int n;
// const int N = 1e5 + 10;
// int q[N],c[N];

// int lowbit(int x){
//     return x & (~x + 1);
// }

// int main(){
//     scanf("%d",&n);
//     for(int i = 0;i < n;i++){
//         scanf("%d",&q[i]);
//     }
    
//     for(int i = 0;i < n;i++){
//         int b = 0;
//         while(q[i] > 0){
//             q[i] -= lowbit(q[i]);
//             b++;
//         }
//         c[i] = b;
//     }

//     for(int i = 0;i < n;i++){
//         cout << c[i] << ' ';
//     }
//     return 0;
// }   


// #include <iostream>
// using namespace std;

// int n;
// const int N = 1e5 + 10;
// int q[N];
// int res[N];

// int main(){
//     scanf("%d",&n);

//     for(int i = 0;i < n;i++){
//         scanf("%d",&q[i]);
//         while(q[i]){
//             if(q[i] & 1) res[i]++;
//             q[i] >>= 1;
//         }
//     }
    
//     for(int i = 0;i < n;i++){
//         printf("%d ",res[i]);
//     }
//     return 0;
// }


// #include <iostream>
// using namespace std;

// const int N = 1e5 + 10;
// int n;
// int q[N],res[N];

// // lowbit操作:返回一个数字二进制形式的最后一位1
// int lowbit(int x){
//     return x & -x;
// }

// int main(){
//     scanf("%d",&n);

//     for(int i = 0;i < n;i++){
//         scanf("%d",&q[i]);
//         while(q[i] > 0){
//             if(lowbit(q[i])) res[i]++;
//             q[i] -= lowbit(q[i]);
//         }
//     }

//     for(int i = 0;i < n;i++){
//         cout << res[i] << ' ';
//     }
    
//     return 0;
// }


#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n;
int q[N];

int lowbit(int x){  // 返回最后一位1,后面跟着零
	return x & -x;
}

int main(){
	scanf("%d",&n);
	for(int i = 0;i < n;i++){
			scanf("%d",&q[i]);
	}   

	for(int i = 0;i < n;i++){
		int c = 0;
		while(q[i]){
			if(lowbit(q[i])){
				c++;
				q[i] -= lowbit(q[i]);
			}
		}
		q[i] = c;
	}

	for(int i = 0;i < n;i++){
		printf("%d ",q[i]);
	}

	return 0;
}