template<typename t> ;
class graph{
	map<t,list<t>>adj;
public:
	graph(){

	}
	void dfshelper(t node,map<t,bool>&visited){
		//whenever to come to a node,mark it visited 
		visited[node]=true;
		cout<<node<< " ";
		//try to find out a node which is neigbour of current node and not yet visited
		for(auto nbr:adj[node]){
			if(!visited[nbr]) dfshelper(nbr,visited);
		}
	}
	void dfs(t src){
		map<t,bool>visited;
		dfshelper(src,visited);
	}
}