class solution{
public:
	node* lcadeepestleaves(node*root){
		vector<node*> temp;
		vector<vector<node*>> level;
		unordered_map<node*,node*>>hash;
		queue<pair<node*,node*>>q;
		q.push({root,NULL});
		q.push({NULL,NULL});

		hash[root]=NULL;
		while(!q.empty()){
			auto[node,parent]=q.front();q.pop();
			if(node==NULL){
				level.push_back(temp);
				temp.clear();
				if(q.size()>0){
					q.push({NULL,NULL});
				}
			}
			else{
				temp.push_back(node);
				hash[node]=parent;
				if(node->left){
					q.push({node->left,node});
				}
				if(node->right){
					q.push({node->right,node});
				}
			}
		}
	}
}