// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;
// typedef pair<int,int> PII;

// // 区间合并
// const int N = 1e5 + 10;
// int n;
// vector<PII> segs;

// // bool isBig(PII &a,PII &b){
// //     return a.first < b.first;
// // }

// void merge(vector<PII> &segs){
//     vector<PII> res;
//     sort(segs.begin(),segs.end());

//     int st = -2e9,ed = -2e9; // 保证从第一组区间开始

//     for(auto seg : segs){
//         if(ed < seg.first){
//             if(st != -2e9){
//                 res.push_back({st,ed});
//             }
//             st = seg.first,ed = seg.second;
//         }else{
//             ed = max(ed,seg.second);
//         }
//     }

//     if(st != -2e9) res.push_back({st,ed}); // 最后一组

//     segs = res;
// }

// int main(){
//     scanf("%d",&n);
//     for(int i = 0;i < n;i++){
//         int l,r;
//         cin >> l >> r;
//         segs.push_back({l,r});
//     }

//     merge(segs);

//     cout << segs.size() << endl;
//     return 0;
// }

// #include <iostream>
// #include <algorithm>
// using namespace std;

// int n;
// typedef pair<int,int> PII;
// vector<PII> segs;

// bool isBig(PII &a,PII &b){
//     return a.first < b.first;
// }

// void merge(vector<PII> &segs){
//     vector<PII> res;
//     sort(segs.begin(),segs.end(),isBig);

//     int st = -2e9,ed = -2e9; // 维护当前需要合并的区间

//     for(auto seg : segs){
//         if(seg.first > ed){
//             if(st != -2e9){
//                 res.push_back({st,ed});
//             }
//             st = seg.first,ed = seg.second;
//         }else{
//             ed = max(ed,seg.second);
//         }
//     }
//     if(st != -2e9) res.push_back({st,ed});
//     segs = res;
// }

// int main(){
//     cin >> n;
//     for(int i = 0;i < n;i++){
//         int l,r;
//         cin >> l >> r;
//         segs.push_back({l,r});
//     }

//     merge(segs);

//     cout << segs.size() << endl;
//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// typedef pair<int,int> PII;

// vector<PII> segs;

// int n;

// bool isBig(const PII &a,const PII &b){
//     return a.first < b.first;
// }

// void merge(vector<PII> &segs){
//     vector<PII> res;
//     int st = -2e9,ed = -2e9;

//     sort(segs.begin(),segs.end(),isBig);

//     for(auto seg : segs){
//         if(seg.first > ed){
//             if(ed != -2e9){
//                 res.push_back({st,ed});
//             }
//             st = seg.first,ed = seg.second;
//         }else{
//             ed = max(ed,seg.second);
//         }
//     }
//     if(ed != -2e9) res.push_back({st,ed});

//     segs = res;

// }


// int main(){
//     cin >> n;

//     for(int i = 0;i < n;i++){
//         int l,r;
//         cin >> l >> r;
//         segs.push_back({l,r});
//     }

//     merge(segs);

//     cout << segs.size() << endl;
//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// typedef pair<int,int> PII;

// vector<PII> q,res;
// int n;

// bool isBig(const PII &a,const PII &b){
//     return a.first < b.first;
// }

// int main(){
//     scanf("%d",&n);
//     for(int i = 0;i < n;i++){
//         int l,r;
//         scanf("%d%d",&l,&r);
//         q.push_back(PII(l,r));
//     }

//     sort(q.begin(),q.end(),isBig);

//     PII mt_val(-2e9,-2e9);
//     for(int i = 0;i < q.size();i++){
//         if(q[i].first <= mt_val.second){
//             mt_val.second = max(q[i].second,mt_val.second);
//         }
//         else{
//             res.push_back(make_pair(mt_val.first,mt_val.second));
//             mt_val.first = q[i].first;
//             mt_val.second = q[i].second;
//         }
//     }
//     cout << res.size() << endl;
//     return 0;
// }


// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// typedef pair<int,int> PII;

// vector<PII> q,res;
// int n;

// bool isBig(const PII &a,const PII &b){
//     return a.first < b.first;
// }

// int main(){
//     scanf("%d",&n);
//     for(int i = 0;i < n;i++){
//         int l,r;
//         scanf("%d%d",&l,&r);
//         q.push_back(PII(l,r));
//     }

//     sort(q.begin(),q.end(),isBig);

//     PII mt_val(-2e9,-2e9);
//     for(auto c : q){
//         if(c.first <= mt_val.second){
//             mt_val.second = max(c.second,mt_val.second);
//         }
//         else{
//             res.push_back(make_pair(mt_val.first,mt_val.second));
//             mt_val.first = c.first;
//             mt_val.second = c.second;
//         }
//     }
//     cout << res.size() << endl;
//     return 0;
// }



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> PII;
const int N = 1e5 + 10;
int n;
vector<PII> alls;

int main(){
  scanf("%d",&n);
  int l,r;
  for(int i = 0;i < n;i++){
    scanf("%d%d",&l,&r);
    alls.push_back({l,r});
  }

  sort(alls.begin(),alls.end());

  PII right_interval(-1e9-10,-1e9-10);

  int c = 0;
  for(auto item : alls){
    if(item.first > right_interval.second){
      right_interval.first = item.first;
      right_interval.second = item.second;
      c++;
    }
    else{
      right_interval.second = item.second > right_interval.second ? item.second : right_interval.second;
    }
  }

  printf("%d",c);
  return 0;
}