#include<iostream>
#include<queue>
#include<functional>
#include <utility>
#include<vector>
using namespsace std;
const int MAX=1e4+5;
typedef pair<long long,int> PII;
bool marked[MAX];
vector<pair<long long,int>> adj[MAX];

long long prim(int x){
	priority_queue<PII,vector<PII>,greater<PII>>Q;
	int y;
	long long minimumcost=0;
	PII p;
	Q.push(make_pair(0,x));
	while(!q.empty()){
		//select the minimmum weigth
		p=Q.top();
		Q.pop();
		x=p.second;
		//checking for cycle
		if(marked[x]==true) continue;
		minimumcost+=p.first;
		marked[x]=true;
		for(int i=0;i<adj[x].size();i++){
			y=adj[x][i].second;
			if(marked[y]==false) Q.push(adj[x][i]);
		}
	}
	return minimumcost;
}