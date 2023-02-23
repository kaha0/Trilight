#include<VertexEdge.h>

Edge<Vertex>::Edge()
{
	amount = 0.0f;
}

//template<class T>
//Hrana<T>::Hrana()
//{
//	velocity = 0.0f;
//	direction = 0.0f;
//}

Edge<Vertex>::Edge(Vertex * t)
{
	target = t;
	amount = 0.0f;
}

//template<class T>
//Hrana<T>::Hrana(T * t)
//{
//	target = t;
//	velocity = 0.0f;
//	direction = 0.0f;
//}

Vertex::Vertex(Movement movement)
{
	keydowntr = new std::map<WPARAM, Edge<Vertex>>();
	keyuptr = new std::map<WPARAM, Edge<Vertex>>();
	mv = movement;
}

Vertex::Vertex(Movement movement, std::string n)
{
	keydowntr = new std::map<WPARAM, Edge<Vertex>>();
	keyuptr = new std::map<WPARAM, Edge<Vertex>>();
	mv = movement;
	name = n;
}

Vertex::~Vertex()
{
	delete keydowntr;
	delete keyuptr;
}