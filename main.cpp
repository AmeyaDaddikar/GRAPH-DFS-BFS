#include <iostream>
#include "header/vertex.h"

using namespace std;

int main()
{
	list<vertex> test_list;
	
	test_list.insert(test_list.end(),vertex(1));
	test_list.insert(test_list.end(),vertex(2));
	test_list.insert(test_list.end(),vertex(3));
	test_list.insert(test_list.end(),vertex(4));
	test_list.insert(test_list.end(),vertex(5));
	
	cout << (std::find(test_list.begin(), test_list.end(), 1) != test_list.end())<< endl;
	cout << (std::find(test_list.begin(), test_list.end(), 6) != test_list.end())<< endl; 
	return 0;
}

