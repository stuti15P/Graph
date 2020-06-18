#include <iostream>
#include<map>
#include<list>
#include<queue>
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
            for(T nbrs:p.second)
                cout<<nbrs<<" ";
            cout<<"\n";
        }
    }
    void bfs_helper(T src, map<T, bool> &visited)
    {
       // cout<<src<<" ";
        //visited[src] =true;
        q.push(src);
        while(!q.empty())
        {
            for(T nbr:m[src])
            {
                if(visited[nbr]==false)
                {
                    q.push(nbr);
                }
            }
            src= q.front();
            cout<<src<<" ";
            visited[src] =true;
            q.pop();
        }
    }
    void bfs(T src)
    {
        map<T, bool> visited;
        for(pair<T, list<T>> p2:m)
        {
            T node =p2.first;
            visited[node] =false;
        }
        q.push(src);
        visited[src] =true;
        while(!q.empty())
        {
            src= q.front();
            q.pop();
            cout<<src<<" ";
            
            for(T nbr:m[src])
            {
                if(visited[nbr]==false)
                {
                    q.push(nbr);
                    visited[nbr]= true;
                }
            }
            
        }
        
    }
};




int main() {
    Graph<int> g;
    g.add_edge(1,2);
    g.add_edge(1,3);
    g.add_edge(3,4);
    g.add_edge(1,6);
    g.add_edge(4,7);
    g.add_edge(3,5);
    g.add_edge(5,9);
    g.add_edge(3,11);
    g.add_edge(4,10);
    //print graph
    g.print_graph();
    //print bfs
    cout<<"BFS:---\n";
    g.bfs(1);

}
