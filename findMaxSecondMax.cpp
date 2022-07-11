#include <iostream>
#include <vector>

/* Find maximum, and second maximum numbers
 * in N time complexity (without sorting)
*/

/* func using vector, func1 using standard array */

 void func(std::vector<int> arr){
    int max_1=INT8_MIN, max_2=INT8_MIN;

    for(int i=0; i<arr.size(); i++){
              /* max*/
        if(arr[i]>max_1){
            max_2=max_1;
            max_1=arr[i];
        }  
        else if(arr[i]>max_2)
            max_2=arr[i];
    }
    std::cout<<"max1: "<<max_1<<", max2:"<<max_2<<std::endl;
 }

void func1(int arr[], int size){
    int max_1=INT8_MIN, max_2=INT8_MIN;

    for(int i=0; i<size; i++){
        /* max*/
        if(arr[i]>max_1){
            max_2=max_1;
            max_1=arr[i];
        }  
        else if(arr[i]>max_2)
            max_2=arr[i];
    }
    std::cout<<"max1: "<<max_1<<", max2:"<<max_2<<std::endl;
 }

int main(){
 
    std::vector<int>  vec={8,9,10,7,77,76 };  //{50,30,40,20}; //{9,1,5,12,11};
    func(vec);

    int arr[]={8,9,10,7,77,76}; //{50,30,40,20}; //{9,1,5,12,11};
    func1(arr, sizeof(arr)/sizeof(arr[0]));
    
    return 0;
}