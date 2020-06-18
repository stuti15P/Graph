#include <iostream>
#include<map>
#include<queue>
#include<list>
using namespace std;
template<typename T>
class Graph
{
    map<T, list<T>> m;
    queue<T> q;
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
            for(int nbr: p.second)
            {
                cout<<nbr<<" ";
            }
            cout<<"\n";
        }
                
    }
    void bfs(T src)
    {
        map<T, bool> visited;
        //for(T node:m.first)
        for(pair<T, list<T>> p:m)
        {
            T node =p.first;
            visited[node] =false;
        }
        q.push(src);
        //cout<<src;
        while(!q.empty())
        {
            T src =q.front();
            q.pop();
            cout<<src<<" ";
            for(T nbrs:m[src])
            {
                if(visited[nbrs]!=true)
                {
                    q.push(nbrs);
                    visited[nbrs] =true;
                }
            }
        }
    }

};

int main() {
    Graph<int> g;
    g.add_edge(1, 3);
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.add_edge(2, 5);
    g.add_edge(3, 5);
    //print graph
    g.print_graph();
    //bfs taversal
    cout<<"BFS TRAVERSAL :-\n";
    g.bfs(1);

}

