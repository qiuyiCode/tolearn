// #include <iostream>
// using namespace std;

// int n;
// const int N = 1e5 + 10;
// int a[N],s[N];

// int main(){
//     int res = 0;
//     scanf("%d",&n);

//     for(int i = 0;i < n;i++){
//         scanf("%d",&a[i]);
//     }

//     for(int i = 0,j = 0;i < n;i++){
//         s[a[i]]++;
//         while(j <= i && s[a[i]] > 1){
//             s[a[j]]--;
//             j++;
//         }
//         res = max(res,i-j+1);
//     }
//     cout << res << endl;
//     return 0;
// }

// #include <iostream>
// using namespace std;

// int n;
// const int N = 1e5 + 10;
// int q[N];
// int fellow[N];

// int main(){
//     int res = 0;
//     scanf("%d",&n);

//     for(int i = 0;i < n;i++){
//         scanf("%d",&q[i]);
//     }

//     int j = 0;
//     for(int i = 0;i < n;i++){
//         fellow[q[i]]++;
//         while(j <= i && fellow[q[i]] > 1){ // 因为当前序列出现重复元素,所以j需要继续往前走
//             fellow[q[j]]--; // 这一行必须在前面,因为后面有j++,影响了此行的取值
//             j++;
//         }

//         if(j <= i){ // 必须是=,当只有一个元素的时候,仍然成立
//             res = max(i-j+1,res);
//         }
//     }
//     cout << res << endl;
// }


// #include <iostream>
// using namespace std;

// const int N = 1e5 + 10;
// int n;
// int q[N];
// int t[N];

// int main(){
//     int res = 0;
//     scanf("%d",&n);

//     for(int i = 0;i < n;i++){
//         scanf("%d",&q[i]);
//     }

//     for(int i = 0,j = 0;i < n;i++){
//         t[q[i]]++;
//         while(j <= i && t[q[i]] > 1){
//             t[q[j]]--;
//             j++;
//         }

//         if(j <= i){
//             res = max(res,i-j+1);
//         }
//     }
// }


#include <iostream>
#include <cmath>
using namespace std;

const int N = 1e5 + 10;
int q[N],t[N]; //t[N]用来判断重复序列
int n;

int main(){
	scanf("%d",&n);
	for(int i = 0;i < n;i++){
			scanf("%d",&q[i]);
	}

	int j = 0,c = 0;

	/*思想:看看i到底能离j多远*/
	for(int i = 0;i < n;i++){
			t[q[i]]++; // 加入重复序列判断数组
			while(j <= i && t[q[i]] > 1){
				t[q[j]]--;
				j++;
			}
 
			if(j <= i)
				c = max(c,i-j+1);
	}

	printf("%d",c);
	return 0;
}
