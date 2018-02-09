// CSE 101 Winter 2018, PA 2
//
// Name: TODO put both partners' info if applicable
// PID: TODO
// Sources of Help: stepik!
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

	Vertex<T>* source = g.vertices.find(src)->second;
	priority_queue.push(source);
	source->distance = 0;
	float total = 0;
	while(!priority_queue.empty()){
		auto vertex = priority_queue.top();
		priority_queue.pop();
		//std::cout<<"pooped: " << vertex->id <<std::endl;
		if(!vertex->visited){
			total += g.get_weight(vertex->id, vertex->prev);
			//std::cout<<"spt +" << g.get_weight(vertex->id, vertex->prev) << std::endl;
		if(!vertex->visited){
			vertex->visited = true;
			int fuck = 0;
			for(auto it = vertex->edges.begin(); it != vertex->edges.end(); it++){
				auto * neighbor = g.vertices.find(*it)->second;
				int fuck = vertex->distance + g.get_weight(vertex->id, neighbor->id);
				if(fuck < neighbor->distance){
					neighbor->prev = vertex->id;
					neighbor->distance = fuck;
					if(!neighbor->visited){
					priority_queue.push(neighbor);
					//std::cout<<"pushing: " << neighbor->id << std::endl;
				}
				}
			}
	}
		
	}
}
	return total;
}

#endif
