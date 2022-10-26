// #include <iostream>
// #include <vector>
// using namespace std;

// string a;
// vector<int> A;
// int b;

// vector<int> mul(vector<int> &A,int b){
//     vector<int> C;
//     int t = 0;

//     for(int i = 0;i < A.size();i++){
//         t += A[i] * b;
//         C.push_back(t%10);
//         t /=10 ;
//     }
//     if(t) C.push_back(t);
    
//     while(C.back() == 0 && C.size() > 1) C.pop_back();
//     return C;
// }

// int main(){
//     cin >> a;
//     scanf("%d",&b);
//     for(int i = a.size()-1;i >= 0;i--){
//         A.push_back(a[i]-'0');
//     }

//     auto C = mul(A,b);

//     for(int i = C.size()-1;i >= 0;i--){
//         cout << C[i];
//     }

//     return 0;
// }

// #include <iostream>
// #include <vector>
// using namespace std;

// vector<int> A;
// vector<int> B;

// vector<int> mul(const vector<int> &A,const int &b){
//     int t = 0;
//     vector<int> res;

//     for(int i = 0;i <= A.size();i++){ // 从个位开始
//         t += A[i] * b;
//         res.push_back(t % 10);
//         t /= 10;
//     }

//     if(t) res.push_back(t);

//     while(res.back() == 0 && res.size() > 1) res.pop_back();

//     return res;
// }

// int main(){
//     string a;
//     int b;
//     cin >> a;
//     cin >> b;

//     for(int i = a.size()-1;i >= 0;i--){
//         A.push_back(a[i] - '0');
//     }

//     auto C = mul(A,b);

//     for(int i = C.size()-1;i >= 0;i--){
//         cout << C[i];
//     }

//     return 0;
// }


#include <iostream>
#include <vector>
using namespace std;

vector<int> mul(vector<int> &A,int b){
  int t = 0;
  vector<int> C;
  for(int i = 0;i < A.size();i++){ // 重点理解这种计算方法
    t += A[i] * b;
    C.push_back(t % 10);
    t /= 10;
  }

  if(t) C.push_back(t);
  while(C.back() == 0 && C.size() > 1) C.pop_back();
  return C;
}

int main(){
  string a;
  int b;
  vector<int> A;
  cin >> a;
  scanf("%d",&b);
  for(int i = a.size()-1;i >= 0;i--){
    A.push_back(a[i] - '0');
  }

  auto C = mul(A,b);

  for(int i = C.size()-1;i >= 0;i--){
    printf("%d",C[i]);
  }
  return 0;
}