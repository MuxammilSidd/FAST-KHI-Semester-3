#include<iostream>
#include<unordered_map>
#include<vector>
#include<stack>
#include<set>
#include<utility>
#include<queue>

using namespace std;

//Create Adjacency List with Weights
void addEdge(int u , int v , int w ,bool direction, unordered_map<int , list<pair<int,int>> > &adjList){
        if(direction == 0){   // undirected

            adjList[u].push_back(make_pair(v,w));
            adjList[v].push_back(make_pair(u,w));
        }

        else{
            adjList[u].push_back(make_pair(v,w));
        }
}


// create adjacecny list without weights


//Print Adjacency List

void printList(unordered_map<int , list<pair<int,int>> > &adjList){

    for(auto i : adjList){
       cout << i.first << "-> ";
        for(auto j : i.second){
            cout << "("<< j.first << "," << j.second <<") ,";
        }
        cout << endl;
    }
}



//Shortest distance Value from source Node to all Vertexes ->Directed Graph
void topoSort(int node , unordered_map<int,bool>&visited ,unordered_map<int , list<pair<int,int>> > &adjList , stack<int>&st){
            visited[node] = true;
             
             for(auto neighbours :adjList[node]){
                 
                 if(!visited[neighbours.first]){
                        topoSort(neighbours.first , visited , adjList , st);
                 }
             }

             st.push(node);
}
void ShortesPathDistace(int src , vector<int>&dist , stack<int>&st , unordered_map<int , list<pair<int,int>> > &adjList){
      
      dist[src] = 0;
       

    while(!st.empty()){
        int top = st.top();
        st.pop();


        if(dist[top] != INT_MAX){
            
            for(auto i : adjList[top]){
                  
                  if(dist[top] + i.second   < dist[i.first]){
                         dist[i.first] = dist[top] + i.second;
                  }
            }
        }
    }
}




//DIJKSTRA'S ALGORITHM
// give the shortest distance from source node to all its Node -> Directed & Undirected , both
void DijkstrasAlgoShortestPath(int src ,unordered_map<int , list<pair<int,int>> > &adjList , vector<int>&dist){
     
     set<pair<int,int>>st;    // in pair -> first int : represents Node distance , second int : represents the Node value

     dist[src] = 0;
     st.insert(make_pair(0,src));


     while(!st.empty()){

        //fetch top node
        auto top = *(st.begin());   // (*) because st.begin() will return the iterator

        int nodeDistance = top.first;
        int topNode = top.second;

        //pop the top
        st.erase(st.begin());

        //traverse the neighbours

        for(auto neighbours : adjList[topNode]){

            if(nodeDistance + neighbours.second  < dist[neighbours.first]){   // we got the minimum distance  -> now we go and check if with the same node , is there exist an other record in "set"  or not
               
               auto record = st.find(make_pair(dist[neighbours.first] , neighbours.first));

               if(record != st.end()){
                   st.erase(record);
               }


               //update the distance
               dist[neighbours.first] = nodeDistance + neighbours.second;

               //push record in set
               st.insert(make_pair(dist[neighbours.first] , neighbours.first));

                 
            }
        }
     }
   

}

// there is a single difference b/w priority queue and SET
//in SET if we get a better pair(of {distance , nodeval}) for the nodeVal -> we erase the previos pair with nodeVal  and insert the new pair with the modified distance 
// but in priority queue we donot delete the previous pair , rather we just insert the new one and that's the
// reason in DIJKSTRAS Algorithm set are more time efficient


//DIJKSTRA'S ALGORITHM USING PRIORITY QUEUE 

void DijkstrasAlgo_priority_queue(int src , unordered_map<int,list<pair<int,int>>>&adjList , vector<int>&dist){
      
      priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;

      dist[src] =0 ;
      pq.push(make_pair(0,src));

      while(!pq.empty()){
        
        int nodeDistance = pq.top().first;
        int topNode = pq.top().second;

        pq.pop();


        for(auto neighbours : adjList[topNode]){

            if(nodeDistance + neighbours.second  < dist[neighbours.first]){
                   dist[neighbours.first] = nodeDistance + neighbours.second;

                   pq.push(make_pair(dist[neighbours.first] ,neighbours.first));
            }
        }

      }

}

// BELLMAN FORD ALGORITHM For Shortest distance from Source to All verticies
// Bellman ford algorithm -> handles negative edges  and can detect negative cycles

void BellManFord_Algorithm(int V , vector<vector<int>>&edges , int src){

    vector<int>dist(V , INT_MAX);
    dist[src] = 0;

    for(int i = 0 ; i< V-1; i++){   // N-1 iterations
       
       for(auto edge : edges){
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        if(dist[u] != INT_MAX  &&  dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
        }
       }
    }


    // to detect a negative cycle we need to perfom the Nth iteration 
    // if in the Nth iteration the distance array gets reduced it means there is a negative cycle

     for(auto edge : edges){
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        if(dist[u] != INT_MAX  &&  dist[u] + w < dist[v]){
                
            cout << "Negative Cycle Present "<< endl;
            return;
        }
   }
   cout << "Distance from Source: ";
   for(auto i : dist){
    cout << i << " ";
   }cout << endl;

}


//Prim's Algorithm to determine minimum spanning Tree

unordered_map<int,list<pair<int,int>>> calculatePRIMSMST(int V , unordered_map<int,list<pair<int,int>>> &adjList){
       
        vector<int>key(V , INT_MAX);
        vector<bool>mst(V , false);
        vector<int>parent(V , -1);

        // starting from 0 because my graph starts from 0
        key[0] = 0;
    
        for(int i = 0 ; i<V-1 ; i++){   // A spanning tree of a graph with V vertices has exactly V-1 edges.
        
        /*In each iteration of the main loop, you are essentially adding one edge to the MST. Initially, 
        no edges are included in the MST. After the first iteration, you have added one edge, 
        after the second iteration, two edges, and so on.
         After V-1 iterations, you will have added exactly V-1 edges, completing the MST.*/
              
                int mini = INT_MAX;
                int u;

                for(int j = 0 ; j<V ; j++){
                    if(key[j] < mini   && mst[j] == false){
                        mini = key[j];   //minimum value
                        u = j;           // minimum Node
                    }
        
                }

                mst[u] = true;  // mark the node..visited/included in mst

                //check adjacent nodes

                for(auto neighbours : adjList[u]){
                    int v = neighbours.first;
                    int w = neighbours.second;

                    if(mst[v] == false   &&  w < key[v]){
                        parent[v] = u;   //assign the parent
                        key[v] = w;    // update the key(wieght) value
                    }
                }

        }

        unordered_map<int,list<pair<int,int>>> result;  // minimum spanning tree  
        for(int i = 1  ; i<V ; i++){   // loop starting from 1 because there donot exist a parent of 0-> (First Node)Q1 
        // since we have arbitarry defined the parent of first node to be -1 so that's why we are not included it  
    
            result[parent[i]].push_back({i, key[i]});
            result[i].push_back({parent[i], key[i]}); // Since it's undirected
            
        }

        return result;
        
}





void printADJLIST(unordered_map<int,list<pair<int,int>>> adjlist){
    
    
    for (const auto &node : adjlist) {
        cout << "Node " << node.first << " is connected to:\n";
        for (const auto &neighbor : node.second) {
            cout << "  Node " << neighbor.first << " with weight " << neighbor.second << '\n';
        }
    }
}



// Number of Bridges in a GRAPH -> TRAJAN'S Algorithm
void addEdge(int u, int v, bool direction, vector<vector<int>>& adjList) {
    adjList[u].push_back(v);
    if (direction == 0) {
        adjList[v].push_back(u);
    }
}

void DFS_BRIDGES(int node, int parent, vector<vector<int>>& adjList, vector<bool>& visited, vector<int>& tin, 
        vector<int>& low, vector<vector<int>>& bridges, int& timer) {

    visited[node] = true;
    tin[node] = low[node] = timer++;
    
    for (int neighbor : adjList[node]) {
        if (neighbor == parent) continue;

        if (!visited[neighbor]) {
            DFS_BRIDGES(neighbor, node, adjList, visited, tin, low, bridges, timer);

            low[node] = min(low[node], low[neighbor]);  // assign the minimum value from the adjacent nodes, not the parent

            if (low[neighbor] > tin[node]) {   // to check if there is a bridge 
                bridges.push_back({neighbor, node});     
            }
        } else {
            low[node] = min(low[node], tin[neighbor]);
        }
    }
}

void BridgesInGraph(int V, vector<vector<int>>& edges) {
    vector<vector<int>> adjList(V);
    
    // Build the adjacency list from the edge list
    for (auto& edge : edges) {
        addEdge(edge[0], edge[1], 0, adjList);
    }

    vector<bool> visited(V, false);
    vector<int> tin(V, -1);  // Time of insertion
    vector<int> low(V, -1);  // Lowest time of insertion
    vector<vector<int>> bridges;
    int timer = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            DFS_BRIDGES(i, -1, adjList, visited, tin, low, bridges, timer);
        }
    }

    for (const auto& edge : bridges) {
        cout << edge[0] << " --- " << edge[1] << endl;
    }
    
}


// ARTICULATION  POINT IN A GRAPH

void DFS_Articulation(int node , int parent , vector<vector<int>>&adjList , vector<bool>&visited , vector<int>& tin ,vector<int>&low , vector<int>&mark , int &timer){

    visited[node] = true;
    tin[node] = low[node] = timer;
    timer++;

    int child =0;   // for the root condition -> if root has more than 1 child then root can be articulation point

    for(auto neighbour : adjList[node]){

        if(neighbour == parent) continue;

        if(!visited[neighbour]){
            DFS_Articulation(neighbour , node , adjList , visited , tin , low , mark , timer);

            low[node] = min(low[node] , low[neighbour]);

            if(low[neighbour] >= tin[node]  &&  parent != -1){
                mark[node] = 1;
            }

            child++;  // unvisited childs
       }

       else{
        low[node] = min(low[node] , tin[neighbour]);
       }
    }


    if(child > 1  && parent == -1){   // root node as articulation point
        mark[node] = 1;
    }

}


void ArticulationPoint(int V , vector<vector<int>>&edges){

    // creater adjacecny List
    vector<vector<int>> adjList(V);
    for(auto &edge : edges){
        addEdge(edge[0] , edge[1] , 0 , adjList);
    }
    vector<bool>visited(V , false);
    vector<int>tin(V);
    vector<int>low(V);

    vector<int>mark(V);  
    int timer = 0;
    for(int i = 0 ; i<V ; i++){
        if(!visited[i]){
            DFS_Articulation(i , -1 , adjList , visited , tin , low , mark , timer);
        }
    }

    cout << "Articulation Points : ";
    for(int i = 0 ; i<V ; i++){
        if(mark[i] == 1){           // 0-based Indexing graph
            cout << i << " ";
        }
    }
    cout << endl;

}


//STRONGLY CONNECTED COMPONNETS -> KASARAJU'S ALGORIHTM
/*KASARAJU'S ALGORIHTM
step-1 : Do a DFS -> push nodes in stack
step-2 : reverse the Graph
step-3 : Do a DFS

*/

void DFS1(int node, vector<int>& vis, vector<vector<int>>& adjList, stack<int>& st) {
    vis[node] = 1;
    for (auto it : adjList[node]) {
        if (!vis[it]) {
            DFS1(it, vis, adjList, st);
        }
    }
    st.push(node);
}

void DFS2(int node, vector<int>& vis, vector<vector<int>>& adjListR, vector<int>& ssc) {
    vis[node] = 1;
    ssc.push_back(node);
    for (auto it : adjListR[node]) {
        if (!vis[it]) {
            DFS2(it, vis, adjListR, ssc);
        }
    }
}

void KosarajuAlgo_SSC(int V, vector<vector<int>>& edges) {
    vector<int> vis(V, 0);
    stack<int> st;

    // Step 1: Create adjacency list for the original graph
    vector<vector<int>> adjList(V);
    for (auto& edge : edges) {
        adjList[edge[0]].push_back(edge[1]);
    }

    // Step 1: Perform DFS and push nodes onto the stack
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            DFS1(i, vis, adjList, st);
        }
    }

    // Step 2: Reverse the graph
    vector<vector<int>> adjListR(V);
    for (int i = 0; i < V; i++) {
        for (auto it : adjList[i]) {
            adjListR[it].push_back(i);
        }
    }

    // Step 3: Find SCCs in the reversed graph
    fill(vis.begin(), vis.end(), 0);   //  it will fill the vis[] array with 0's
    vector<vector<int>> ans;
    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (!vis[node]) {
            vector<int> ssc;
            DFS2(node, vis, adjListR, ssc);
            ans.push_back(ssc);
        }
    }

    // Print the results
    cout << "Total Components: " << ans.size() << endl;
    for (auto& ssc : ans) {
        for (int i : ssc) {
            cout << i << " ";
        }
        cout << endl;
    }
}



int main(){

   int V = 8;
   int E = 8;

// unordered_map<int , list<pair<int,int>> > adjList;

//    addEdge(0,1,2,0,adjList);
//    addEdge(0,3,6,0,adjList);
//    addEdge(1,3,8,0,adjList);
//    addEdge(1,2,3,0,adjList);
//    addEdge(1,4,5,0,adjList);
//    addEdge(2,4,7,0,adjList);



   //printList(adjList);

//    unordered_map<int,bool>visited;
//    for(int i = 0 ; i<V ; i++){
//     visited[i] = false;
//    }
/*
   stack<int>st;

   for(int i = 0 ; i<V ; i++){
         if(!visited[i]){
            topoSort(i , visited , adjList , st);
         }
   }

    vector<int>dist(V , INT_MAX);


        ShortesPathDistace(1 , dist , st , adjList);
        */

//  vector<int>dist(V , INT_MAX);
   
//    DijkstrasAlgoShortestPath(0 , adjList , dist);
//     for(int i = 0 ; i<dist.size() ; i++){
//         cout << dist[i] << " ";
//     }

//   unordered_map<int,list<pair<int,int>>> MST = calculatePRIMSMST(V, adjList);

//    printADJLIST(MST);

//vector<vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}, {2, 3} , {2, 4} , {2, 5} , {4, 6} , {5, 6}};

//   BridgesInGraph(V, edges);

 // ArticulationPoint(V , edges);

//  vector<vector<int>>edges = {{3,2,6} , {5,3,1} , {0,1,5} , {1,5,-3} , {1,2,-2} , {3,4,-2} , {2,4,3}};

//  BellManFord_Algorithm(V , edges , 0);

vector<vector<int>>edges = {{0,2} , {1,2} , {2,0} , {2,3} , {3,4} , {4,7} , {4,5} , {5,6} , {6,4} , {6,7}};

KosarajuAlgo_SSC(V , edges);

    
}