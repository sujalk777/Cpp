template<typename t>;
class graph{
	map<t,list<t>> adj;
public:
	graph(){

	}
	bool iscyclichelper(t node,map<t,bool>&visited,map<t,bool>&instack){
		//processing thr current node-visited,instack
		visited[node]=true;
		instack[node]=true;
	}
}