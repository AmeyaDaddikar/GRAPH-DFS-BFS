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
		this->adj_list.insert(adj_list.end(),v);
	else
		cout << "LIST ALREADY CONTAINS THE VERTEX" << endl;
}

void vertex::depth_first_search()
{

}

void vertex::breadth_first_search()
{

}



