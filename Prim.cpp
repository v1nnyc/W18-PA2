// CSE 101 Winter 2018, PA 2
//
// Name: TODO put both partners' info if applicable
// PID: TODO
// Sources of Help: TODO
// Due: February 9th, 2018 at 11:59 PM

#ifndef __PRIM_CPP__
#define __PRIM_CPP__

#include <queue>
#include <vector>

#include "Graph.hpp"
// include more libraries as needed

template <class T>
bool comparePQ(Vertex<T> * vertex1, Vertex<T> * vertex2){
	return vertex1->distance > vertex2->distance;
}

template <class T>
float prim(Graph<T>& g, T src) {

	auto source = g.vertices.find(src)->second;
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
					neighbor->distance = length;
					priority_queue.push(neighbor);
				}
			}
		}
	}

	float total = 0;
	for(auto it = g.vertices.begin(); it != g.vertices.end(); it++){
		total += it->second->distance;
	}

  return total-2;
}
#endif
