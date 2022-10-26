#include <iostream>
#include <vector>

using namespace std;

class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        vector<int> ans;
        
        /* since arr[i] is bound between 0 to N-1, 
            we will store frequency in same array location idx */
            int idx;
            for(int i=0; i<n; i++){
                idx=arr[i]%n;
                arr[idx] += n;
            }
            
            
        /* count the number 'n' on index location
          if greater than 1, means it occured more than once */
            for(int i=0; i<n; i++){
                if(arr[i]/n > 1)
                   ans.push_back(i);
            }
            
            if(ans.size() > 0)
               return ans;
            else
                ans.push_back(-1);
                
            return ans;
    }
};


int main(){
    Solution s;

    int arr1[]={0,3,1,2};
    vector<int> v1=s.duplicates(arr1, sizeof(arr1)/sizeof(arr1[0]));

    cout<<"Duplicates in arr1: ";
    for(int i : v1)
       cout<<" "<<i;

    cout<<endl;

    int arr2[]={2,3,1,2,3};
    vector<int> v2=s.duplicates(arr2, sizeof(arr2)/sizeof(arr2[0]));

    cout<<"Duplicates in arr2: ";
    for(int i : v2)
       cout<<" "<<i;

    cout<<endl;
    return 0;
}