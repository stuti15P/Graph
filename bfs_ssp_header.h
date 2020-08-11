#ifndef _BFS_SSP_H
#define _BFS_SSP_H


#include<iostream>
#include<climits>
#include<map>
#include<list>
#include<queue>

using namespace std;
template<typename T>
class Graph
{

    public:
    map<T, list<T> > m;
    void addEdge(T src, T dest, bool bidir =true);
    void printGraph();
    void bfs_ssp(T start);
};


#endif // _BFS_SSp_H
