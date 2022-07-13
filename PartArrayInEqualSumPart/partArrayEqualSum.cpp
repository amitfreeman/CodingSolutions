#include <iostream>
#include <vector>

using namespace std;

bool canThreePartsEqualSum(vector<int>& arr) {
    int totalSum=0, thirdSum=0;
    
    for(int &i: arr)
        totalSum+=i;
    
    if(totalSum%3 != 0)
        return false;
    
    thirdSum=totalSum/3;
    
    int temp=0, found=0;
    
    for(int i=0; i<arr.size(); i++){
        temp+=arr[i];
        if(temp==thirdSum){
            found++;
            temp=0;
        }
    }
    
    return found>=3? true:false;  // >3 to handle corner case of all 0s
}

int main(){
    vector<int> input={3,3,6,5,-2,2,5,1,-9,4};
    //0,2,1,-6,6,-7,9,1,2,0,1  
    //0,2,1,-6,6,7,9,-1,2,0,1  
    //3,3,6,5,-2,2,5,1,-9,4

    bool ans=canThreePartsEqualSum(input);    

    if(ans)
      cout<<"Partition possible"<<endl;
    else
      cout<<"Partition not possible!"<<endl;
}