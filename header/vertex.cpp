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

////////FRIEND FUNCTIONS/////////////////
bool operator == (vertex &v, char &c)
{
	return (v.name == c) ;
}

//////CLASS FUNCTIONS//////////////////

void vertex::depth_first_search()
{

}

void vertex::breadth_first_search()
{

}


