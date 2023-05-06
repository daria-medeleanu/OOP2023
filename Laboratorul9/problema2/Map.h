#pragma once
#include <iostream>
//using namespace std;

template<class K, class V>
class Map
{
private:
	struct Map_Vector {
		K key;
		V value;
		int index;
		Map_Vector() : index(-1) {}
		//constructorul default se apeleaza
	}; 
public:
	class MyIterator {
	public:
		Map_Vector* ptr;

		MyIterator(Map_Vector* ptr): ptr(ptr){}
		void operator++() 
		{ 
			ptr++; 
			//return *this; 
		}
		bool operator != (MyIterator& m) 
		{ 
			return ptr != m.ptr; 
		}
		Map_Vector& operator* ()
		{ 
			return *ptr; 
		}
	};
	int size;
	Map_Vector* vector;
	Map()
	{
		size = 0;
		vector = new Map_Vector[100];
	}
	~Map()
	{
		delete[] vector;
	}
	V& operator[](K key)
	{
		for (int i = 0; i < size; i++)
			if (vector[i].key == key)
				return vector[i].value;
		vector[size].key = key;
		vector[size].index = size;
		size++;
		return vector[size - 1].value;
	}
//a method Set that can be used to associate a value to a key
	void Set(const K& key, const V& value)
	{
		//daca exista deja cheia
		for (int i = 0; i < size; i++)
			if (vector[i].key == key)
			{
				vector[i].value = value;
				return;
			}
		//daca nu exista adaugam un nou element in vector
		vector[size].key = key;
		vector[size].value = value;
		vector[size].index = size;
		size++;
		//if(10 == 10 and 9 == 9 or 1 == 1)
	}
//a method Get that will copy the value associated to parameter key into the parameter value returns true. 
//If the parameter key does not exists in the map, Get method will return false
	bool Get(const K& key, V& value)
	{
		//daca exista cheia key
		for (int i = 0; i < size; i++)
			if (vector[i].key == key)
			{
				value = vector[i].value;
				return true;
			}
		return false;
	}
//a method Count that returns the amount of elements in the map
	int Count()
	{
		return size;
	}
//a method Clear that clears the entire map
	void Clear()
	{
		for (int i = 0; i < size; i++)
		{
			vector[i].key = K();
			vector[i].value = V();
			vector[i].index = -1;
		}
		size = 0;
	}
//a method Delete that deletes a specific key (if exists) 
	bool Delete(const K& key)
	{
		for(int i = 0; i < size; i++)
			if (vector[i].key == key)
			{
				for (int j = i; j < size - 1; j++)
				{
					vector[j] = vector[j + 1];
					vector[j].index = j;
				}
				//ultimul element il resetam la default
				vector[size - 1].key = K();
				vector[size - 1].value = V();
				vector[size - 1].index = -1;
				//scadem size-ul
				size--;
				return true;
			}
		return false;
	}	
//a method Includes that checks if a map is included in another. 
//A map A is included in another map B, if all keys from map A exists in map B
	bool Includes(const Map<K, V>& map)
	{
		for (int i = 0; i < map.size; i++)
		{
			bool found = false;
			for(int j = 0; j < size; j++)
				if (vector[j].key == map[i].key)
				{
					found = true;
					break;
				}
			if (!found)
			{
				return false;
			}
		}
		return true;
	}
	MyIterator begin() {
		return MyIterator(vector);
	}

	MyIterator end() {
		return MyIterator(vector+size);
	}
};