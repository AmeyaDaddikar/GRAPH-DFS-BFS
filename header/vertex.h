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
	
	friend bool operator == (vertex &v, char &c);
	friend bool operator == (vertex &v1, vertex &v2);
	
	char getName(){return this->name;}
	
	void depth_first_search();
	void breadth_first_search();

};

#include "vertex.cpp"

#endif
