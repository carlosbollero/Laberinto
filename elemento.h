#include <iostream>
#include <string>
#ifndef ELEMENTO_H
#define ELEMENTO_H

using namespace std;

class Elemento {
    private:
        string nombre;
        int cantidad;

    public:
        /* Post: Devuelve un nuevo elemento cuyo nombre se recibe por parametro y su cantidad inicial es 1 */
        Elemento (string nombre);

        /* Post: Devuelve la cantidad total del mismo elemento que hay */
        int getCantidad ();

        /* Post: Devuelve el nombre del elemento */
        string getNombre ();

        /* Post: Hay un elemento mas si se recogio uno, o uno menos si se solto uno */
        void modificarCantidad (int nuevoselementos);
};

#endif // ELEMENTO_H
