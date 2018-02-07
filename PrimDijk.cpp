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


template <class T>
float prim(Graph<T>& g, T src) {

	auto source = g.vertices.find(src)->second;
	float count = 0;
	int visitedCount = 0;

	source->distance = 0;
	source->visited = true;

	std::priority_queue<Vertex<T> *, std::vector<Vertex<T> *>, bool(*)(Vertex<T> *, Vertex<T> *)> priority_queue(comparePQ);
	
	priority_queue.push(source);

	while(!priority_queue.empty()){
		auto parent = priority_queue.top();
		priority_queue.pop();
		parent->visited = true;
		//reduce runtime by breaking out of loop when everything has been visited
		if(++visitedCount == g.vertices.size()){
			break;
		}
		for(auto it = parent->edges.begin(); it != parent->edges.end(); it++){
			Vertex<T> * neighbor = g.vertices.find(*it)->second;
			if(!neighbor->visited){
				auto length = g.get_weight(parent->id, neighbor->id);
				if(neighbor->distance > length){
					if(neighbor->distance != FLT_MAX){
						count -= neighbor->distance;
					}
					count += length;
					neighbor->distance = length;
					priority_queue.push(neighbor);
				}
			}
		}
	}
  return count;
}



template <class T>
float primdijk(Graph<T>& g, T src, float c) {
	if(c < 0.5){
		//return 5.0;
		return prim(g, src);
	}
	else{
		return dijkstra(g,src);
	}
  // TODO: implement PrimDijk
  //return 0.0;
}
#endif
