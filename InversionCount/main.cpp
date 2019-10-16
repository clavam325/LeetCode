#include <iostream>
#include <bits/stdc++.h>

using namespace std;



// Complete the countInversions function below.

int merge(vector<int>& arr, vector<int>& temp, int low, int mid, int high) {

    int i = low, j = mid, k = low, invCount = 0;

    while(i <= mid-1 && j <= high) {

        if(arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];

            invCount += mid - i;
        }
    }

    while (i <= mid-1)
        temp[k++] = arr[i++];

    while (j <= high)
        temp[k++] = arr[j++];

    for(int ind = low; ind <= high ; ind++) {
        arr[ind] = temp[ind];
    }

    return invCount;
}

void printArr(char ID, vector<int> vec){
    cout << ID << " {";
    for(int i = 0 ; i < vec.size() ; i++)
        cout << vec[i];

        cout << "}" << endl;
}

int mergeSort(vector<int>& arr, vector<int>& temp, int low, int high ) {

    if(low >= high){
            cout << low << " Low " << endl;
        return 0;
    }

    int mid = low + (high - low)/2;

    int invCount = mergeSort(arr, temp, low, mid);
    cout << "Left InvCount" << invCount <<"{" << low << " | " << mid << " | " << high << endl;
    invCount += mergeSort(arr, temp, mid+1, high);
    cout << "Right InvCount" << invCount << "{" << low << " | "<<  mid << " | " << high << endl;

    invCount += merge(arr, temp, low, mid+1, high);
    printArr('A', arr);
    printArr('T', temp);
    cout << "MergeCount " << invCount << "{" << low << " | "<<  mid << " | " << high << endl << endl ;

    return invCount;
}


long countInversions(vector<int> arr) {

    vector<int> temp(arr.begin(), arr.end());

    return mergeSort(arr, temp, 0, arr.size()-1);
}

int main()
{
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(7);
    cout << countInversions(vec);
    return 0;
}
