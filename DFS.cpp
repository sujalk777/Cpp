#include<iostream>
#include<queue>
#include<unordered_map>
#include<set>
using namespace std;
template<typename>t;
class graph{
public:
    unordered_map<t,list<t>> adj;
    void addedge(t u,t v,bool bidir=true){

    }
    void print(){

    }
    void dfshelper(t src,unordered_map<t,bool>&visited){
        cout<<src<< " ";
        visited[src]=true;
        for(auto ngh:adj[src] ){
            if(!visited[ngh]){
                dfs(ngh,visited);
            }
        }
    }
    void dfs(t src){
        unordered_map<t,bool> visited;
        dfshelper(src,visited);
        int component=1;
        for(auto p:adj){
            if(!visited[p.first]){
                dfshelper(p.first,visited);
                component++;
            }
        }
        cout<<"total components: "<<component<<endl;
    }
};
int main (){
    Graph<int> g;
    g.addedge(0,1);
    g.addedge(0,1);
    g.addedge(0,1);
    g.addedge(0,1);
    g.addedge(0,1);
    g.addedge(0,1);
    return 0;
}