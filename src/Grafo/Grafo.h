

class Grafo{
public:
	Grafo();
	~Grafo();
	void agregarVertice();
	Vertice* getVertice();
	void agregarArista();
	//Arista* getArista();
	bool esta(/* coordenada */);

private:
	//Vertice* raiz;
	Lista<Vertice*>* vertices;
	
};