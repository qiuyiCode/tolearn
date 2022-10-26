// #include <iostream>
// using namespace std;

// int n,m;

// const int N = 1e5 + 10;
// int q[N];

// int main(){
//     scanf("%d%d",&n,&m);

//     for(int i = 0;i < n;i++){
//         scanf("%d",&q[i]);
//     }   

//     while(m--){
//         int k;
//         scanf("%d",&k);

//         int l = 0,r = n-1;
//         int mid;
        
//         while(l < r){
//             mid = l + r >> 1; // 必须对mid进行更新
//             if(q[mid] >= k) r = mid;
//             else l = mid + 1;
//         }
        
//         if(q[l] != k){
//             cout << "-1 -1" << endl;
//         }else{
//                 cout << l << ' ';
//                 l = 0,r = n-1;
//                 while(l < r){
//                     mid = l + r + 1 >> 1; // 必须对mid进行更新
//                     if(q[mid] <= k) l = mid;
//                     else r = mid - 1;
//                 }
//             cout << l << endl;
//         }
//     }
    
//     return 0;
// }

#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int n,m;
int q[N];

int main(){
	scanf("%d%d",&n,&m);

	for(int i = 0;i < n;i++){
			scanf("%d",&q[i]);
	}   

  while(m--){
    int k;
    scanf("%d",&k);
    int l = 0,r = n-1;
    while(l < r){ // 如果数组中存在这个元素,那么此时l == r是肯定满足的
      int mid = l + r >> 1;
      if(q[mid] >= k) r = mid;
      else l = mid + 1;
    }
    if(q[l] != k){
      cout << "-1 -1" << endl;
      continue;
    }else{
      cout << l << ' ';
      int l = 0,r = n-1;
      while(l < r){
        int mid = l + r + 1 >> 1;
        if(q[mid] <= k) l = mid;
        else r = mid - 1;
      }
      cout << l << endl;
    }
  }
  return 0;
}