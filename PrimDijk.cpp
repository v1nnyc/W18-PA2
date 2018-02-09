// CSE 101 Winter 2018, PA 2
//
// Name: TODO put both partners' info if applicable
// PID: TODO
// Sources of Help: TODO
// Due: February 9th, 2018 at 11:59 PM

#ifndef __DIJKSTRA_CPP__
#define __DIJKSTRA_CPP__

#include "Graph.hpp"
// include more libraries as needed
#include <queue>
#include <vector>

//#include "Prim.hpp"
//#include "Dijkstra.hpp"

//dijsktra
template <class T>
bool comparePQ(Vertex<T> * vertex1, Vertex<T> * vertex2){
	return vertex1->distance > vertex2->distance;
}

template <class T>
float primdijk(Graph<T>& g, T src, float c) {
	std::priority_queue<Vertex<T> *, std::vector<Vertex<T> *>, bool(*)(Vertex<T> *, Vertex<T> *)> priority_queue(comparePQ);

	auto source = g.vertices.find(src)->second;
	float count = 0;

	source->distance = 0;
	source->visited = true;
	priority_queue.push(source);

	while(!priority_queue.empty()){
		auto vertex = priority_queue.top();
		priority_queue.pop();
		for(auto it = vertex->edges.begin(); it != vertex->edges.end(); it++){
			Vertex<T> * neighbor = g.vertices.find(*it)->second;
			if(!neighbor->visited){
				auto length = c*vertex->distance + g.get_weight(vertex->id, neighbor->id);
				if(neighbor->distance > length){
					neighbor->distance = length;
					count += g.get_weight(vertex->id, neighbor->id);
					neighbor->visited = true;
					priority_queue.push(neighbor);
				}
			}
		}
	}
	float total = 0;
	for(auto it = g.vertices.begin(); it != g.vertices.end(); it++){
		total += it->second->distance;
	}
	
  return count-2;
}
#endif
