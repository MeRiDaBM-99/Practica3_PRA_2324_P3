#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"

#include "../PRA_2324_P1/ListLinked.h"  // ¡¡¡¡MODIFICAR!!!!

template <typename V>
class HashTable: public Dict<V> {

    private:
        //ATRIBUTOS
	int n;					//Nº elementos almacenados
	int max;				//Tamaño total de la tabla hash
	ListLinked<TableEntry<V>>* table;	//Lista enlazada
		//MÉTODOS
	int h(string key){
		int sum = 0;
        	for (int i = 0; i < key.length(); i++) {
            		sum += int(key.at(i));
        	}
        	return sum % max;
	}

    public:
        //MÉTODOS
	HashTable(int size) : n{0}, max{size}, table{new ListLinked<TableEntry<V>>[max]} {}

        ~HashTable() {
		delete[] table;
	}

	int capacity(){
		return max;
	}

	friend ostream& operator<<(ostream &out, const HashTable<V> &th){
        	for (int i = 0; i < th.max; i++) {
            		out << " Entrada " << i << ": ";
            		out << th.table[i] << endl;
        	}
        	return out;	
	}


	V operator[](string key){
		return search(key);
	}


	//MÉTODOS HEREDADOS DICT
	void insert(string key, V value) override{
		int pos = h(key);
        	ListLinked<TableEntry<V>>& posicion = table[pos];

        	//EXISTE?
        	for (int i = 0; i < posicion.size(); i++) {
            		if (posicion.get(i).key == key) {
                		throw runtime_error("La Key '" + key + "' ya existe");
            		}
        	}

        	//SINO
        	posicion.append(TableEntry<V>(key, value));
        	n++;
	}


	V search(string key) override{
		int pos = h(key);
        	ListLinked<TableEntry<V>>& posicion = table[pos];
        
        	//BUSCAR
        	for (int i = 0; i < posicion.size(); i++) {
            		TableEntry<V> entry = posicion.get(i);
            		if (entry.key == key) {
                		return entry.value;
            		}
        	}
        
        	//SINO SE ENCUENTRA
        	throw runtime_error("La Key '" + key + "' no se ha encontrado");
	}


	V remove(string key) override{
		int pos = h(key);
        	ListLinked<TableEntry<V>>& posicion = table[pos];
        
        	//BUSCAR
        	for (int i = 0; i < posicion.size(); i++) {
            		TableEntry<V> entry = posicion.get(i);
            		if (entry.key == key) {
                		V value = entry.value;
                		posicion.remove(i);
                		n--;
                		return value;
            		}
        	}
        
        	//SINO SE ENCUNTRA
        	throw runtime_error("La Key '" + key + "' no se ha encontrado");
	}


	int entries() override{
		return n;
	}

};

#endif
