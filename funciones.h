#ifndef Graph_H_
#define Graph_H_

#include <string>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
#include <map>
using namespace std;


class Graph {
private:
	int V; 
    map<pair<string,string>,int> city ;
    vector<string> city1;
    vector<string> city2;
    map<int, bool> visited;
    public:
    Graph(int start_V)
    {
        V = start_V;
    }
    void addEdge(string start,string end,int wt);
    void display();
    void DFS(int v);
};

void Graph::addEdge(string start,string end,int wt)
{   
   city[make_pair(start,end)] = wt;
}

void Graph::display()
{   
    int flag=0;
    for(auto it:city)
    {
        city1.push_back(it.first.first);
        city2.push_back(it.first.second);
    }

    sort(city1.begin(), city1.end()); 
    auto last = unique(city1.begin(), city1.end());
    city1.erase(last, city1.end());

    sort(city2.begin(), city2.end()); 
    auto last2 = unique(city2.begin(), city2.end());
    city2.erase(last2, city2.end());

    for(auto col:city2)
    {
        cout<<"\t"<<col;
    }
    cout<<"\n";

    for(auto row:city1)
    {
    int flag =0;   
    for(auto col:city2)
    {
        if (!flag)
            cout<<row;
        cout<<"\t"<<city[make_pair(row,col)];
        flag = 1;
    }
    cout<<"\n";
    }

}
/*
void Graph::DFS(int v)
{
    city.find("v");

    visited[v] = true;
    cout << v << " ";

    list<int>::iterator i;
    for (i = city[v].begin(); i != city[v].end(); ++i)
        if (!visited[*i])
            DFS(*i);
}*/
#endif
