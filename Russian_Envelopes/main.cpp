#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int index(vector<int> vec, int low, int high, int key) {

    while(high > low){
        int mid = low + (high-low)/2;

        if(vec[mid] >= key)
            high = mid;
        else
            low = mid+1;
    }
    return high;
}

int maxEnvelopes(vector<vector<int>>& envelopes) {

    vector< pair<int,int> > pairs;

    for(int i = 0 ; i < envelopes.size() ; i++) {
        pair<int, int> p = make_pair(envelopes[i][0], envelopes[i][1]);
        pairs.push_back(p);
    }

    bool comp(pair<int,int> p1, pair<int,int> p2) {
        if(p1.first == p2.first)
            return p1.second < p2.second;

        return p1.first < p2.first;
    }

    sort(p.begin(), p.end(), comp);

    trim();

    vector<int> lis(pairs.size(), 0);
    lis[0] = pairs[0].second;
    int length = 1;
    for(int i = 1 ; i < pairs.size() ; i++) {

        //New smallest element
        if(pairs[i].second < lis[0]) {
            lis[0] = pairs[i].second;
        }
        //Largest element adds to the largest list
        else if(pairs[i].second > lis[length-1]) {
            lis[length++] = pairs[i].second;
        }
        else {
            lis[index(lis, 0, length-1, pairs[i].second)] = pairs[i].second;
        }
    }

    return length;

}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
