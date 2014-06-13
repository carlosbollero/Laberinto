class Vertice{
public:
	Vertice(string nombre);
	~Vertice();

private:
	string nombre;
	Lista<Arista*>* aristas;
	
};