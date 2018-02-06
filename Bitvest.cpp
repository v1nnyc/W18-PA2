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
static float price = 100;

int rateCheck(float start, float firstTF, float exRate, float secondTF){
	return (start * (1-firstTF) * exRate * (1 - secondTF));
}

bool bitvest(std::list<Exchange> exchanges, std::map<std::string, float> fees) {

  //TODO: Implement an algorithm to determine if a profitable trade is possible
  return false;
}
#endif
