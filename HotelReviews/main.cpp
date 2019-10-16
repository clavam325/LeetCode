#include <iostream>
#include<bits/stdc++.h>
#include<map>
using namespace std;

bool compareFn(pair<int,int> p1, pair<int,int> p2) {
    if(p1.second == p2.second)
        return (p1.first < p2.first);

    return (p1.second > p2.second);
}

vector<int> solve(string A, vector<string> &B) {

    map<string, bool> mappo;
    string substr;
    int start = 0, prev = 0;
    vector<int> ans;

    while((start = A.find('_', start)) != -1) {
        substr = A.substr(prev, start - prev);
        mappo[substr] = true;
        prev = start+1;
        start++;
    }

    substr = A.substr(prev, start - prev);
    mappo[substr] = true;

    vector< pair<int,int> > vec;
    for(int i = 0 ; i < B.size() ; i++) {
        string opt = B[i];

        int count = 0;
        start = 0, prev = 0;
        while((start = opt.find('_', start)) != -1) {
            substr = opt.substr(prev, start - prev);
            prev = start+1;
            start++;

            if(mappo.find(substr) != mappo.end()) {
               cout << i << " " << substr << endl;
               count++;
            }
        }

        substr = opt.substr(prev, start - prev);
        if(mappo.find(substr) != mappo.end()) {
            cout << i << " " << substr << endl;
            count++;
        }

        pair<int,int> pair1;
        cout << opt << " " << i << " count " << count << endl;
        pair1.first = i;
        pair1.second = count;
        vec.push_back(pair1);
    }

    sort(vec.begin(), vec.end(), compareFn);
    vector< pair<int,int> >::iterator myit;

    for(myit = vec.begin(); myit != vec.end(); ++myit) {
        ans.push_back(myit->first);
        cout << myit->first << endl;
    }

    return ans;
}


int main()
{
    int B = 23;
    vector<int> C ;
    C.push_back(86);
    C.push_back(63);
    C.push_back(60);
    C.push_back(0);
    C.push_back(47);
    C.push_back(0);
    C.push_back(99);
    C.push_back(9);
    C.push_back(0);
    C.push_back(0);

    int curr = B;
    int whoGave = -1;

    for(int i = 0 ; i < C.size() ; i++) {
        if(C[i] != 0 ) {
            whoGave = curr;
            curr = C[i];
        cout << i << " whoGave->" << whoGave << " Curr->" << curr << endl;
        }
        else {
            int temp = curr;
            curr = whoGave;
            whoGave = temp;
            cout << i << " whoGave->" << whoGave << " Curr->" << curr << endl;
        }
    }
    cout << curr;


  /*
    string s1 = "cool_ice_wifi";
    vector<string> s2;
    s2.push_back("water_is_cool");
    s2.push_back("cold_ice_drink");
    s2.push_back("cool_wifi_speed");

    solve(s1, s2);
    */
    return 0;
}
