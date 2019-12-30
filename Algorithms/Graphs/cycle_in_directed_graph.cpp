// A C++ Program to detect cycle in a graph
// Language Used: C++
// Output: This algorithm will give the output that whether the graph has cycle or not
// Sample Input:
// Enter the number of vertices
/*  4
   Enter the number of edges
    6
    Enter edge no 1
    0 1
    Enter edge no 2
    0 2
    Enter edge no 3
    1 2
    Enter edge no 4
    2 0
    Enter edge no 5
    2 3
    Enter edge no 6
    3 3      */
//  Sample output:
//  Graph contains cycle
#include<iostream>
#include <list>
#include <limits.h>

using namespace std;

class Graph
{
    int Vertices;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
    bool isCyclicUtil(int v, bool visited[], bool *rs);  // used by isCyclic()
public:
    Graph(int Vertices);   // Constructor
    void addEdge(int v, int w);   // to add an edge to graph
    bool isCyclic();    // returns true if there is a cycle in this graph
};

Graph::Graph(int Vertices)
{
    this->Vertices = Vertices;
    adj = new list<int>[Vertices];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v�s list.
}

// This function is a variation of DFSUtil() in https://www.geeksforgeeks.org/archives/18212
bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack)
{
    if(visited[v] == false)
    {
        // Mark the current node as visited and part of recursion stack
        visited[v] = true;
        recStack[v] = true;

        // Recur for all the vertices adjacent to this vertex
        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) )
                return true;
            else if (recStack[*i])
                return true;
        }

    }
    recStack[v] = false;  // remove the vertex from recursion stack
    return false;
}

// Returns true if the graph contains a cycle, else false.
// This function is a variation of DFS() in https://www.geeksforgeeks.org/archives/18212
bool Graph::isCyclic()
{
    // Mark all the vertices as not visited and not part of recursion
    // stack
    bool *visited = new bool[Vertices];
    bool *recStack = new bool[Vertices];
    for(int i = 0; i < Vertices; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }

    // Call the recursive helper function to detect cycle in different
    // DFS trees
    for(int i = 0; i < Vertices; i++)
        if (isCyclicUtil(i, visited, recStack))
            return true;

    return false;
}

void main()
{
    // Create a graph given in the above diagram
    int no_of_vertices,no_of_edges,value1,value2;
    cout<<"Enter the number of vertices\n";
    cin>>no_of_vertices;
    cout<<"Enter the number of edges\n";
    cin>>no_of_edges;
    Graph g1(no_of_vertices);
    for(int i=0;i<no_of_edges;i++)
    {
        cout<<"Enter edge no "<<i+1<<"\n";
        cin >> value1 >> value2;
        g1.addEdge(value1,value2);
    }

    if(g1.isCyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
}
