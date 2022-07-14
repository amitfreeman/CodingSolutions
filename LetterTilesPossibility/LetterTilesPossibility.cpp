#include <iostream>
#include <map>

using namespace std;

class Solution {
    map<string, bool> sm;

    void get(string str, string res, int& c){
        
        if(!sm[res] && res!=""){
            //cout<<" DEBUG: "<<res<<endl;
            sm[res]=true;
            c+=1;
        }

	    for(int i=0; i<str.length(); i++)
		    get(string(str).erase(i,1), res+str[i], c);
    }

public:   
    int numTilePossibilities(string tiles) {
        int count=0;
        get(tiles, "", count);    
        return count;
    }
};

int main(){
   string str="V" ; //"AAB", "AAABBC", "V"

   Solution s;
   int ans=s.numTilePossibilities(str);
   cout<<"Number of tiles possibilities are: "<<ans<<endl;
}