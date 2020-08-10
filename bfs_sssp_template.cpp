#include<iostream>
#include<queue>
#include<list>
#include<map>
#include <climits>

using namespace std;
template <typename T>
class Graph
{
    int v;
    public:
    map<T, list<T>> m;
    void addEdge(T src, T dest, bool bidir =true)
    {

        m[src].push_back(dest);
        if (bidir)
            m[dest].push_back(src);
    }
    void bfs_sssp(T start)
    {

        map<T, int> dist;
        typename map<T, list<T>>::iterator itr1; //since, T is a template so, we can't write map<T, list<T>>::iterator itr1; It will give compilation error
        for(itr1 =m.begin(); itr1!=m.end(); itr1++)
        {
            T node = itr1->first;
            dist[node] =INT_MAX;
        }

        queue<T> q;
        q.push(start);
        dist[start] =0;
        while(!q.empty())
        {
            T node = q.front();
            q.pop();
            cout<<"("<<node<<",       "<<dist[node]<<")"<<endl;
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

int main()
{

    Graph<int> g;
    cout<<"Node  "<<"Distance from start node"<<endl;
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(2,5);
   // g.addEdge(2,7);
    g.addEdge(5,7);
    g.bfs_sssp(1);
}
