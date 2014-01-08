#include "graph.h"

#include <cassert>
#include <algorithm>
#include <iostream>

namespace algo
{
Edge::Edge(std::initializer_list<std::string> verts)
    : weight(0)
{
    assert(verts.size() == 2);
    this->vertexA = *verts.begin();
    this->vertexB = *std::next(verts.begin());
}

Edge::Edge(const std::string& a, const std::string& b)
    : vertexA(a)
    , vertexB(b)
    , weight(0)
{
}

Edge::Edge(const std::string& a, const std::string& b, double weight)
    : vertexA(a)
    , vertexB(b)
    , weight(weight)
{
}

const std::string& Edge::getVertexA() const
{
    return this->vertexA;
}

const std::string& Edge::getVertexB() const
{
    return this->vertexB;
}

double Edge::getWeight() const
{
    return this->weight;
}

Graph::Graph(std::initializer_list<Edge> edges)
{
    std::for_each(edges.begin(), edges.end(),
    [this](const Edge& edge)
    {
        addEdge(edge);
    });
}

void Graph::addEdge(const Edge& e)
{
    bool inserted = false;
    AdjList::iterator iterForNew = std::prev(this->adjList.end());
    //fisrt try a->b
    if (!inserted)
    {
        auto searchPair = AdjListPair(e.getVertexA(), AdjRow());
        auto i = std::lower_bound(this->adjList.begin(), 
                                  this->adjList.end(), 
                                  searchPair,
                                  [](const AdjListPair& a, const AdjListPair& b) -> bool
                                  {
                                      return std::less<std::string>()(a.first, b.first);
                                  });
        iterForNew = i; 
        if(i != this->adjList.end())
        {
            if (i->first == e.getVertexA())
            {
                auto insertPair = std::make_tuple(e.getVertexB(), e.getWeight(), false);
                auto j = std::lower_bound(i->second.begin(), i->second.end(), insertPair);
                if (j != i->second.end() &&
                    std::get<0>(*j) != std::get<0>(insertPair))
                {
                    i->second.insert(j, insertPair);
                    inserted = true;
                }
                else
                {
                    i->second.push_back(insertPair);
                    inserted = true;
                }
            }
        }   
    }
    if (!inserted) // try b->a
    {
        auto searchPair = AdjListPair(e.getVertexB(), AdjRow());
        auto i = std::lower_bound(this->adjList.begin(), 
                                  this->adjList.end(), 
                                  searchPair,
                                  [](const AdjListPair& a, const AdjListPair& b) -> bool
                                  {
                                      return std::less<std::string>()(a.first, b.first);
                                  });
         
        if(i != this->adjList.end())
        {
            if (i->first == e.getVertexB())
            {
                auto insertPair = std::make_tuple(e.getVertexA(), e.getWeight(), false);
                auto j = std::lower_bound(i->second.begin(), i->second.end(), insertPair);
                if (j != i->second.end() &&
                    std::get<0>(*j) != std::get<0>(insertPair))
                {
                    i->second.insert(j, insertPair);
                    inserted = true;
                }
                else
                {
                    i->second.push_back(insertPair);
                    inserted = true;
                }
            }
        } 
    } 
    if (!inserted) // new vertices
    {
        auto newPair =  AdjListPair(e.getVertexA(), {std::make_tuple(e.getVertexB(), e.getWeight(), false)});
        this->adjList.insert(iterForNew, newPair);
    } 
}

void Graph::breadthFirstVisit(std::function<void (const std::string&)> callback)
{
}

void Graph::depthFirstVisit(std::function<void (const std::string&)> callback)
{
}

void printVert(const std::string& v)
{
    std::cout << v << std::endl;
}

void graph_test()
{
	Graph g = {{"a", "b"}, {"a", "c"}, {"c", "g"}, {"g", "b"}, {"b", "e"}, {"b", "d"}, {"b", "f"}};
    g.breadthFirstVisit(printVert);
    std::cout << std::endl;
    g.depthFirstVisit(printVert);
}
}
