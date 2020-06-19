#include <iostream>
#include<queue>
#include<list>
#include<map>
#include <climits>
using namespace std;
template<typename T>
class Graph
{
    map<T, list<T>> m;
    public:
    void add_edge(T src, T dest, bool bidir =true)
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
            for(T node:p.second)
                cout<<node<<" ";
            cout<<"\n";
        }
    }
    //bfs_single_source_shortest_path
    void bfs_sssp(T src)
    {
        map<T, int> dist;
        queue<T> q;
        for(pair<T, list<T>> p2:m)
        {
            T node =p2.first;
            dist[node] =INT_MAX;
        }
        dist[src] =0;
        q.push(src);
        while(!q.empty())
        {
            T node =q.front();
            q.pop();
            cout<<"("<<node<<" "<<dist[node]<<")";
            for(T nbr:m[node])
            {
                if(dist[nbr]==INT_MAX)
                {
                    q.push(nbr);
                    dist[nbr] =dist[node]+1;
                }
            }
        }
    }
};
int main() {
    Graph<int> g;
    g.add_edge(1,2);
    g.add_edge(1,3);
    g.add_edge(2,4);
    g.add_edge(3,5);
    g.print_graph();
    //BFS_SSSP
    cout<<"BFS SINGLE SOURCE SHORTEST PATH:-";
    g.bfs_sssp(1);

}
