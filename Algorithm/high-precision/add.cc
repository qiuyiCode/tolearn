// #include <iostream>
// #include <vector>
// using namespace std;

// vector<int> A,B,C;
// string a,b;

// vector<int> add(vector<int> &A,vector<int> &B){
//     if(A.size() < B.size()) return add(B,A);

//     int t = 0;
//     for(int i = 0;i < A.size();i++){
//         t += A[i];
//         if(i < B.size()) t += B[i];

//         C.push_back(t%10);
//         t /= 10;
//     }
//     if(t) C.push_back(t);
//     return C;
// }

// int main(){
//     cin >> a >> b;

//     // 将高精度数字(字符串)以逆序形式存入数组中(因为可能发生进位,如果按照从早向右存储,则会发生大规模重排)
//     for(int i = a.size()-1;i >= 0;i--){
//         A.push_back(a[i]-'0'); // a[i]此时为字符-‘0’之后才是数字
//     }

//     for(int i = b.size()-1;i >= 0;i--){
//         B.push_back(b[i]-'0');
//     }

//     auto C = add(A,B);

//     for(int i = C.size()-1;i >= 0;i--){
//         cout << C[i];
//     }
//     return 0;
// }


// #include <iostream>
// #include <vector>
// using namespace std;

// vector<int> A,B;

// vector<int> add(const vector<int> &A,const vector<int> &B){
//     if(A.size() < B.size()) return add(B,A); // 保证大数加小数

//     vector<int> rlt;
//     int t = 0;
    
//     for(int i = 0;i < A.size();i++){
//         if(i < B.size()) t += B[i];
//         t += A[i];
//         rlt.push_back(t % 10);
//         t /= 10;
//     }

//     if(t) rlt.push_back(t);

//     while(rlt.back() == 0 && rlt.size() > 1) rlt.pop_back();

//     return rlt;
// }

// int main(){
//     string a,b;
//     cin >> a >> b;
//     for(int i = a.size()-1;i >= 0;i--){
//         A.push_back(a[i] - '0'); // 一定别忘了字符转数字
//     }

//     for(int i = b.size()-1;i >= 0;i--){
//         B.push_back(b[i] - '0');
//     }

//     auto C = add(A,B);

//     for(int i = C.size()-1;i >= 0;i--){
//         cout << C[i];
//     }

//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;

vector<int> add(vector<int> &A,vector<int> &B){
  if(A.size() < B.size()) return add(B,A);

  vector<int> C;

  int t = 0;
  for(int i = 0;i < A.size();i++){
    if(i < B.size()) t += B[i];
    t += A[i];
    C.push_back(t % 10);
    if(t >= 10) t = 1;
    else t = 0;
  }

  if(t != 0) C.push_back(t); // 可能出现位数相等退出循环但是还有进位的情况

  while(C.back() == 0 && C.size() > 1) C.pop_back();
  return C;
}

int main(){
  string a,b;
  cin >> a >> b;
  vector <int> A,B;

  for(int i = a.size()-1;i >= 0;i--){
    A.push_back(a[i] - '0');
  }

  for(int i = b.size()-1;i >= 0;i--){
    B.push_back(b[i] - '0');
  }

  auto C = add(A,B);
  
  for(int i = C.size()-1;i >= 0;i--){
    printf("%d",C[i]);
  }

  return 0;
}