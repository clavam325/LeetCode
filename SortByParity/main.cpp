#include <iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> sortArrayByParity(vector<int>& A) {
    int i = 0, j = A.size()-1;

    while(i < j) {
        while(i < j && A[i]%2 == 0){
                cout << "i is " << i << endl;
            i++;
        }

        while(j > i && A[j]%2 != 0){
            cout << "j is " << j << endl;
            j--;
        }

        if(i < j){
                cout << "swap " << i << " " << j << endl;
            swap(A[i], A[j]);
        }
    }

    return A;
}

int main()
{
    vector<int> v;
    v.push_back(3);
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    sortArrayByParity(v);
    for(int i = 0 ; i < v.size(); i++){
        cout << v[i]  << " ";
    }
    return 0;
}
