#include<iostream>
#include<algorithm>
#include<utility>
#include<utility>

using namespace std;
const int MAX=1e4+5;
int id[MAX],nodes,edges;
pair<long long,pair<int,int>>p[MAX];

void initialize(){
	for(int i=0;i<MAX;i++){
		id[i]=i;
	}
}

int root(int x){
	while(id[x]!=x){
		id[x]=id[id[x]];
		x=id[x];
	}
	return x;
}

void union1(int x,int y){
	int p=root(x);
	int q=root(y);
	id[p]=id[q];
}

long long kurskal(pair<long long,pair<int,int>>p[]){
	int x,int y;
	long long cost,minimumcost=0;
	for(int i=0;i<edges;i++){
		x=p[i].second.first;
		y=p[i].second.second;
		cost=p[i].first;

		if(root(x)!=root(y)){
			minimumcost+=cost;
			union(x,y)
		}
		return minimumcost;
	}
}