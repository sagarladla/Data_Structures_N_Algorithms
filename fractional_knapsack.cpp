#include <bits/stdc++.h>
using namespace std;

int N,W,v,w;

bool sortvec(const pair<float,float> &a, const pair<float,float> &b) {
    return a.second > b.second;
}

map<float,float> vwmap;

void solve() {
    vector<pair<float, float>> sortedvec;
    cin >> N >> W;
    for(auto i=0; i<N; i++) {
        cin >> v >> w;
        vwmap[v] = w;
    }
    for(auto i=vwmap.begin();i!=vwmap.end();i++) {
        sortedvec.push_back(make_pair(i->first,(i->first/i->second)));
    }
    sort(sortedvec.begin(), sortedvec.end(), sortvec);
    float ans=0;
    for (auto i=sortedvec.begin();i!=sortedvec.end() and W!=0;i++) {
        if (W>=vwmap[i->first]) {
            ans += i->first;
            W -= vwmap[i->first];
        }
        else {
            ans += (W/vwmap[i->first]) * i->first;
            W -= (W/vwmap[i->first])*vwmap[i->first];
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t,count=1;
    cin >> t;
    while(t--) {
        cout << "Case #" << count << ": ";
        solve();
        count++;
    }
    return 0;
}