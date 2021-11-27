#ifndef weight_H_
#define weight_H_

#include<iostream>
#include <vector>
#include "DiGrapht.h"

using namespace std;


template <class VertexType>
class weightedGraph : public DiGraphType<VertexType, bool>
{
public:
    weightedGraph(int max);
};

template <class VertexType>
weightedGraph<VertexType>::weightedGraph(int max)
{
    this->size = 0;
    this->vertices.resize(max);
    //Inicializamos la matriz

    this->edges.resize(max);

    for (int i = 0; i < max; i++)
    {
        this->edges[i].resize(max, 0);
    }
}
#endif