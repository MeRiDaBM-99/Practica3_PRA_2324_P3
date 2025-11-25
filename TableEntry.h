#ifndef TABLEENTRY_H
#define TABLEENTRY_H

#include <string>
#include <ostream>

using namespace std;

template <typename V> 
class TableEntry {
    public:
	//ATRIBUTOS
	string key;
	V value;

        //MÉTODOS públicos
	//constructores
	TableEntry(string key, V value) : key{key}, value{value} {}
	TableEntry(string key) : key{key} {}
	TableEntry() : key{""} {}

	//sobrecarga de operadores
	friend bool operator==(const TableEntry<V> &te1, const TableEntry<V> &te2){
		if(te1.key == te2.key){
			return true;
		}else{
			return false;
		}
	}

	friend bool operator!=(const TableEntry<V> &te1, const TableEntry<V> &te2){
		if(te1.key != te2.key){
                        return true;
                }else{
                        return false;
                }
	}

	friend ostream& operator<<(ostream &out, const TableEntry<V> &te){
		out = te.key;
		out = "->";
		out = te.value;

		return out;
	}
    
};

#endif
