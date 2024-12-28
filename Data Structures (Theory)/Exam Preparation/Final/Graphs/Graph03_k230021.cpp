#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Disjoint set Data Structure 
// Union by rank and size
class Disjoint{
 vector<int>rank , parent,size;

 vector<vector<int>>edges;
 vector<vector<int>>mst;

 public:
 Disjoint(int totalNode){
    rank.resize(totalNode+1 , 0);    // n+1 -> validing for both 0-based and 1-based indexing
    parent.resize(totalNode+1);
    size.resize(totalNode+1);

    for(int i = 0 ; i<= totalNode ; i++){
        parent[i] = i;
        size[i] = 1;
    }
 }
 
 int findUParent(int node){
      if(node == parent[node]){
        return node;   // base case
      }

      return parent[node] = findUParent(parent[node]);   //path-compression
 }

  // union by rank
 void UnionbyRank(int u , int v){
   
   int ulp_u = parent[u];
   int ulp_v = parent[v];

   if(ulp_u  == ulp_v) return;   // both nodes lie in a same component

   if(rank[ulp_u] < rank[ulp_v]){
       parent[ulp_u] = ulp_v;
   }

   else if(rank[ulp_v] < rank[ulp_u]){
      parent[ulp_v] = ulp_u;
   }
   else{
       // when ranks of ulp_u  and ulp_v  is same
       parent[ulp_v] = ulp_u;
       rank[ulp_u]++;   // bigger is ulp_u  and we are attaching ulp_v  with it , so rank++
   }
 }


 // union by size
 void UnionbySize(int u , int v){
   int ulp_u = parent[u];
   int ulp_v = parent[v];

   if(ulp_u  == ulp_v) return;   // both nodes lie in a same component

   if(size[ulp_u] < size[ulp_v]){
     parent[ulp_u] = ulp_v;
     size[ulp_v] += size[ulp_u];
   }
   else{
      // in equal it doesnot matter which node is attached to which
    parent[ulp_v] =  ulp_u;
    size[ulp_u] += size[ulp_v];
   }
 }



 // KrusKal's Algorithm

 void addEdge(int u, int v , int w){
    edges.push_back({u,v,w});
 }


  void KruskalAlgo_MST(int n) {

        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {    // if not using lamnda function then getting issues that i can't even read 
            return a[2] < b[2];  // Compare weights and return in ascending order
        });

        mst.clear();  // clear; so that for other graph the mst should be free
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if (findUParent(u) != findUParent(v)) {
                mst.push_back({u, v, w});
                UnionbyRank(u, v);
            }
            if (mst.size() == n - 1) break;  // Stop if we have enough edges
        }
  } 

 void printMST() const {
        cout << "Edges in the Minimum Spanning Tree:\n";
        for (const auto& e : mst) {
            cout << e[0] << " - " << e[1] << " : " << e[2] << "\n";
        }
    }
};
 


int main(){
    
    int n = 6;

   Disjoint ds(n);

   ds.addEdge(1,2,2);
   ds.addEdge(1,4,1);
   ds.addEdge(1,5,4);
   ds.addEdge(4,5,9);
   ds.addEdge(4,3,5);
   ds.addEdge(2,4,3);
   ds.addEdge(2,3,3);
   ds.addEdge(2,6,7);
   ds.addEdge(3,6,8);

   ds.KruskalAlgo_MST(n);
   ds.printMST();

}