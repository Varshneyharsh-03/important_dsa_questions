// User function Template for C++
class Solution {
  public:
    class DSU{
        public:
        vector<int> parent,rank;
        DSU(int n){
            parent.resize(n);
            rank.resize(n);
            
            for(int i=0;i<n;i++){
                parent[i]=i;
                rank[i]=1;
            }
        }
        
        int find(int node){
            return parent[node]==node ? node : parent[node] = find(parent[node]);
        }
        
        void unionRank(int i,int j){
            int s1 = find(i);
            int s2 = find(j);
            
            if(s1!=s2){
                if(rank[s1]>rank[s2]){
                    parent[s2]=s1;
                }
                else if (parent[s2]>parent[s1]){
                    parent[s1] = s2;
                }
                else{
                    parent[s2]=s1;
                    rank[s1]++;
                }
            }
        }
    };
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        sort(edges.begin(),edges.end(),[&](vector<int> a,vector<int> b){
            return a[2]<b[2];
        });
        
        int sum = 0;
        int count = 0;
        DSU dsu(V);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            
            if(dsu.find(u)!=dsu.find(v)){
                sum+=wt;
                dsu.unionRank(u,v);
                count++;
                if(count==V-1) break;
            }
            
            
        }
        
        return sum;
        
    }
};
