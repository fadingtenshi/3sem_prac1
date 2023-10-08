


#include "HashTable.h"



unsigned int HashTable_::simpleHash(const std::string& str) {

	unsigned int hash = 0;

	for (char element : str) {

		hash += static_cast<unsigned int>(element);

	}

	return hash;

}

void HashTable_::initialize(HashTable* container) {

	for (short i = 0; i < HASH_MAX_SIZE; i++) {

		container[i].key = "0";
		container[i].data = "0";

	}

}

void HashTable_::insert(HashTable* container, S new_key, S new_data) {

	int new_key_ = simpleHash(new_key);

	if (container[new_key_ % HASH_MAX_SIZE].data != "0") {

		return;

	}

	else {

		container[new_key_ % HASH_MAX_SIZE].data = new_data;
		container[new_key_ % HASH_MAX_SIZE].key = new_key;

	}
}

void HashTable_::remove(HashTable* container, S key) {

	int key_ = simpleHash(key);
	int hash = key_ % HASH_MAX_SIZE;

	if (container[hash].data == "0") {

		std::cout << "-> Slot is empty" << std::endl;
		return;

	}

	else if (container[hash].key != key) {

		std::cout << "-> A collision has occurred, select another key" << std::endl;
		return;

	}

	else {

		container[hash].data = "0";
		container[hash].key = "0";
		return;

	}

}


S HashTable_::get(HashTable* container, S key) {

	int key_ = simpleHash(key);
	int hash = key_ % HASH_MAX_SIZE;

	if (container[hash].key == "0") {

		return "Slot is empty";

	}

	if (container[hash].key != key) {
		return "A collision has occurred, select another key";
	}

	return container[hash].data;

}