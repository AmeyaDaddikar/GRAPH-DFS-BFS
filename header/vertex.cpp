typedef list<vertex> VERTEX_LIST;
//////////CONSTRUCTORS/////////////////////
vertex::vertex()
{
	this->name = 65;
	this->adj_list = list<vertex> ();
}

vertex::vertex(char name)
{
	this->name = name;
	this->adj_list = list<vertex> ();
}

////////FRIEND FUNCTIONS (COMPARATORS)/////////////////
bool operator == (const vertex &v,const char &c)
{
	return (v.name == c) ;
}

bool operator == (const char &c,const vertex &v)
{
	return (v.name == c) ;
}

bool operator == (const vertex &v1,const vertex &v2)
{
	return (v1.name == v2.name) ;
}

//////CLASS FUNCTIONS//////////////////

void vertex::addNeighbour(vertex &v)
{
	if(std::find(this->adj_list.begin(),this->adj_list.end(), v) != this->adj_list.end())
		cout << "LIST ALREADY CONTAINS THE VERTEX" << endl;
	else
		this->adj_list.insert(adj_list.end(),v);
}

void vertex::depth_first_search()
{
	stack<vertex> vertex_stack;
	list<vertex> visited_list;
	
	vertex_stack.push(*this);
	
	while(vertex_stack.size() != 0)
	{
		vertex curr_vertex = vertex_stack.top();
		vertex_stack.pop();
		
		cout << curr_vertex.getName() << ' ';
		
		VERTEX_LIST &neighbour_list = curr_vertex.getAdjList();
		
		for(VERTEX_LIST::iterator it = neighbour_list.begin(); it != neighbour_list.end(); it++)
		{
			vertex *neighbour = &(*it);
			
			if(std::find(visited_list.begin(),visited_list.end(), *neighbour) == visited_list.end())
				vertex_stack.push(*neighbour);
		}
	}
	cout << endl;
}

void vertex::breadth_first_search()
{
	queue<vertex> vertex_queue;
	list<vertex> visited_list;

	vertex_queue.push(*this);
	
	while(vertex_queue.size() != 0)
	{
		vertex curr_vertex = vertex_queue.front();		
		vertex_queue.pop();
		
		cout << curr_vertex.getName() << ' ';
		
		VERTEX_LIST &neighbour_list = curr_vertex.getAdjList();

		for(VERTEX_LIST::iterator it = neighbour_list.begin(); it != neighbour_list.end(); it++)
		{
			vertex *neighbour = &(*it);
			
			if(std::find(visited_list.begin(),visited_list.end(), *neighbour) == visited_list.end())
				vertex_queue.push(*neighbour);					
		}
	}
	cout << endl;
}



