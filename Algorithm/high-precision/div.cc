// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;

// string a;
// vector<int> A;
// int b;

// vector<int> div(vector<int> &A,int &b,int &r){
//     r = 0; // 余数
//     vector<int> C;

//     for(int i = A.size()-1;i >= 0;i--){
//         r = r * 10 + A[i];
//         C.push_back(r / b); // 商
//         r %= b; // 余数
//     }

//     reverse(C.begin(),C.end());
//     while(C.back() == 0 && C.size() > 1) C.pop_back();
//     return C;
// }

// int main(){
//     int r;
//     cin >> a >> b;

//     for(int i = a.size()-1;i >= 0;i--){
//         A.push_back(a[i]-'0');
//     }

//     auto C = div(A,b,r);

//     // 逆序打印
//     for(int i = C.size()-1;i >= 0;i--){
//         cout << C[i];
//     }

//     cout << endl << r;
// }

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// vector<int> A;

// vector<int> div(const vector<int> &A,int &b){
//     vector<int> res;

//     int r = 0; // r为余数remainder,m为商merchant

//     for(int i = A.size()-1;i >= 0;i--){
//         r = r * 10 + A[i];
//         res.push_back(r / b);
//         r = r % b;
//     }

//     reverse(res.begin(),res.end());
//     while(res.back() == 0 && res.size() > 1) res.pop_back();
//     b = r;
//     return res;
// }

// int main(){
//     string s;
//     int b;
//     cin >> s >> b;

//     for(int i = s.size()-1;i >= 0;i--){
//         A.push_back(s[i] - '0');
//     }

//     auto C = div(A,b);

//     for(int i = C.size()-1;i >= 0;i--){
//         cout << C[i];
//     }

//     cout << endl << b;

//     return 0;
// }



#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> div(vector<int> &A,int b,int &c){
  int t = 0; //t存储余数
  vector<int> C; // 存储商
  for(int i = 0;i < A.size();i++){
    t = t * 10 + A[i];
    C.push_back(t / b);
    t = t % b;
  }
  c = t;
  reverse(C.begin(),C.end());
  while(C.back() == 0 && C.size() > 1) C.pop_back();
  return C;
}

int main(){
  string a;
  vector<int> A;
  cin >> a;
  int b;
  scanf("%d",&b);

  for(int i = 0;i < a.size();i++){
    A.push_back(a[i] - '0');
  }
  int c;
  auto C = div(A,b,c);
  for(int i = C.size()-1;i >= 0;i--){
    printf("%d",C[i]);
  }
  cout << endl << c;
  return 0;
}
