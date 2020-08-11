/********Note************************************/
/* since template is there in .h we need to write
    template before every function like below if 
    we are using template T inside a function. */
    
    
#include "bfs_ssp.h"

template<typename T>
void Graph<T>::addEdge(T src, T dest, bool bidir)
{
    m[src].push_back(dest);
    if(bidir)
        m[dest].push_back(src);
}
template<typename T>
void Graph<T>::printGraph()
{
    for(auto nbr_pair: m)
    {
        T node =nbr_pair.first;
        cout<<node<<" ->";
        for(T nbr:nbr_pair.second)
            cout<<nbr<<",";
        cout<<endl;
    }
}
template<typename T>
void Graph<T>::bfs_ssp(T start)
{
    queue<T> q;
    map<T, int> dist;
    for(pair<T, list<T>> nbr_pair: m)
    {
        T node =nbr_pair.first;
        dist[node] =INT_MAX;
    }
    dist[start] =0;
    q.push(start);
    while(!q.empty())
    {
        T node =q.front();
        q.pop();
        cout<<node<<",    "<<dist[node]<<endl;
        for(T nbr:m[node])
        {
            if(dist[nbr] ==INT_MAX)
            {
                dist[nbr] = dist[node] +1;
                q.push(nbr);
            }
        }
    }
}


int main()
{
    Graph<int> g;
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(2,5);
    g.addEdge(5,7);
    g.addEdge(7,9);
    g.printGraph();
    cout<<endl<<"Node Distance from start node"<<endl;
    g.bfs_ssp(1);
    return 0;

}
