#ifndef DICT_H
#define DICT_H
#include <string>

template <typename V> 
class Dict {
    public:
        // ... aquí los métodos virtuales puros
	void insert(std::string key, V value) = 0;	//Insertar key->value
	V search(std::string key) = 0;			//Buscar el value de key
	V remove(std::string key) = 0; 			//Eliminar key->value
	int entries() = 0; 				//Nº elementos del dicc
};

#endif
