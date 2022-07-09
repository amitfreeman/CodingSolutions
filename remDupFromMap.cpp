/* CS interview questions */
#include <bits/stdc++.h>
/* 
* Q1. How to disable creation of object on heap for class?
* - override new & delete operator & make it private
* Q2. How to remove duplicate key from map?
*  - loop over, track all duplicate in vector
*  - delete duplicate key from vector
*/

class A{
    private:
    /* make new & delete operator private */
        void* operator new(size_t s);
        void* operator new[](size_t s);
        void operator delete(void* v);
        void operator delete[](void* v);
};

int main(){
    A a;  //legal
    //A *a1=new A();  //illegal since new is private
    std::map<int, char> mp; 
    mp[1]='a';
    mp[2]='b';
    mp[3]='c';
    mp[4]='a';
    mp[5]='d';
    mp[6]='d';
    mp[7]='a';

    std::cout<<"---BEFORE---"<<std::endl;
    for(auto& m:mp){
        std::cout<<m.first<<", "<<m.second<<std::endl;
    }
    
    std::vector<int> dupkey;
    /* iterate on map */
    for(auto m: mp){
        /* check if key is already marked as duplicate,
           else proceed to check */
        auto it=std::find(dupkey.begin(), dupkey.end(), m.first);
        if(it==dupkey.end()){
            /* loop over to find if there is any other key with same value, 
                if found then add it into duplicate key list */
            for(auto m1: mp){
                if(m.first != m1.first && m1.second == m.second){
                    dupkey.push_back(m1.first);
                }
            }
        }//for2 end
    }//for1 end

   /*for(int &i: dupkey)
       std::cout<<"dupkey: "<<i<<", ";
   std::cout<<std::endl;*/

    /* erase the duplicate keys from map */
    for(int& i: dupkey)
       mp.erase(i);

    std::cout<<"\n---AFTER REMOVING DUPLICATE---"<<std::endl;
    for(auto& m:mp){
        std::cout<<m.first<<", "<<m.second<<std::endl;
    }   

    //delete a1; //illegal since private
    return 0;
}