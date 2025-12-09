#ifndef DICT_H
#define DICT_H

#include <string>

using namespace std;

template <typename V> 
class Dict {
    public:
        // ... aquí los métodos virtuales puros
	virtual void insert(string key, V value) = 0;		//Insertar key->value
	virtual V search(string key) = 0;			//Buscar el value de key
	virtual V remove(string key) = 0; 			//Eliminar key->value
	virtual int entries() = 0; 				//Nº elementos del dicc
};

#endif
