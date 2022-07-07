#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> answer;
        //answer.reserve(rowIndex+1);
        answer.push_back(1);
        /* first loop iterates for rowIndex
        and generates required array size ,
        second loop actually populates elements by adding two elements
        and replacing jth position element with it,
        then push back last '1' at end, and size also increases with it */
        for(int i=1; i<=rowIndex; i++){
            for(int j=answer.size()-1; j>0; j--){
                answer[j]+=answer[j-1];
            }
            answer.push_back(1);
        }
        return answer;
    }
};

int main(){
    int rowIdx;
    vector<int> ans;
    cout<<"Enter index number you want: "<<endl;
    cin>>rowIdx;

    Solution s;
    ans=s.getRow(rowIdx);

    cout<<"[ ";
    for(int& i:ans){
        cout<<i<<" ";
    }
    cout<<"]"<<endl;
    return 0;
}