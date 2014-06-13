class Arista{
public:
	Arista(unsigned int longitud);
	~Arista();

private:
	unsigned int longitud
	Vertice* origen;	// no tienen dirección
	Vertice* destino;	// ver otro nombre para esto
};