#include <iostream>
#include<bits/stdc++.h>
using namespace std;

 int leastInterval(vector<char>& tasks, int n) {

        if(tasks.size() == 0)
            return 0;

        if(n == 0)
            return tasks.size();

        bool isCharLeft = true;
        vector<int> countVec(26,0);

        for(int i = 0 ; i < tasks.size() ; i++ ){
            countVec[tasks[i] - 'A']++;
        }

        //for(int i = 0 ; i < countVec.size() ; i++ )
        //    cout << "Count of " << (char)('A' + i) << "  is " << countVec[i] << endl;

        int i = 0 , temp = n, jobCount = 0;
        while(isCharLeft) {
            temp = n+1;
            i = 0;
            isCharLeft = false;
            while(i < countVec.size() && temp >= 0) {
                if(countVec[i] > 0) {
                    jobCount++;
                    temp--;
                    countVec[i]--;
                    if(countVec[i] > 0)
                        isCharLeft = true;
                }
                i++;
            }

            if(isCharLeft == false)
                break;

            if(temp >= 0)
                jobCount += temp;

        }

        return jobCount;
    }

int main()
{
    vector<char> v;
    v.push_back('A');
    v.push_back('A');
    v.push_back('A');
    v.push_back('B');
    v.push_back('B');
    v.push_back('B');
    cout << "Ans is " << leastInterval( v, 1);
    return 0;
}
