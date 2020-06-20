#include <iostream>

#include <list>
#include<map>
using namespace std;
template<typename T>
class Graph
{
    map<T, list<T>> m;
    public:
    void add_edge(T src, T dest, bool bidir= true)
    {
        m[src].push_back(dest);
        if(bidir)
            m[dest].push_back(src);
    }
    void print_graph()
    {
        for(pair<T, list<T>> p:m)
        {
            cout<<p.first<<" ->";
            for(int nbr:p.second)
                cout<<nbr<<" ";
            cout<<"\n";
        }
    }
    void dfs_helper(T src, map<T, bool> &visited)
    {
        visited[src] =true;
        cout<<src<<" ";
        for(T nbr:m[src])
        {
            if(!visited[nbr])
                dfs_helper(nbr, visited);

        }
    }
    void dfs()
    {
        map<T, bool> visited;
        for(pair<T, list<T>> p2:m)
        {
            T node =p2.first;
            visited[node] =false;
        }
        int comp =1;
        for(pair<T, bool> p3:visited)
        {
            T node =p3.first;
            
            if(!visited[node])
            {
                cout<<"component "<<comp++<<" ->";
                dfs_helper(node, visited);
            }
            cout<<"\n";
        }
    }
};

int main() {
    Graph<int> g;
    g.add_edge(0,1);
    g.add_edge(0,2);
    g.add_edge(0,3);
    g.add_edge(1,5);
    g.add_edge(2,7);
    g.add_edge(5,9);
    //Single Node
    g.add_edge(14, 14);
    g.add_edge(10, 11);
    //print_graph:-
    g.print_graph();
    g.dfs();
    return 0;
}
    
