#ifndef _GRAPH_H_

#include <cstddef>
#include <vector>
#include <string>
#include <functional>
#include <set>
#include <list>
#include <tuple>

namespace algo
{
	
class Edge
{
public:
    Edge(std::initializer_list<std::string> verts);
	Edge(const std::string& a, const std::string& b);
	Edge(const std::string& a, const std::string& b, double weight);
	const std::string& getVertexA() const;
	const std::string& getVertexB() const;
	double getWeight() const;
private:
	std::string vertexA;
	std::string vertexB;
	double weight;
};
	
    
class Graph
{
public:
	Graph(std::initializer_list<Edge> edges);
    void addEdge(const Edge& e);
    void breadthFirstVisit(std::function<void (const std::string&)> callback);
    void depthFirstVisit(std::function<void (const std::string&)> callback);
private:
    void cleanMarks();
private:
    typedef std::tuple<std::string, double, bool> AdjRowValue;
    typedef std::list<AdjRowValue> AdjRow;
    typedef std::pair<std::string, AdjRow> AdjListPair;
    typedef std::list<AdjListPair> AdjList;
    AdjList adjList;
};

void graph_test();
}

#endif
