#include<iostream>
#include<queue>
#include<unordered_map>
#include<set>
#include<list>

using namespace std;

int main(){
    //pair ke first argumnent ke accordig sort hota hia 
    set<pair<int,char>>s;
    s.insert({3, 'C'});
	s.insert({3, 'C'});
	s.insert({3, 'C'});
	s.insert({2, 'A'});
	s.insert({1, 'D'});
	s.insert({4, 'B'});
    //set main  updation is not possible
    //to update value in set 
    //1. delete the pair {3,c};
    //2.then insert the pair again{4,c};
    //is tarah se update karte hai 
    auto x=s.find({3,'C'});
    if(x!=s.end()){
        //that means pair mil gya 
        //delete krte hai pehle
        s.erase(x);

    }
    //agar mil gaya tha {3,'c'} toh erase kr diya
    //agar nhi mila toh erase nhi hua hoga
    //insert tph kardo
    s.insert({4,'C'});
    auto f=s.begin();
    while(!s.empty()){
        cout<<(*f).first<<"  "<<(*f).second<<endl;
        s.erase(f);
        f=s.begin();
        
    }

    
    return 0;
}