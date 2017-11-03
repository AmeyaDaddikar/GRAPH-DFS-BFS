#ifndef VERTEX_H
#define VERTEX_H

#include <list> 		//For adjacency list and visited list
#include <algorithm>	//For std::find() method
#include <queue> 		//For BFS and DFS algorithms
#include <stack>

using namespace std;

class vertex {

private:	
	char name;
	list<vertex> adj_list;

public:
	vertex();
	vertex(char name);
	vertex(const vertex &v);
	
	friend bool operator == (const vertex &v, const char &c);	//COMPARATORS
	friend bool operator == (const char &c,const vertex &v);
	friend bool operator == (const vertex &v1,const vertex &v2);
	
	char getName(){return name;}						//Get functions
	list<vertex>* getAdjList(){return &adj_list;}
	
	void addNeighbour(vertex &v);						//Adds neighbour to adj-list
	
	void depth_first_search();
	void breadth_first_search();

};

#include "vertex.cpp"

#endif
