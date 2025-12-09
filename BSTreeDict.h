#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "BSTree.h"
#include "TableEntry.h"

using namespace std;

template <typename V>
class BSTreeDict: public Dict<V> {

    private:
        //ATRIBUTOS
	BSTree<TableEntry<V>>* tree;

    public:
        //MÉTODOS
	BSTreeDict(){
		tree = new BSTree<TableEntry<V>>();
	}

	~BSTreeDict(){
		delete tree;
	}

	friend ostream& operator<<(ostream &out, const BSTreeDict<V> &bs){
		out << *bs.tree;
		return out;
	}

	V operator[](string key){
		return search(key);
	}

	//MÉTODOS HEREDADOS DE DICT<T>
	void insert(string key, V value) override{
		//Se crea una entrada auxiliar para ver si ya existe la key
		TableEntry<V> prueba(key, V());

		//Verifica si ya existe la key
		try{
			tree->search(prueba);
			throw runtime_error("La key ya existe");
		} catch (const runtime_error&){
			//Si la clase no existe la añadimos
			TableEntry<V> entrada(key, value);
			tree->insert(entrada);
		}
	}

	V search(string key) override{
		TableEntry<V> prueba(key, V());

		try{
			TableEntry<V> result = tree->search(prueba);
			return result.value;
		} catch (const runtime_error&){
			throw runtime_error("La key no se ha encontrado");
		}
	}
        

	V remove(string key) override {
		TableEntry<V> prueba(key, V());

		try{
			TableEntry<V> eliminar = tree->remove(prueba);
			return eliminar.value;
		} catch (const runtime_error&){
			throw runtime_error("La key no se ha encontrado");
		}
	}


	int entries() override {
		return tree->size();
	}
};

#endif
