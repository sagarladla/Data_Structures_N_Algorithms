#include <bits/stdc++.h>
using namespace std;

int n,prof[10000],dl[10000];

bool sortvec(const pair<int,int> &x, const pair<int,int> &y) {
    return x.first > y.first;
}

map<pair<int,int>, int> makeDS (vector<pair<int,int>> prof_dl) {
    map<pair<int,int>, int> ds;
    int job=1;
    for(auto i=prof_dl.begin();i!=prof_dl.end();i++) {
        ds[*i]=job;
        job++;
    }
    return ds;
}

void solve() {
    cin >> n;
    int max=0;
    for(int i=0;i<n;i++) {
        cin >> prof[i] >> dl[i];
    }
    vector<pair<int,int>> prof_dl;
    for(int i=0;i<n;i++) {
        if(max<dl[i]){
            max=dl[i];
        }
        prof_dl.push_back(make_pair(prof[i],dl[i]));
    }
    sort(prof_dl.begin(),prof_dl.end(), sortvec);
    map<pair<int,int>,int> val_job = makeDS(prof_dl);
    for(auto i=val_job.begin();i!=val_job.end();i++) {
        cout << "(" <<i->first.first << "," <<i->first.second << ")";
        cout << " : " << i->second;
        cout << endl ;
    }
    vector<int> slot(max,0);
    int total_profit=0;
    for(auto i=prof_dl.begin();i!=prof_dl.end();i++) {
        for(int j=i->second - 1;j>=0;j--) {
            if(slot[j]==0) {
                total_profit+=i->first;
                slot[j]=val_job[*i];
                break;
            }
        }
        
    }
    for(auto i=0;i<max;i++) {
        cout << slot[i] << " ";
    }
    cout << total_profit << endl ;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t,count=1;
    cin >> t;
    while(t--) {
        solve();
    }
}