// #include <iostream>
// #include <map>
// #include <cctype>
// using namespace std;

// map<char,int> priority;
// const int N = 1e5 + 10;
// char op[N];
// char c_arr[N];
// int opds[N];
// int k = 0;

// int op_top = -1,opds_top = -1;

// int main(){
//     priority['+'] = 1;
//     priority['-'] = 1;
//     priority['*'] = 2;
//     priority['/'] = 2;
    
//     string exp;
//     cin >> exp;
//    // 中缀转后缀
//     for(int i = 0;i < exp.size();i++){
//         if(isalnum(exp[i])){
//             int j = i,x = 0;
//             while(j < exp.size() && isdigit(exp[j])){
//                 x = x * 10 + exp[j++];
//             }
//             c_arr[k++] = x;
//         }else{
//             /*1.栈空或者栈顶为'(',直接入栈
//               2.操作符为')',直接全部出栈,直到遇到'('
//               3.当前操作符比栈顶操作符优先级高,入栈
//               4.当前操作符比栈顶操作符优先级低或者等于,出栈
//               5.操作符全部取出,但是栈还未空,直接输出操作符
//             */

//             // 栈为空或者栈顶为'('或读取操作符的优先级大于栈顶操作符优先级,操作符直接入栈
//             if(op_top == -1 || exp[i] == '(' || priority[exp[i]] > priority[op[op_top]])
//                 op[++op_top] = exp[i];
//             // 当前遍历的符号为')',符号全部出栈,直到遇到'('为止
//             else if(exp[i] == ')'){
//                 while(op[op_top] != '(')  c_arr[k++] = op[op_top--];
//                 op_top--;
//             }else if(priority[exp[i]] <= priority[op[op_top]]){ // 读取操作符的优先级小于等于栈顶操作符优先级,高优先级运算符出栈,低优先级运算符入栈
//                 while(priority[exp[i]] <= priority[op[op_top]] && op_top != -1) c_arr[k++] = op[op_top--];
//                 op[++op_top] = exp[i];
//             }
//         }
//     }

//     while(op_top != -1){
//         c_arr[k++] = op[op_top--];
//     }

//     // for(int i = 0;i < k;i++){
//     //     cout << c_arr[i] << ' ';
//     // }

//     // 上面的代码实现了中缀表达式转后缀表达式

//     // 下面实现后缀表达式求值
//     int x = 0;
//     opds_top = -1;
//     for(int i = 0;i < k;i++){
//         // 操作数入栈
//         if(isalnum(c_arr[i])){
//             opds[++opds_top] = c_arr[i] - '0';
//         }else{
//             int r = opds[opds_top--];
//             int l = opds[opds_top--];
//             if(c_arr[i] == '*'){
//                 opds[++opds_top] = r * l;
//             }else if(c_arr[i] == '/'){
//                 opds[++opds_top] = l / r;
//             }else if(c_arr[i] == '+'){
//                 opds[++opds_top] = r + l;
//             }else{
//                 opds[++opds_top] = l - r;
//             }
//         }
//     }
    
//     cout << opds[0] << endl;

//     return 0;
// }


// #include <iostream>
// #include <cstring>
// #include <unordered_map>
// #include <stack>
// using namespace std;

// stack<char> op;
// stack<int> num;

// void eval(){
//   int b = num.top();num.pop();
//   int a = num.top();num.pop();  
//   char c = op.top();op.pop();

//   if(c == '+') num.push(a + b);
//   if(c == '-') num.push(a - b);
//   if(c == '*') num.push(a * b);
//   if(c == '/') num.push(a / b);
// }

// int main(){
//   unordered_map<char,int> pr = {{'+',1},{'-',1},{'*',2},{'/',2}};

//   string str;
//   cin >> str;

//   for(int i = 0;i < str.size();i++){
//     auto c = str[i];
//     if(isdigit(c)){
//       int x = 0,j = i;
//       while(j < str.size() && isdigit(str[j])){ // 第一个条件,str可能是100000
//         x = x * 10 + str[j++] - '0';
//       }
//       num.push(x);
//       i = j - 1; // 这时候i还未加
//     }else if(c == '('){ // 无优先级,直接入栈
//       op.push(c); 
//     }else if(c == ')'){ // 出栈并计算,直到遇到'('
//       while(op.top() != '(') eval();
//       op.pop(); // 弹出'('
//     }else{
//       while(op.size() && pr[op.top()] >= pr[c]) eval();
//       op.push(c);
//     }
//   }

//   while(op.size()) eval();
//   cout << num.top() << endl;
//   return 0;
// }

// #include <iostream>
// #include <unordered_map>
// #include <stack>
// using namespace std;

// stack<int> num;
// stack<char> op;
// unordered_map<char,int> pr{
//   {'+',1},
//   {'-',1},
//   {'*',2},
//   {'/',2}
// };

// void eval(){
//   int b = num.top();num.pop();
//   int a = num.top();num.pop();  
//   char c = op.top();op.pop();

//   if(c == '-') num.push(a - b);
//   if(c == '+') num.push(a + b);
//   if(c == '*') num.push(a * b);
//   if(c == '/') num.push(a / b);
// }


// int main(){
//   string str;
//   cin >> str;

//   for(int i = 0;i < str.size();i++){
//     auto c = str[i];
//     if(isdigit(c)){
//       int x = 0,j = i;
//       while(str.size() && isdigit(str[j])){
//         x = x * 10 + str[j++] - '0';
//       }
//       num.push(x);
//       i = j - 1;
//     }else if(c == '('){
//       op.push(c);
//     }else if(c == ')'){
//       while(op.size() && op.top() != '(') eval();
//       op.pop();
//     }else{
//       while(op.size() && pr[op.top()] >= pr[c]) eval();
//       op.push(c);
//     }
//   }

//   while(op.size()) eval();
//   cout << num.top() << endl;
//   return 0;
// }

// #include <iostream>
// #include <stack>
// #include <unordered_map>
// using namespace std;

// stack<int> num;
// stack<char> op;
// unordered_map<char,int> pr = {
//   {'+',1},
//   {'-',1},
//   {'*',2},
//   {'/',2},
// };

// void eval(){
//   int b = num.top();num.pop();
//   int a = num.top();num.pop();
//   char c = op.top();op.pop();

//   if(c == '+') num.push(a + b);
//   if(c == '-') num.push(a - b);
//   if(c == '*') num.push(a * b);
//   if(c == '/') num.push(a / b);
// }

// int main(){
//   string str;
//   cin >> str;

//   for(int i = 0;i < str.size();i++){
//     auto c = str[i];
//     if(isdigit(c)){
//       int x = 0,j = i;
//       while(j < str.size() && isdigit(str[j])){
//         x = x * 10 + str[j++] - '0';
//       }
//       num.push(x);
//       i = j - 1;
//     }else if(c == '('){
//       op.push(c);
//     }else if(c == ')'){
//       while(op.size() && op.top() != '(') eval();
//       op.pop();
//     }else{
//       while(op.size() && pr[op.top()] >= pr[c]) eval();
//       op.push(c);
//     }
//   }

//   while(op.size()) eval();
//   cout << num.top() << endl;
//   return 0;
// }


#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

unordered_map<char,int> pr = 
{
  {'+',1},
  {'-',1},
  {'*',2},
  {'/',2}
};

stack<int> num;
stack<char> oprd;

void eval(){
  int b = num.top();
  num.pop();
  int a = num.top();
  num.pop();
  char c = oprd.top();
  oprd.pop();

  if(c == '+') num.push(a + b);
  if(c == '-') num.push(a - b);
  if(c == '*') num.push(a * b);
  if(c == '/') num.push(a / b);

}

int main(){
  string str;
  cin >> str;

  for(int i = 0;i < str.size();i++){
    auto c = str[i];
    if(isdigit(c)){
      int t = 0,j = i;
      while(j < str.size() && isdigit(str[j])){
        t = t * 10 + str[j] - '0';
        i++,j++;
      }
      num.push(t);
      i--;
    }else if(str[i] == '('){
      oprd.push(str[i]);
    }else if(str[i] == ')'){
      while(!oprd.empty() && oprd.top() != '(') eval();
      oprd.pop(); // 弹出左括号
    }else{ // 其他运算符
      while(!oprd.empty() && pr[oprd.top()] >= pr[c]) eval();
      oprd.push(c);
    }
  }

  while(!oprd.empty()) eval(); // 整个表达式走完,可能还存在没有计算的数字

  printf("%d",num.top());
  return 0;
}