#include <iostream>
#include <list>
using namespace std;

class Graph
{
    int v;
    list<int> *adjList;
    public:
    Graph(int v)
    {
        this->v =v;
        adjList = new list<int>[v];
    }
    //Add_Edge in adjList
    void addEdge(int src, int dest, bool bidir  =true)
    {
        adjList[src].push_back(dest);
        if(bidir)
            adjList[dest].push_back(src);
    }
    //print adj_list of graph
    void printGraphAsAdjList()
    {
        for(int i=0; i<v; i++)
        {
            cout<<i<<" ->";
            for(int nbr:adjList[i])
                cout<<nbr<<" ";
            cout<<"\n";
        }
    }

};
int main() {
    //cout<<"Hello World!";
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(1,3);
    
    //Points to learn 
    //I have added g.addEdge(2, 5); ---> giving me segmentation fault as in
    //printGraphAsAdjList() I am accessing adjList[i] so, adjList[4] will not exist as i 
    // is simple iterator so, it does not know 4 is not a vertex however 5 is.
    g.addEdge(2,4);
    //print graph adj List:--
    g.printGraphAsAdjList();
}
