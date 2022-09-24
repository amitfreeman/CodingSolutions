#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_set>

using namespace std;

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */

class ThroneInheritance {
    string king;
    vector<string> order;
    map<string, vector<string>> mp;  //store parent - children relationship
    unordered_set<string> deth, vis;  //store dead list, and visited list in dfs()
public:
    ThroneInheritance(string kingName) {
        king=kingName;
    }
    
    void birth(string parentName, string childName) {
        mp[parentName].push_back(childName);
    }
    
    void death(string name) {
        deth.insert(name);
    }
    
      /* custom DFS function */
    void dfs(string s){
          vis.insert(s);
          /* if not deat, push in order */
          if(deth.find(s)==deth.end())
              order.push_back(s);
          
          for(auto i:mp[s]){
              /* if not visited, then push into dfs */
              if(vis.find(i)==vis.end())
                  dfs(i);
          }
      }
    
    vector<string> getInheritanceOrder() {
        vis.clear();
        order.clear();
        dfs(king);
        return order;
    }
};

int main(){
    //Initialize throne, & set people in
    ThroneInheritance t("king");
    t.birth("king", "andy"); // order: king > andy
    t.birth("king", "bob"); // order: king > andy > bob
    t.birth("king", "catherine"); // order: king > andy > bob > catherine
    t.birth("andy", "matthew"); // order: king > andy > matthew > bob > catherine
    t.birth("bob", "alex"); // order: king > andy > matthew > bob > alex > catherine
    t.birth("bob", "asha"); // order: king > andy > matthew > bob > alex > asha > catherine
    t.getInheritanceOrder(); // return ["king", "andy", "matthew", "bob", "alex", "asha", "catherine"]
    
    vector<string> ans  = t.getInheritanceOrder(); 

    for(string s:ans){
        cout<<s<<" -> ";
    }
    cout<<"null"<<endl;

    t.death("bob"); //death of bob
    ans.clear();
    cout<<"After death of bob"<<endl;
    ans  = t.getInheritanceOrder();  // return ["king", "andy", "matthew", "alex", "asha", "catherine"]
    for(string s:ans){
        cout<<s<<" -> ";
    }
    cout<<"null"<<endl;

    return 0;
}