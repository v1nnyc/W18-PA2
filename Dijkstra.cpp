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
	return vertex1->distance > vertex2->distance;
}

template <class T>
float dijkstra(Graph<T>&g, T src) {
	Vertex<T>* source = g.vertices[src];
	source->distance = 0;
	source->visited = true;
	std::priority_queue<Alarm<T>, std::vector<Alarm<T>>> pq;

	float total = 0;

	for(auto it = source->edges.begin(); it != source->edges.end(); it++){
		T src = source->id;
		T dest = g.vertices[*it]->id;
		float weight = g.get_weight(source->id, *it); 
		
		auto alarm = Alarm<T>(src, dest, weight);
		
		pq.push(alarm);
	}	

	while(!pq.empty()){
		auto cur = pq.top();
		auto dest = g.vertices[cur.dest];
		auto src = g.vertices[cur.src];
		pq.pop();
		if(!dest->visited){
			dest->visited = true;
			dest->prev = src->id;
			total += g.get_weight(dest->id, src->id);
			dest->distance = 
				src->distance 
				+ g.get_weight(dest->id, src->id);
			for(auto it = dest->edges.begin(); it != dest->edges.end(); it++){
				float time = dest->distance + g.get_weight(dest->id, g.vertices[*it]->id);
				auto alarm = Alarm<T>(dest->id, *it, time);
				pq.push(alarm);
			}
		}
	}
	return total ;
}

#endif
