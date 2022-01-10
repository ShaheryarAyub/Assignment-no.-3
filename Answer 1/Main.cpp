#include<bits/stdc++.h> 
using namespace std;
#include <list>

class Graph
{
    int V;    // No. of vertices 
    list<int>* adjList;    // adjacency lists 

public:
    Graph(int V)
    {
        this->V = V;
        adjList = new list<int>[V];
    }
    void addEdge(int v, int w)
    {
        adjList[v].push_back(w); // Add w to v’s list
    }
    void pri_road();
    void con_road();
    void junction();

    void DFSUtil(int s, vector<bool>& visited);          //used by con_road & junction 
    void DFSJUNCTION(int s, vector<bool>& visited);      //used by con_road & junction  
};

//traverses all not visited vertices
//start node s

void Graph::DFSUtil(int s, vector<bool>& visited)
{
    // stack for DFS  
    stack<int> dfsstack;
    // current source node inside stack 
    dfsstack.push(s);
    while (!dfsstack.empty())
    {
        // Pop a vertex  
        s = dfsstack.top();
        dfsstack.pop();
               
        if (!visited[s])
        {
            cout << s << " ";
            visited[s] = true;
        }

        // explore all adjacent vertices of popped vertex. 
        //Push the vertex to the stack if still not visited.
        for (auto i = adjList[s].begin(); i != adjList[s].end(); ++i)
            if (!visited[*i])
                dfsstack.push(*i);
    }
}

void Graph::pri_road()
{   
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++)
        if (!visited[i])
            DFSUtil(i, visited);
}

void Graph::con_road()
{
    vector<bool> visited(V, false);

    for (int i = 6; i < V; i++)
        if (!visited[i])
            DFSUtil(i, visited);
}

void Graph::junction()
{
    vector<bool> visited(V, false);

    for (int i = 6; i < V; i++)
        if (!visited[i])
            DFSJUNCTION(i, visited);
}

void Graph::DFSJUNCTION(int s, vector<bool>& visited)
{
    stack<int> dfsstack;
    
    dfsstack.push(s);
    
    while (s = dfsstack.top())
    {                                                                         
        if (!visited[s])                                            

        {
            static int count = 0;
            count++;
            cout << count << " ";
        }
        dfsstack.pop();
                
        if (!visited[s])
        {
            visited[s] = true;
        }
       
        for (auto i = adjList[s].begin(); i != adjList[s].end(); ++i)
        if (!visited[*i])
        dfsstack.push(*i);
    }
}

int main()
{
    Graph gidfs(6);                  
    Graph conctg(15);
    Graph junction(15);              
    gidfs.addEdge(0, 3);
    gidfs.addEdge(3, 5);
    gidfs.addEdge(0, 5);
    gidfs.addEdge(3, 1);
    gidfs.addEdge(1, 4);
    gidfs.addEdge(3, 4);
    gidfs.addEdge(4, 5);
    gidfs.addEdge(2, 4);
    gidfs.addEdge(2, 5);

    cout << "Primary Road: " << endl;
    gidfs.pri_road();
    cout << " " << endl;

    conctg.addEdge(6, 8);
    conctg.addEdge(9, 10);
    conctg.addEdge(13, 14);

    conctg.addEdge(6, 7);
    conctg.addEdge(10, 11);
    conctg.addEdge(12, 14);

    conctg.addEdge(9, 11);
    conctg.addEdge(12, 13);
    conctg.addEdge(7, 8);

    cout << "Connecting Road: " << endl;
    conctg.con_road();
    cout << " " << endl;

    junction.addEdge(6, 8);
    junction.addEdge(9, 10);
    junction.addEdge(13, 14);

    junction.addEdge(6, 7);
    junction.addEdge(10, 11);
    junction.addEdge(12, 14);

    junction.addEdge(9, 11);
    junction.addEdge(12, 13);
    junction.addEdge(7, 8);

    cout << "Total junction: " << endl;
    junction.junction();
    cout << " " << endl;
    
    return 0;
}

