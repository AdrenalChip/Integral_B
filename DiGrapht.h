#ifndef DiGrapht_H_
#define DiGrapht_H_

#include <vector>
#include <queue>
#include <stack>
#include <iostream>

using namespace std;

template <class VertexType, class EdgeType>
class DiGraphType
{
  public:
    void addVertex(VertexType);
    void addEdge(VertexType, VertexType, EdgeType);
    int getIndex(VertexType);
    void printAdjancencyMatrix();
    void getAdjacents(VertexType, queue<VertexType> &);
    void printVertices();
    vector<VertexType> getVertices();
    void TS(stack<VertexType> &answer);
    bool isDAG();
    void DFS(VertexType, VertexType); // buscamos por stack
    void BFS(VertexType, VertexType); // buscamos por queue
    
    void DFS(int index, vector<bool> &visited, stack<VertexType> &answer);
    bool DFS(int index, vector<int> &colors);

  protected:
    int size;
    vector<vector<EdgeType>> edges;
    vector<VertexType> vertices;
};

template <class VertexType, class EdgeType> 
void DiGraphType<VertexType, EdgeType>::addVertex(VertexType vertex)
{
  vertices[size++] = vertex;
}

template <class VertexType, class EdgeType>
void DiGraphType<VertexType, EdgeType>::addEdge(VertexType fromVertex, VertexType toVertex, EdgeType value)
{ 
  int row = getIndex(fromVertex);
  int col = getIndex(toVertex);

  edges[row][col] = value;
}

template <class VertexType, class EdgeType>
int DiGraphType<VertexType, EdgeType>::getIndex(VertexType vertex)
{
  for (int i=0; i<size;i++)
  {
    if (vertices[i]== vertex)
    {
      return i;
    }
  }

  return -1;
}

template <class VertexType, class EdgeType>
void DiGraphType<VertexType, EdgeType>::printAdjancencyMatrix()
{
  for (int i=0; i<size;i++)
  {
    for(int j=0; j<size;j++)
    {
      cout << edges[i][j] << " ";
    }
    cout << endl;
  }
}

template <class VertexType, class EdgeType>
void DiGraphType<VertexType, EdgeType>::printVertices()
{
  for (int i = 0; i<size;i++)
  {

      cout << vertices[i] << " -> "<<endl;

  }
}

template <class VertexType, class EdgeType>
vector<VertexType> DiGraphType<VertexType, EdgeType>::getVertices()
{
  return vertices;
}

template <class VertexType, class EdgeType>
void DiGraphType<VertexType, EdgeType>::DFS(VertexType fromVertex, VertexType toVertex)
{
  stack<VertexType> searching;
  queue<VertexType> adjacents;
  int index;
  vector<bool> visited(size, false);
  bool found = false;

  VertexType vertex;
  VertexType neighbour;

  searching.push(fromVertex);

  while(!searching.empty() && !found)
  {
    vertex = searching.top();
    searching.pop();
    //index = getIndex(vertex);
    //visited(index)=true;

    if (vertex == toVertex)
    {
      cout << vertex << endl;
      found = true;
    }
    else
    {
      index = getIndex(vertex);

      if (!visited[index])
      {
        visited[index] = true;
        //cout << vertex << endl;
        getAdjacents(vertex, adjacents);

        cout << vertex <<"---> ";

        while(!adjacents.empty())
        {
          neighbour = adjacents.front();
          adjacents.pop();

          index = getIndex(neighbour);

          if(!visited[index])
          {
            searching.push(neighbour);
          }
        }
      }
    }
  }
}

template <class VertexType, class EdgeType>
void DiGraphType<VertexType, EdgeType>::BFS(VertexType fromVertex, VertexType toVertex)
{
  queue<VertexType> searching;
  int index;
  queue<VertexType> adjacents;
  vector<bool> visited(size, false);
  bool found = false;

  VertexType vertex;
  VertexType neighbour;

  searching.push(fromVertex);

  while(!searching.empty() && !found)
  {
    vertex = searching.front();
    searching.pop();
    //index = getIndex(vertex);
    //visited(index)=true;

    if (vertex == toVertex)
    {
      cout << vertex << endl;
      found = true;
    }
    else
    {
      index = getIndex(vertex);

      if (!visited[index])
      {
        visited[index] = true;
        //cout << vertex << endl;
        getAdjacents(vertex, adjacents);

        cout << vertex << endl;

        while(!adjacents.empty())
        {
          neighbour = adjacents.front();
          adjacents.pop();

          index = getIndex(neighbour);

          if(!visited[index])
          {
            searching.push(neighbour);
          }
        }
      }
    }
  }
}

template <class VertexType, class EdgeType>
bool DiGraphType<VertexType, EdgeType>::isDAG()
{
  vector<int> colors(size,0);

  for (int i=0; i<size; i++)
  {
    if (colors[i]== 0)
    {
      if (DFS(i,colors))
      {
        return true;
      }
    }
  }
  return false;
}

template <class VertexType, class EdgeType>
bool DiGraphType<VertexType, EdgeType>::DFS(int index, vector<int> &colors)
{
  queue<VertexType> adjacents;
  VertexType neighbour;

  colors[index] = 1; //marcamos de gris

  getAdjacents(vertices[index], adjacents); 

  while(!adjacents.empty())
  {
    neighbour = adjacents.front();
    adjacents.pop();

    int neighbourIndex = getIndex(neighbour);

    if(colors[neighbourIndex] == 0)
    {
      if (DFS(neighbourIndex, colors))
      {
        return true;
      }
    }
    else if (colors[neighbourIndex] == 1)
    {
      return true;
    }
  }
  colors[index] = 2; //se marca en negro
  return false; //no hay ciclo
}

template <class VertexType, class EdgeType>
void DiGraphType<VertexType, EdgeType>::TS(stack<VertexType> &answer)
{
  vector<bool> visited(size, false);

  for(int i =0; i<size; i++)
  {
    if(!visited[i])
    {
      DFS(i,visited,answer);
    }
  }

  while(!answer.empty())
  {
    cout << answer.top() << endl;
    answer.pop();
  }
}

template <class VertexType, class EdgeType>
void DiGraphType<VertexType, EdgeType>::DFS(int index, vector<bool> &visited, stack<VertexType> &answer)
{
  queue<VertexType> adjacents;

  VertexType neighbour;

  visited[index] = true; //se marca como visitado

  getAdjacents(vertices[index], adjacents);

  while(!adjacents.empty()) //se revisan adyacentes
  {
    neighbour = adjacents.front(); //obtenemos un adjacente
    adjacents.pop(); // Quitamos del queue de vertices a revisar

    int indexNeighbour = getIndex(neighbour);

    if (!visited[indexNeighbour]) //si no se ha visitado antes ese vÃ©rtice
    {
      DFS(indexNeighbour, visited, answer); // Hacemos DFS
    }
  }  
  answer.push(vertices[index]);
}

template <class VertexType, class EdgeType>
void DiGraphType<VertexType, EdgeType>::getAdjacents(VertexType vertex, queue<VertexType> &adjacents)
{
  int fromVertex = getIndex(vertex);

  for (int toVertex = 0; toVertex < size; toVertex++)
  {
    if (edges[fromVertex][toVertex]>0 && toVertex != fromVertex)
    {
      adjacents.push(vertices[toVertex]);
    }
  }
}
#endif