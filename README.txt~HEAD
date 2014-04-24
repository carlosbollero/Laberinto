=========
Laberinto
=========

TP1 - Algoritmos II - FIUBA

CLASES:

-------------------------------------------------------------------------------
                                MAPA
-------------------------------------------------------------------------------
Atributos:  tamanio;  //ver como lo implementamos

Métodos:    

-------------------------------------------------------------------------------
                                CAMINO
-------------------------------------------------------------------------------
Atributos:  Posicion* puntoInicial;
            informe:cantPosiciones;     //  se puede usar un struct
                    cantBifurcaciones;  //  sirve para los informes
                    cantGiros;          //  del final
                    elementosNoRecogidos//
                    etc;                //
            unsigned int[3] color;      //  para guardar el código de color     //agregado
            Personaje* personaje;       //  para poder manipular el personaje   //agregado
            LectorArchivo* lector;      //  para levantar datos del archivo     //agregado

Métodos:    void agregarPosicion();  //agrega un nuevo nodo al final del camino
            void recorrer();
            Posicion* buscar();
            bool esVacio();
            void setInforme();

-------------------------------------------------------------------------------
                                POSICION
-------------------------------------------------------------------------------
Atributos:  Posicion* nodoNorte;
            Posicion* nodoSur;
            Posicion* nodoEste;
            Posicion* nodoOeste;
            Elemento* elemento;
            

Métodos:    void setNorte/Sur/Este/Oeste();
            Posicion* getNorte/Sur/Este/Oeste();
            void setElemento();



-------------------------------------------------------------------------------
                                PERSONAJE
-------------------------------------------------------------------------------
Atributos:  Mochila* mochila;
            char orientacion;  //Indica hacia donde esta mirando (N,S,E,O)
            Posicion* posicionActual;

Métodos:    void avanzar();
            void retroceder();
            void levantarElemento();
            void tirarElemento();
            Posicion* getPosicionActual();
        
-------------------------------------------------------------------------------
                                MOCHILA
-------------------------------------------------------------------------------
Atributos:  Elemento* primerElemento;   //apunta a una lista de elementos
            
Métodos:    void aniadirElemento();
            void quitarElemento();
            bool esVacia();
            Elemento* buscarElemento();
            void recorrerListaElementos();

-------------------------------------------------------------------------------
                                ELEMENTO
-------------------------------------------------------------------------------
Atributos:  string nombre;  //se asigna en el constructor
            unsigned int cantidad;  //se asigna en el constructor
            Elemento* elementoSiguiente;

Métodos:    void setCantidad();  //ver si conviene separarlo en incCantidad() y decCantidad()
            unsigned int getCantidad();
            void setElementoSiguiente();
            Elemento* getElementoSiguiente();
