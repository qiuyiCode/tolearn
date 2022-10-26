// #include <iostream>
// #include <vector>
// using namespace std;

// string a,b;
// vector<int> A,B;

// // 判断A >= B ?
// bool cmp(vector<int> &A,vector<int> &B){
//     if(A.size() != B.size()) return A.size() > B.size();

//     /*等价于

//     if(A.size() < B.size()){
//         return false;
//     }else if(A.size() > B.size()){
//         return true;
//     }

//     */

//     // 上面已经判断了是否大于或者小于,如果走到下面的流程,则表明A.size() == B.size()
    
//     for(int i = A.size()-1;i >= 0;--i){ // 两个数字位数相等,高位开始比较,高位只要有一个A[i] > B[i]或者A[i] < B[i]就返回
//         if(A[i] != B[i]) // 这里不管是取大于还是小于,都会返回,只有一个 == 会继续判断,所以将此作为if判断条件
//             return A[i] > B[i];
//     }
    
//     return true;
// }


// vector<int> sub(vector<int> &A,vector<int> &B){
//     vector<int> C;
//     int t = 0;

//     for(int i = 0;i < A.size();i++){
//         t = A[i] - t;
//         if(i < B.size()) t = t - B[i];
//         C.push_back((t+10)%10); 
//         if(t < 0)
//             t = 1;
//         else t = 0;
//     }

//     // if(t) C.push_back(t); // 已经判断过A>=B,不需要考虑是不是需要借位

//     while(C.back() == 0 && C.size() > 1) C.pop_back(); // 去前导零
//     return C;
// }

// int main(){
//     cin >> a >> b;

//     for(int i = a.size()-1;i >= 0;i--){
//         A.push_back(a[i] - '0');
//     }

//     for(int i = b.size()-1;i >= 0;i--){
//         B.push_back(b[i] - '0');
//     }

//     if(!cmp(A,B)){
//         cout << '-';
//         auto C = sub(B,A);
//         for(int i = C.size()-1;i >= 0;i--){
//             cout << C[i];
//         }
//     }else{
//         auto C = sub(A,B);
//         for(int i = C.size()-1;i >= 0;i--){
//             cout << C[i];
//         }
//     }

//     return 0;
// }

// #include <iostream>
// #include <vector>
// using namespace std;

// string a,b;
// vector<int> A,B;

// bool cmp(vector<int> &A,vector<int> &B){
//     if(A.size() != B.size()) return A.size() > B.size();

//     for(int i = A.size()-1;i >= 0;i--){
//         if(A[i] != B[i])
//             return A[i] > B[i];
//     }
//     return true;
// } 

// vector<int> sub(vector<int> &A,vector<int> &B){
//     vector<int> C;
    
//     int t = 0;
//     for(int i = 0;i < A.size();i++){
//         t = A[i] - t;
//         if(i < B.size()) t -= B[i];

//         C.push_back((t+10)%10);
//         if(t < 0)
//             t = 1;
//         else
//             t = 0;
//     }

//     while(C.back() == 0 && C.size() > 1) C.pop_back(); // 可能出现减完出现零的情况(极端情况000000-0000)
//     return C;
// }

// int main(){
//     cin >> a >> b;
    
//     for(int i = a.size()-1;i >= 0;i--){
//         A.push_back(a[i]-'0');
//     }

//     for(int i = b.size()-1;i >= 0;i--){
//         B.push_back(b[i]-'0');
//     }

//     if(cmp(A,B)){ // A.size() >= B.size() 不需要加'-'
//         auto C = sub(A,B);

//         for(int i = C.size()-1;i >= 0;i--){
//             cout << C[i];
//         }
//     }else{
//         cout << '-';
//         auto C = sub(B,A);
//         for(int i = C.size()-1;i >= 0;i--){
//             cout << C[i];
//         }
//     }

//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;

vector<int> A,B;

// 判断A>=B?
// bool A_more_than_B(){
//     if(A.size() < B.size()) return false;
//     else if(A.size() > B.size()) return true;
//     else{
//         for(int i = A.size()-1;i >= 0;i--){
//             if(A[i] > B[i]) return true;
//             else if(A[i] < B[i]) return false;
//             else{
//                 continue;
//             }
//         }
//     }
//     return true;
// }

// bool A_more_than_B(){
//     if(A.size() != B.size()) return A.size() > B.size();
//     else{
//         for(int i = A.size()-1;i >= 0;i--){
//             if(A[i] != B[i]) return A[i] > B[i];
//             else{
//                 continue;
//             }
//         }
//     }
//     return true;
// }

// vector<int> sub(const vector<int> &A,const vector<int> &B){
//     vector<int> res;

//     int t = 0;
//     for(int i = 0;i <= A.size();i++){
//         t += A[i];
//         if(i < B.size()) t -= B[i];
//         res.push_back((t + 10) % 10);
//         if(t < 0) t = -1;
//         else t = 0;
//     }

//     while(res.back() == 0 && res.size() > 1) res.pop_back();

//     return res;
// }

// int main(){
//     string a,b;
//     cin >> a >> b;

//     for(int i = a.size()-1;i >= 0;i--){
//         A.push_back(a[i] - '0');
//     }

//     for(int i = b.size()-1;i >= 0;i--){
//         B.push_back(b[i] - '0');
//     }

//     if(A_more_than_B()){
//         cout << "A>=B" << endl;
//         auto C = sub(A,B);
//         for(int i = C.size()-1;i >= 0;i--){
//             cout << C[i];
//         }
//     }else{
//         cout << '-';
//         auto C = sub(B,A);
//         for(int i = C.size()-1;i >= 0;i--){
//             cout << C[i];
//         }
//     }

//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;

// 判断A是否大于等于B ? 
bool isBig(vector<int> &A,vector<int> &B){
  if(A.size() != B.size()) return A.size() > B.size();

  for(int i = A.size()-1;i >= 0;i--){
    if(A[i] != B[i]) return A[i] > B[i]; // 从高位开始比较,不相等的话就可以返回了
  }
  return true;
}

vector<int> sub(vector<int> &A,vector<int> &B){
  vector<int> C;

  int t = 0;
  for(int i = 0;i < A.size();i++){
    t += A[i];
    if(B.size() > i) t -= B[i];

    C.push_back((t+10) % 10); // 如果是负数,借位.如果是正数,不用借位
    if(t < 0) t = -1;
    else t = 0;
  }

  while(C.back() == 0 && C.size() > 1) C.pop_back();
  return C;
} 

int main(){
  string a,b;
  vector<int> A,B;
  cin >> a >> b;

  for(int i = a.size()-1;i >= 0;i--){
    A.push_back(a[i] - '0');
  }

  for(int i = b.size()-1;i >= 0;i--){
    B.push_back(b[i] - '0');
  }

  if(isBig(A,B)){
    auto C = sub(A,B);
    for(int i = C.size()-1;i >= 0;i--){
      printf("%d",C[i]);
    }
  }else{
    printf("-");
    auto C = sub(B,A);
    for(int i = C.size()-1;i >= 0;i--){
      printf("%d",C[i]);
    }
  }

  return 0;
}