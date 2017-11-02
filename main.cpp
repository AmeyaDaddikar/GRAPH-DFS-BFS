#include <iostream>
#include "header/vertex.h"

using namespace std;

//To check if an element is in the list
//(std::find(test_list.begin(), vertex_list.end(), 1) != vertex_list.end())
typedef list<vertex> VERTEX_LIST;
int main()
{
	char v_name;
	VERTEX_LIST vertex_list;
	VERTEX_LIST::iterator start_vertex;
	bool option_flag = false;
	
	cout << "This program works best for simple directed and undirected graphs." << endl;
	cout << "Multigraphs can also be enabled quite easily (by changing one line in source code" << endl;
	cout << "However, a multigraph doesn't serve any purpose for dfs and bfs algorithms." << endl;
	
	do{		
		cout << "Give a vertex name ... (NAME SHOULD BE 1 character LONG)" << endl;
		cin >> v_name;
		vertex_list.insert(vertex_list.end(),vertex(v_name));
		
		cout << "Enter another vertex ? ...\n PRESS 0 FOR NO" << endl;
		cin >> option_flag;
		
	}while(option_flag);
	
	cout << "----THE VERTEX LIST----------------------------------------" << endl;	
	for(VERTEX_LIST::iterator it = vertex_list.begin(); it != vertex_list.end(); it++)
		cout << it->getName() << ' ';
	
	cout << endl;
	cout << "-----------------------------------------------------------" << endl;
	
	for(VERTEX_LIST::iterator it = vertex_list.begin(); it != vertex_list.end(); it++)
	{
		cout << "CURRENT VERTEX : " << it->getName() << endl;
		
		while(true)
		{
			cout << "Add neighbour for VERTEX : " << it->getName() << " ? ..." << endl;
			cout << "PRESS 0 FOR NO" << endl;
			
			cin >> option_flag;
			if(!option_flag)
				break;
			
			cout << "Enter the vertex name to be added ... (NAME SHOULD BE 1 character LONG)" << endl;
			cin >> v_name;
			
			VERTEX_LIST::iterator neighbour = find(vertex_list.begin(), vertex_list.end(), v_name);
			
			if(neighbour == vertex_list.end())
				cout << "CAN'T FIND THE VERTEX NAME" << endl;
			else
			{
				it->addNeighbour(*neighbour);
				cout << "VERTEX " << neighbour->getName() << " set as neighbour of " << it->getName() << endl; 
			}
		}
		
		cout << "ADJACENT LIST OF VERTEX " << it->getName() << endl;
		VERTEX_LIST &adj_list = it->getAdjList();
		
		for(VERTEX_LIST::iterator curr = adj_list.begin(); curr != adj_list.end(); curr++)
			cout << curr->getName() << ' ';
		
		cout << endl;
		cout << "-----------------------------------------------------------" << endl;
		
	}
	
	while(true)
	{
		cout << "----THE VERTEX LIST----------------------------------------" << endl;	
		for(VERTEX_LIST::iterator it = vertex_list.begin(); it != vertex_list.end(); it++)
			cout << it->getName() << ' ';

		cout << endl;
		cout << "-----------------------------------------------------------" << endl;
		
		cout << "Enter the vertex name to be considered as start vertex ... (NAME SHOULD BE 1 character LONG)" << endl;
		cin >> v_name;
		
		start_vertex = find(vertex_list.begin(), vertex_list.end(), v_name);
		
		if(start_vertex == vertex_list.end())
			cout << "CAN'T FIND THE VERTEX NAME" << endl;
		else			
			break;
	}
	
	return 0;
}
 
