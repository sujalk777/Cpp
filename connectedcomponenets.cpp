template<typename t>;
class graph{
	map<t ,list<t>>adj;
public:
	void dfshelper(t node,map<t<bool>>&visited){
		//whenever to come to a node, mark it visited;
		visited[node]=true
		for(auto nbr:adj[node]){
			if (!visited[nbr])dfshelper(nbr,visited);
		}
	}

	void dfs(t src){
		map<t,bool> visited;
		int component=1;
		dfshelper(src,visited);
		cout<<endl;
		for(auto i:adjlist){
			t city =i.first;
			if(!visited[city]){
				dfshelper(city,visited);
				component++;
			}
		}
	}
};