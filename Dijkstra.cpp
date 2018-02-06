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

#include <iostream>

template <class T>
bool comparePQ(Vertex<T> * vertex1, Vertex<T> * vertex2){
	return vertex1->distance < vertex2->distance;
}

template <class T>
float dijkstra(Graph<T>&g, T src) {
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
			auto length = vertex->distance + g.get_weight(vertex->id, neighbor->id);
			if(length < neighbor->distance && neighbor->visited != true){
				neighbor->distance = length;
				count += g.get_weight(vertex->id, neighbor->id);
				neighbor->visited = true;
				priority_queue.push(neighbor);
			}
		}
	}
	
  return count;
}

#endif
