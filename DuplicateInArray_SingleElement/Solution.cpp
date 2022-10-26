#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l = 1, h = nums.size()-1;
        while(l < h)
        {
            //cout<<"---l="<<l<<", h="<<h<<endl;
            int count = 0;
            int m = (h+l)/2;
             //cout<<"----m="<<m<<endl;
            for(int i = 0; i < nums.size(); ++i){
                
                if(nums[i]>=l && nums[i]<=m){
                    //cout<<"nums["<<i<<"]="<<nums[i]<<endl;
                    count++;
                }
            }
            //cout<<"count="<<count<<endl;
            if(count <= m-l+1) l = m+1;
            else h = m;
        }
        return l;
    }
};


int main(){

    Solution s;
    
    vector<int> arr1 = {1,3,4,2,2};
    cout<<"Duplicate in arr1 = "<<s.findDuplicate(arr1)<<endl;
    
    vector<int> arr2 = {3,1,3,4,2};
    cout<<"Duplicate in arr2 = "<<s.findDuplicate(arr2)<<endl;

    return 0;
}