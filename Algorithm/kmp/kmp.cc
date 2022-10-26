#include <iostream>
using namespace std;

/*前缀：一个字符串包含第一个字母但不包含最后一个字母的所有连续子串*/
/*后缀：一个字符串包含最后字母但不包含第一个字母的所有连续子串*/

/*利用已经部分匹配这个有效信息，保持i指针不回溯，通过修改j指针，让模式串尽量地移动到有效的位置*/

/*https://blog.csdn.net/weixin_44450058/article/details/123772886*/

const int N = 1e4 + 10,M = 1e5 + 10;
int n,m;
char p[N],s[M]; // p为模式串,s为主串
int ne[N]; //next数组

int main(){
  cin >> n >> m;
  for(int i = 1;i <= n;i++){
    scanf("%d",&p[i]);
  }

  for(int i = 1;i <= m;i++){
    scanf("%d",&s[i]);
  }

  // next数组
  for(int i = 2,j = 0;i <= n;i++){
    while(j && p[i] != p[j+1]) j = ne[j];
    if(p[i] == p[j+1]) j++;
    ne[i] = j;
  }

  // 匹配过程(子串向左错一位)
  for(int i = 1,j = 0;i <= m;i++){
    // j没有退回起点 && 主串与子串不能继续匹配,子串匹配位置就开始退
    while(j && s[i] != p[j+1]) j = ne[j];
    
    if(s[i] == p[j+1]) j++;
    if(j == n){
      cout << i - n + 1 << endl;
      j = ne[j];
    }
    
  }

  return 0;
}