#include<iostream>
#include<unordered_map>
#include<vector>
#include<stack>
#include<set>
#include<utility>
#include<queue>
#include<list>
#include<algorithm>

using namespace std;

void adjacencyMatrix() {

	// n is the number of Nodes/vertices
	// m is the number of edges
	int n, m;
	cin >> n >> m;
	
	// Dynamic allocation of the adjacency matrix
	int **adjMat = new int*[n+1];  // Allocating n+1 rows (1-based indexing)
	for (int i = 0; i <= n; i++) {
		adjMat[i] = new int[n+1];  // Allocating n+1 columns for each row
	}

	// Initialize the matrix with 0
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			adjMat[i][j] = 0;
		}
	}

	// Read the edges and fill the adjacency matrix
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adjMat[u][v] = 1;
		adjMat[v][u] = 1;  // For undirected graphs
		// For directed graphs, comment the above line
	}

	// Display the adjacency matrix
	cout << "  ";  // To align the first row
	for (int i = 1; i <= n; i++) {  // Display column numbers
		cout << i << " ";
	}
	cout << endl;

	for (int i = 1; i <= n; i++) {  // Display row numbers and the matrix
		cout << i << " ";
		for (int j = 1; j <= n; j++) {
			cout << adjMat[i][j] << " ";
		}
		cout << endl;
	}

	// Deallocate memory
	for (int i = 0; i <= n; i++) {
		delete[] adjMat[i];
	}
	delete[] adjMat;
}


//Adjacency list

 
void addEdge(int u , int v , bool direction , unordered_map<int , list<int> >&adjList){    // instead of List we can also use SET : in case we want the neighbours in sorted order   
        //direction = 0 / False -> Undirected Graph
        //direction = 1 / True  -> Directed Graph

      //Create an Edge from u to v
      adjList[u].push_back(v);
      if(direction == 0)
      {
        adjList[v].push_back(u);
      }
}

void printAdjList(unordered_map<int , list<int> >&adjList){
    for(auto i : adjList){
        cout << i.first <<" -> ";
        for(auto j : i.second){
            cout << j << " ";
        }
        cout << endl;
    }
}

//BFS
void BFS(unordered_map<int , list<int> >&adjList, unordered_map<int , bool> &visited ,vector<int>&ans , int node){
     
     queue<int>q;
     q.push(node);
     visited[node] = true;

     while(!q.empty()){
      int frontNode = q.front();
      q.pop();

      //store front Node
      ans.push_back(frontNode);
      
      //traverse all neighbours

      for(auto i : adjList[frontNode]){
         if(!visited[i]){
          q.push(i);
           visited[i] = true;

         }
      }


     }
}




//DFS

void DFS(unordered_map<int , list<int> >&adjList , unordered_map<int , bool > &visited , vector<int>&ans , int node){
          ans.push_back(node);
          visited[node] = true;


          for(auto i : adjList[node]){
              if(!visited[i]){
                DFS(adjList , visited , ans , i);
              }
          } 
}




//DETECT A CYCLE IN AN UNDIRECTED GRAPH

//1- BFS APPROACH
bool detectCycleBFS(unordered_map<int , list<int>>&adjList ,unordered_map<int , bool>&visited , int src){
     
     unordered_map<int,int>parent;   // tp store the parent of each node  , we can also make a pair of int in a queue to avoid this too 
     visited[src] = true;
     parent[src] = -1;

     queue<int>q;
     q.push(src);

     while(!q.empty()){
      int frontNode = q.front();
      q.pop();

       for(auto neighbours : adjList[frontNode]){
          if(visited[neighbours] == true   && neighbours != parent[frontNode]){
             return true;
          }
          else if(!visited[neighbours]){
             q.push(neighbours);
             visited[neighbours] = true;
             parent[neighbours] = frontNode;

          }
       }
     }

     return false;

}

//2-DFS APPROACH
bool detectCycleDFS(int node , int parent , unordered_map<int,bool>&visited , unordered_map<int , list<int>>&adjList){
     visited[node] = true;

     for(auto neighbours : adjList[node]){
        if(!visited[neighbours]){
          bool cycledetected = detectCycleDFS(neighbours , node , visited , adjList);
          if(cycledetected){
            return true;
          }
        }

        else if(neighbours != parent){
          return true;
        }
     }

     return false;
}





//CYCLE DETECTION IN A DIRECTED GRAPH
//USING DFS

bool cycleDetectINDG(int node , unordered_map<int,bool>&visited , unordered_map<int,bool>&dfsvis, unordered_map<int , list<int>> &adjList)
{
   visited[node] = true;
   dfsvis[node] = true;


   for(auto neighbour : adjList[node]){

       if(!visited[neighbour]){
          bool res = cycleDetectINDG(neighbour , visited , dfsvis , adjList);
          if(res) return true;
       }

       else if(dfsvis[neighbour]){
        return true;
       }

   }

          return false;

}

// if we want to detect cycle in a directed graph using BFS
//     we can apply KAHNS Algorithm 
//ALGO 

//  we will keep count of all the visisted nodes 
//  so in a valid topological sort ( if count == number of nodes ) -> means there is no cycle present  -> return false;
//                                   else return true (means cycle is present -> becuase the topological sort is invalid)
// 





//TOPOLOGICAL SORT 
//USING DFS

void topoSort_DFS(int node , unordered_map<int , bool>&visited , stack<int>&st , unordered_map<int , list<int>>&adjList)
{
    visited[node] = true;

    for(auto neighbours : adjList[node]){
      if(!visited[neighbours]){
          topoSort_DFS(neighbours , visited , st , adjList);
      }

    }

    st.push(node);
}


//USING KHANS ALGORITHM -- TOPOLOGICAL SORT
void topoSort_KAHNS(int V, unordered_map<int , list<int>>&adjList){
   
   vector<int>indegree(V);
   for(auto i : adjList){
      for(auto j : i.second){     //create indegree of each element
         
         indegree[j]++;
      }
   }

   queue<int>q;
   for(int i =0 ; i<V ; i++){
       if(indegree[i] == 0){
        q.push(i);
       }
   }


  //do bfs
  vector<int>ans; 
  while(!q.empty()){
    int front = q.front();
    q.pop();

    ans.push_back(front);

    for(auto neighbours : adjList[front]){
        indegree[neighbours]--;

        if(indegree[neighbours] == 0){
          q.push(neighbours);
        }
    }
  }


for(int i =0 ; i<ans.size() ; i++){
  cout << ans[i] << " ";
}

}


// Shortest Path from a Source Node to a Destination Node -> Unweighted Undirected Graph
void ShortestPath_FromSrcToDST(int src , int dst , unordered_map<int , bool> &visited, unordered_map<int,list<int>>&adjList){
       
       unordered_map<int,int>parent;   // to keep track of parents
       parent[src] = -1;
       visited[src] = true;

       queue<int>q;
       q.push(src);

       while(!q.empty()){
         int front = q.front();
         q.pop();

          for(auto neighbours : adjList[front]){
            
             if(!visited[neighbours]){
                  visited[neighbours] = true;
                  parent[neighbours] = front;
                   q.push(neighbours);
            }
          }
         
      }
      
      //store shortest path
      vector<int>arr;
      int currNode = dst;  // we will backtarck from dst to src -> then reverse it
       arr.push_back(currNode);

      while(currNode != src){
        currNode = parent[currNode];
         arr.push_back(currNode);
      }

      reverse(arr.begin() , arr.end());

   

      for(int i = 0 ; i<arr.size() ; i++){
        cout << arr[i] << " ";
      }
}


int main()
{
     int V = 8;
     int E = 9;
unordered_map<int , list<int> >adjList;

   addEdge(0,2,0,adjList);
   addEdge(0,3,0,adjList);
   addEdge(0,4,0,adjList);
   addEdge(2,5,0,adjList);
   addEdge(5,8,0,adjList);
   addEdge(3,8,0,adjList);
   addEdge(4,6,0,adjList);
   addEdge(6,7,0,adjList);
   addEdge(7,8,0,adjList);
    

    
  unordered_map<int , bool> visited;    // to mark visited Nodes


    for (int i = 0; i < V; ++i) {
        visited[i] = false;  // Initialize visited map
    }

   vector<int>ans;

  // for(int i = 0 ; i<V ; i++){
  //      if(!visited[i]){
  //       BFS(adjList , visited , ans , i);
  //      }
  // }

//   for(int i = 0 ; i<V ; i++){
//      if(!visited[i]){
//        DFS(adjList , visited , ans , i);
//     }
//   }


// for(int i = 0 ; i<ans.size() ; i++){
//   cout << ans[i] << " ";
// }


// for(int i =0 ; i<V ; i++){
//     if(!visited[i]){
//      if(detectCycleDFS( i , -1 ,  visited ,adjList)){
//       cout << "Cycle Detected";
//       return 0;
//      }
//   }
// }

// cout  << "Cycle Not Detected";



unordered_map<int, bool>dfsVis;  // to mark the nodes that are still in going through the recursive call
// for(int i =0  ; i<V ; i++){
//   dfsVis[i] = false;
// }

// for(int i =0 ; i<V ; i++){
//     if(!visited[i]){
//         if(cycleDetectINDG(i , visited , dfsVis , adjList)){
//             cout << "CYCLE DETECTED";
//             return 0;
//         }
//     }
// }

// cout << "CYCLE NOT DETECTED";

// stack<int>st;

// for(int i =0 ; i<V ; i++){
//   if(!visited[i]){
//   topoSort_DFS(i , visited , st , adjList);
//   }

// }

// while(!st.empty()){
//   cout << st.top() << " ";
//   st.pop();

// }

  
 // ShortestPath_FromSrcToDST(3,6,visited , adjList);

 adjacencyMatrix();



	return 0;
}
