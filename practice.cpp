// #include <bits/stdc++.h>
// using namespace std;
// vector<int> par;
// class edge{
// 	public:
// 	int vtx;
// 	int wt;
// 	edge(int a,int b){
// 		vtx=a;
// 		wt=b;
// 	}
// };
// int getParent(int node)
// {
// 	if (par[node] == node)
// 		return node;
// 	return par[node] = getParent(par[node]);
// }
// class Pair
// {
// 	public:
// 	int u;
// 	int wsf;
// 	Pair(int a, int b)
// 	{
// 		u = a;
// 		wsf = b;
// 	}
// };
// class comp{
// 	public:
// 	bool operator()(Pair a,Pair b){
// 		return a.wsf>b.wsf;
// 	}
// };
// void djk(vector<vector<edge>> &graph, int src, int vtx)
// {
// 	vector<int> dis(vtx, 1e9);
// 	dis[src] = 0;
// 	vector<bool>vis(vtx,false);
// 	priority_queue<Pair,vector<Pair>,comp>pq;
// 	pq.push({src,0});
// 	while(!pq.empty()){
// 		auto rem=pq.top();pq.pop();
// 		int u=rem.u;
// 		int wt=rem.wsf;
// 		if(vis[u])continue;
// 		dis[u]=wt;
// 		vis[u]=true;
// 		for(auto val:graph[u]){
// 			if(vis[val.vtx]==false){
// 				pq.push({val.vtx,wt+val.wt});
// 			}
// 		}
// 	}
// }
// int main()
// {
// 	int n, m, k;
// 	cin >> n >> m >> k;
// 	vector<vector<int>> graph;
// 	vector<int> res;
// 	int csf = 0;
// 	int super_road = 0;
// 	int count = 0;
// 	if (m < n - 1)
// 	{
// 		cout << -1;
// 		return 0;
// 	}
// 	for (int i = 0; i < m; i++)
// 	{
// 		int x, y, z;
// 		cin >> x >> y >> z;
// 		graph.push_back({z, x, y});
// 	}
// 	sort(graph.begin(), graph.end());
// 	for (int i = 0; i <= n; i++)
// 	{
// 		par.push_back(i);
// 	}

// 	for (auto &val : graph)
// 	{
// 		int u = val[1];
// 		int v = val[2];
// 		int cost = val[0];
// 		int x = getParent(u);
// 		int y = getParent(v);
// 		if (x != y)
// 		{
// 			par[x] = y;
// 			res.push_back(cost);
// 			csf += cost;
// 			count++;
// 			if (count == n - 1)
// 				break;
// 		}
// 	}
// 	if (count < n - 1)
// 	{
// 		cout << -1;
// 		return 0;
// 	}
// 	if (csf <= k)
// 	{
// 		cout << super_road;
// 		return 0;
// 	}
// 	for (int i = res.size() - 1; i >= 0; i--)
// 	{
// 		csf = csf - res[i] + 1;
// 		super_road++;
// 		if (csf <= k)
// 		{
// 			cout << super_road;
// 			return 0;
// 		}
// 	}
// 	cout << -1;
// 	return 0;
// }
#include <bits/stdc++.h>
using namespace std;
int main(){
   vector<int> arr(5,0);
   // arr={6,2,1,8,5};
   sort(arr.begin(),arr.end());
   for(auto vl:arr){
      cout<<vl<<" ";
   }
return 0;
}
