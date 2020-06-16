#include <iostream>
#include<map>
#include<list>
using namespace std;
template<typename T>
class Graph
{
    map<T, list<T>> l;
    public:
    void add_edge(T src, T dest, bool bidir =true)
    {
        l[src].push_back(dest);
        if(bidir)
            l[dest].push_back(src);
    }

    void print_graph()
    {
        for(pair<T, list<T>> p:l)
        {
            cout<<p.first<<" ->";
            for(T nbr:p.second)
                cout<<nbr<<" ";
            cout<<"\n";
        }
    }

    void dfs_helper(T src, map<T, bool> &visited)
    {
        cout<<src<<" ";
        visited[src] =true;
        for(T nbr:l[src])
        {
            if(visited[nbr]!=true)
                dfs_helper(nbr, visited);
        }
    }
    void dfs(T src)
    {
        map<T, bool> visited;
        for(pair<T, bool> p:visited)
        {
            p.first= false; 
        }
        dfs_helper(src, visited);
    }
};

int main() {
    Graph<string> g;
    g.add_edge("A", "B");
    g.add_edge("A", "C");
    g.add_edge("B", "E");
    g.add_edge("B", "F");
    //g.add_edge("B", "E");
    g.add_edge("C", "F");
    g.add_edge("A", "D");
    //Print graph
    g.print_graph();
    cout<<"DFS traversal:-\n";
    //DFS traversal of the tree
    g.dfs("A");
}
