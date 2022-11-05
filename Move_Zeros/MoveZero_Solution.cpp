#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        /* First attempt */
       /*int size=nums.size(), zeros=0;
       vector<int> ans;
        
        for(int i: nums){
            //cout<<" i="<<i;
            if(i!=0)
                ans.push_back(i);
            else //0
                zeros++;
        }
       
        for(int i=0; i<zeros; i++)
            ans.push_back(0);
        
        for(int i=0; i<size; i++)
            nums[i]=ans[i];*/
        
        
        /* better approach, less memory */
        int zeroIdx=0, size=nums.size();
        if(size==1) return;
        
        for(int i: nums){
            if(i)
                nums[zeroIdx++]=i;
        }
        
        for(int i=zeroIdx; i<size; i++)
            nums[i]=0;
       
    }
};

int main(){
    Solution s;
    vector<int> nums1={0,1,0,3,12};

    s.moveZeroes(nums1);

    cout<<"\nnums1: ";
    for(int i: nums1)
        cout<<" "<<i;

    vector<int> nums2={0};
    cout<<"\nnums2: ";
    for(int i: nums2)
        cout<<" "<<i;

    return 0;
}