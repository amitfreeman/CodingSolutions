#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int R,C, r=0, c=0, sum=0;
        
        R=matrix.size();
        C=matrix[0].size();
        //cout<<"R="<<R<<", C"<<C;
        
        int lookup[R][C];
        
        for(;r<R; r++){
            for(c=0;c<C; c++){
                lookup[r][c]=matrix[r][c];
                
                /* if not 0th row or column, and position has 1, count possible matrix */
                if(r && c && matrix[r][c]==1){
                    lookup[r][c]=1+ min( min(lookup[r][c-1], lookup[r-1][c]), 
                                    lookup[r-1][c-1] );
                    /* current + top + left + top_left */
                }
                
                sum+=lookup[r][c];
               // cout<<"DEBUG: lookup["<<r<<"]["<<c<<"]: "<<lookup[r][c]<<", sum: "<<sum<<endl;
            }
        }
        
        return sum;
    }
};

int main(){

   vector<vector<int>> mat1={
                          {0,1,1,1},
                          {1,1,1,1},
                          {0,1,1,1} };

   Solution s;

   cout<<"Possibilities in mat1 = "<<s.countSquares(mat1)<<endl;

   vector<vector<int>> mat2= {
                              {1,0,1},
                              {1,1,0},
                              {1,1,0} };
    
    cout<<"Possibilities in mat2 = "<<s.countSquares(mat2)<<endl;
}