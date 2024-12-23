int main(){
	int n;
	cin>>n;
	vector<int>graph[n];
	vector<int>reversegraph[n];
	void dfs(vector<int>graph[],int i,bool*visited,vector<int>&stack){
		visited[i]=true;
		for(auto nbr:graph[i]){
			if(!visited[nbr]) dfs(graph,nbr,visted,stack);
		}
		//function call is complete;
		stack.push_back(i);
	}
	void dfs2(vector<int>graph,int i,bool*visited){
		visited[i]=true;
		for(auto nbr:graph){
			if(!visited[nbr]) dfs2(graph,nbr,visted);
		}
	}

	void solve(vector<int>graph,vector<int>reversegraph,int n ){
		bool visited[n];
		memset(visited,0,n);
		vector<int>stack;

		//step 1 need to store the vertices of acc to dfs finish time
		for(int i=0;i<n;i++){
			if(!visited[i]) dfs(graph,i,visted,stack);


		}

		//step 2 reverse the graph
		for(int i=n-1;i>=0;i--){
			reversegraph.push_back(graph[i]);
		}
		//step 3 to dfs according to the order given in the stack
		memset(visited,0,n);
		char component_name='A';
		


	}
}