/*
Here is the Question for the coding exercise:

Step1: Shopping Cart
- You are building a checkout system for a shop which only sells apples and oranges.
- Apples cost 60p and oranges cost 25p.
- Build a checkout system which takes a list of items scanned at the till and outputs the total cost.
- For example [Apple, Apple, Orange, Apple] => £2.05
- Make reasonable assumptions about the inputs to your solution; for example, many candidates take a list of strings as input

Step2: Simple offers:
- The shop decides to introduce 2 new offers
- buy one, get one free on Apples
- 3 for the price of 2 on oranges
- Update your checkout functions accordingly
*/

#include <iostream>
#include <sstream>
#include <map>

float apple_price=0.6;
float orange_price=0.25;
std::string apple="Apple";
std::string orange="Orange";

/* This program will take string containing
   list of goods purchased (only Apples & Oranges in this case),
   for example "Apple Apple Orange Apple",
   and return the Bill amount */
int main(int argc, char** argv){
    float bill_amt=0;
    std::map<std::string, int> shopping_list;

    /* if no item provided return 0 */
    if( argc < 2){
        return bill_amt;
    }
   
   std::stringstream ss(argv[1]);
   std::string word;
    /* count the frequency for each items */
    while(ss>>word){
        if(word==apple)
          shopping_list[apple]++;
        else if(word==orange)
          shopping_list[orange]++;
        else 
           std::cout<<"Invalid input! "<<word<<std::endl;
    }

    /* step 1: without any discount */
    /*for(auto& m: shopping_list){
        if(m.first == apple)
           bill_amt+=(m.second*apple_price);
        else if(m.first == orange)
           bill_amt+=(m.second*orange_price);
    }*/

    /* step 2: with discount
       - buy one, get one free on Apples
       - 3 for the price of 2 on oranges */
   for(auto& m: shopping_list){
      int div=0, quo=0;
      if(m.first == apple){
         div=m.second/2;  quo=m.second%2;
         bill_amt+=(div*apple_price);
         bill_amt+=(quo*apple_price);
      }
      else if(m.first == orange){
         div=m.second/3; quo=m.second%3;
         bill_amt+=(div*orange_price*2);
         bill_amt+=(quo*orange_price);
      }
   }

    std::cout<<"Final Bill Amount is: $"<<bill_amt<<std::endl;
    /* return has to be in int only, so multiply by 100 
        so actual value can be retrieved outside by dividing by 100*/
   return bill_amt*100;
}