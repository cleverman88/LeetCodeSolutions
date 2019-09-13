#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/discuss/interview-question/124710/Facebook-or-Min-Time-to-Execute-Tasks
bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second > b.second);
}

int main(){
    string operations = "AAAACDEEBBB";
    int k = 2;
    map<char,int> m;
    for(auto x : operations){
        m[x]++;
    }

    vector<pair<char,int>> vect(0);

    for(auto &x: m){
        vect.push_back({x.first,x.second});
    }

    sort(vect.begin(),vect.end(), sortbysec);
    int timer = 0;

    while(true){
        vect[0].second--;
        timer++;
        if(vect[1].second != 0){
            vect[1].second--;
            timer++;
            sort(vect.begin(),vect.end(), sortbysec);
            if(vect[0].second == 0) break;
        }
        else{
            sort(vect.begin(),vect.end(), sortbysec);
            if(vect[0].second == 0) break;
            timer += k;
        }

    }

    cout << "TOTAL TIME TO WAIT IS: " << timer << endl;

    return 0;
}
