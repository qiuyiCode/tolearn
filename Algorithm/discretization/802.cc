// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// typedef pair<int,int> PII;

// const int N = 3e5 + 10;
// int n,m;
// int a[N],s[N];
// vector<int> alls;
// vector<PII> add,query;

// int find(int x){
//     int l = 0,r = alls.size()-1;
    
//     while(l < r){
//         int mid = (l + r) >> 1;
//         if(alls[mid] >= x) r = mid;
//         else l = mid + 1;
//     }
//     return r + 1;
// }

// int main(){
//     cin >> n >> m;

//     for(int i = 0;i < n;i++){
//         int x,c;
//         cin >> x >> c;
//         add.push_back(PII(x,c));
//         alls.push_back(x);
//     }

//     for(int i = 0;i < m;i++){
//         int l,r;
//         cin >> l >> r;
//         query.push_back({l,r});
//         alls.push_back(l);
//         alls.push_back(r);
//     }

//     sort(alls.begin(),alls.end());
//     alls.erase(unique(alls.begin(),alls.end()),alls.end());

//     for(auto item : add){
//         int x = find(item.first);
//         a[x] += item.second;
//     }

//     for(int i = 1;i <= alls.size();i++){
//         s[i] = s[i-1] + a[i];
//     }
   
//     for(auto item : query){
//         int l = find(item.first),r = find(item.second);
//         cout << s[r] - s[l-1] << endl;
//     }

//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// typedef pair<int,int> PII;

// int n,m;
// const int N = 3e5 + 10;
// int a[N],s[N];
// vector<int> alls; // 离散化后的数组下标
// vector<PII> add,query; // 一个代表(x,c),一个代表(l,r)

// // 去重
// // vector<int>::iterator unique(vector<int> &a){
// //     int j = 0;
// //     for(int i = 0;i < n;i++){
// //         while(!i || a[i] != a[i-1]){
// //             a[j++] = a[i];
// //         }
// //     }
// //     return a.begin() + j;
// // }

// int find(int x){
//     int l = 0,r = alls.size()-1;
//     while(l < r){
//         int mid = l + r >> 1;
//         if(alls[mid] >= x) r = mid;
//         else l = mid + 1;
//     }
//     return r + 1;
// }

// int main(){
//     cin >> n >> m;
//     for(int i = 0;i < n;i++){
//         int x,c;
//         cin >> x >> c;
//         add.push_back({x,c});
//         alls.push_back(x); // 将原数轴离散化
//     }

//     for(int i = 0;i < m;i++){
//         int l,r;
//         cin >> l >> r;
//         query.push_back({l,r});
//         alls.push_back(l);
//         alls.push_back(r);
//     }

//     sort(alls.begin(),alls.end());
//     alls.erase(unique(alls.begin(),alls.end()),alls.end());

//     for(auto item : add){
//         int x = find(item.first);
//         a[x] += item.second;
//     }

//     for(int i = 1;i <= alls.size();i++){
//         s[i] = s[i-1] + a[i];
//     }

//     for(auto item : query){
//         int l = find(item.first),r = find(item.second);
//         cout << s[r] - s[l-1] << endl;
//     }
//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// typedef pair<int,int> PII;
// const int N = 3e5 + 10;
// int n,m;
// vector<int> alls;
// vector<PII> add,query;
// int a[N],s[N];

// int find_in_alls(int x){
//     int l = 0,r = alls.size()-1,mid;

//     while(l < r){
//         mid = l + r >> 1;
//         if(alls[mid] >= x) r = mid;
//         else l = mid + 1;
//     }
//     return l + 1;
// }
 
// int main(){
//     scanf("%d%d",&n,&m);

//     int x,c;
//     for(int i = 0;i < n;i++){
//         scanf("%d%d",&x,&c);
//         add.push_back(PII(x,c));
//         alls.push_back(x);
//     }

//     while(m--){
//         int l,r;
//         scanf("%d%d",&l,&r);
//         alls.push_back(l);
//         alls.push_back(r);
//         query.push_back(PII(l,r));
//     }
    
//     // 去重
//     sort(alls.begin(),alls.end());
//     alls.erase(unique(alls.begin(),alls.end()),alls.end());

//     for(auto item : add){ // 下标映射
//         int x_in_alls = find_in_alls(item.first);
//         a[x_in_alls] += item.second;
//     }

//     for(int i = 1;i <= alls.size();i++){
//         s[i] = s[i-1] + a[i];
//     }

//     for(auto item : query){
//         int l = find_in_alls(item.first);
//         int r = find_in_alls(item.second);

//         cout << s[r] - s[l-1] << endl;
//     }

//     return 0; 
// }


// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// typedef pair<int,int> PII;
// const int N = 3e5 + 10;

// int a[N],s[N];
// int n,m;

// vector<int> alls; // 保存离散化后的数轴
// vector<PII> add,query; // add保存{x,c},query保存询问区间{l,r}

// int find(int x){
//     int l = 0,r = alls.size() - 1,mid;

//     while(l < r){
//         mid = l + r >> 1;
//         if(alls[mid] >= x) r = mid;
//         else l = mid + 1;
//     }

//     return l + 1;
// }

// int main(){
//     scanf("%d%d",&n,&m);
//     int x,c;
//     for(int i = 0;i < n;i++){
//         scanf("%d%d",&x,&c);
//         alls.push_back(x);
//         add.push_back({x,c});
//     }

//     while(m--){
//         int l,r;
//         scanf("%d%d",&l,&r);
//         query.push_back({l,r});
//         alls.push_back(l);
//         alls.push_back(r);
//     }

//     sort(alls.begin(),alls.end());
//     alls.erase(unique(alls.begin(),alls.end()),alls.end());

//     for(auto item : add){
//         int index = find(item.first);
//         a[index] += item.second;
//     }

//     for(int i = 1;i <= alls.size();i++){
//         s[i] = s[i-1] + a[i];
//     }

//     for(auto item : query){
//         int l = find(item.first);
//         int r = find(item.second);
//         printf("%d\n",s[r] - s[l-1]);
//     }

//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// typedef pair<int,int> PII;
// vector<PII> add,query;
// vector<int> alls;
// const int N = 3e5 + 10;
// int n,m;
// int a[N],s[N];

// int find(int x){
//     int l = 0,r = alls.size()-1;
//     int mid;

//     while(l < r){
//         mid = l + r >> 1;
//         if(alls[mid] >= x) r = mid;
//         else l = mid + 1;
//     }

//     return l + 1;
// }

// int main(){
//     int x,c;
//     int l,r;
//     scanf("%d%d",&n,&m);

//     for(int i = 0;i < n;i++){
//         cin >> x >> c;
//         add.push_back(PII(x,c));
//         alls.push_back(x);
//     }

//     for(int i = 0;i < m;i++){
//         cin >> l >> r;
//         query.push_back({l,r});
//         alls.push_back(l);
//         alls.push_back(r);
//     }

//     sort(alls.begin(),alls.end());
//     alls.erase(unique(alls.begin(),alls.end()),alls.end());

//     for(auto item : add){
//         int x = find(item.first);
//         a[x] += item.second;
//     }

//     for(int i = 1;i <= alls.size();i++){
//         s[i] = s[i-1] + a[i];
//     }

//     for(auto item : query){
//         int l = find(item.first),r = find(item.second);
//         cout << s[r] - s[l-1] << endl;
//     }
//     return 0;
// }

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int,int> PII;
vector<PII> add,query;
vector<int> nums; // 离散化后的数轴

int n,m;
const int N = 3e5 + 10;
int a[N],s[N];

int find(int x){
  int l = 0,r = nums.size()-1,mid;
  while(l < r){
    mid = l + r >> 1;
    if(nums[mid] >= x) r = mid;
    else l = mid + 1;
  }
  return l + 1;
}

int main(){
  scanf("%d%d",&n,&m);
  int x,c;
  for(int i = 0;i < n;i++){
    scanf("%d%d",&x,&c);
    add.push_back({x,c});
    nums.push_back(x);
  }

  int l,r;
  for(int i = 0;i < m;i++){
    scanf("%d%d",&l,&r);
    query.push_back({l,r});
    nums.push_back(l);
    nums.push_back(r);
  }

  // 去重
  sort(nums.begin(),nums.end());
  nums.erase(unique(nums.begin(),nums.end()),nums.end());

  for(auto item : add){
    auto x = find(item.first),c = item.second;
    a[x] += c; // 这里为什么a[x] = c不行呢? 因为x位置上可能加了好几次,需要累加
  }

  for(int i = 1;i <= nums.size();i++){
    s[i] = s[i-1] + a[i];
  }

  for(auto item : query){
    int l = find(item.first),r = find(item.second);

    printf("%d\n",s[r] - s[l-1]);
  }

  return 0;
}
