#include<iostream>
#include<queue>
#include<set>
#include<unordered_map>
#include<map>
#include<list>
using namespace std;
#define pb push_back
template<typmame T>
class Graph{
    public :
    map<T,list<pair<T,int> > > adj;
    void addEdge(){

    }
    void print(){

    }
    //sssp in weighted graph is called dijkstra algorithm 
    int sssp(char src,char des){
        unordered_map<char ,char> parent;
        unordered_map<char,int> dist;
        //set the distance of all nodes equal to intmax 
        for(auto p:adj){
            dist[p]=INT_MAX;
        }
        //distance src from itself is zero 
        dist[src]=0;
        parent[src]=src ;
        set<pair<int, char> > s;
        //src ko daalo na set main 
        s.insert({dist[src],src});
        while(!s.empty()){
            auto f=s.begin();
            auto p=(*f).second;
            auto pd=(*f).first
        }
    }
    
}