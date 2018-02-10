// CSE 101 Winter 2018, PA 2
//
// Name: TODO put both partners' info if applicable
// PID: TODO
// Sources of Help: TODO
// Due: February 9th, 2018 at 11:59 PM

#ifndef __BITVEST_CPP__
#define __BITVEST_CPP__

#include <list>
#include <string>
#include <set>
#include <map>

#include "Graph.hpp"
#include "Bitvest.hpp"
// include more libraries as needed
static float startPrice = 100;

float rateCheck(float start, float firstTF, float exRate, float secondTF){
	return (start * (1-firstTF) * exRate * (1 - secondTF));
}

bool bitvest(std::list<Exchange> exchanges, std::map<std::string, float> fees) {
	std::map<std::string, float> weights;
	//std::map<std::string, float> origWeights;
	for(auto itFees = fees.begin(); itFees != fees.end(); itFees++){
		weights.emplace(itFees->first, 0);
		//origWeights.emplace(itFees->first, 0);
	}

	auto startIt = weights.find(fees.begin()->first);
	startIt->second = startPrice;
	auto startt = startIt->first;
	auto curr = startt;
	
	for(int i = 0; i < 2; i++){
	//iterate through fees like vertices
		for(auto itFees = fees.begin(); itFees != fees.end(); itFees++){
			//for each edge u,v
			for(auto itEx = exchanges.begin(); itEx != exchanges.end(); itEx++){
				curr = itFees->first;
				//updating weight of each "vertex"
				if(itEx->in == curr){
					std::cout<<"curr is: " << curr << "\n";
					float start = weights.find(curr)->second;
					float firstTF = fees.find(curr)->second;
					float exRate = itEx->rate;
					float secondTF = fees.find(itEx->out)->second;	
					float rate = rateCheck(start, firstTF, exRate, secondTF);
					if(rate > weights.find(itEx->out)->second){
						weights.find(itEx->out)->second = rate;
						std::cout<< "rate for: " <<  itEx->out <<"is: " << rate << "\n";
					}
					
				}
			}
		}
	}

	if(startIt->second > startPrice){
		return true;
	}
  //TODO: Implement an algorithm to determine if a profitable trade is possible
  return false;
}
#endif
