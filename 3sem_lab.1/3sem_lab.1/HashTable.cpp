


#include "HashTable.h"



unsigned int HashTable_::simpleHash(const std::string& str) {

	unsigned int hash = 0;

	if (str.length() == 0) {

		return -1;

	}

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
	int hash = new_key_ % HASH_MAX_SIZE;
	int temp_hash = hash;

	if (new_key_ == -1) {

		std::cout << "-> Zero-length key" << std::endl;

	}
	else if (container[hash].key == new_key) {

		std::cout << "-> This key already exist in the hashtable" << std::endl;
		return;

	}
	else {

		int initialHash = hash;

		do {
			if (container[hash].key == "0") {

				container[hash].data = new_data;
				container[hash].key = new_key;
				std::cout <<  "-> Data was inserted" << std::endl;
				return;

			}
			//линейное пробирование
			hash = (hash + 1) % HASH_MAX_SIZE;
		} while (hash != initialHash);

		std::cout << "-> No free slot" << std::endl;

	}
}

void HashTable_::remove(HashTable* container, S key) {

	int key_ = simpleHash(key);
	int hash = key_ % HASH_MAX_SIZE;


	if (key_ == -1) {

		std::cout << "-> Zero-length key" << std::endl;
		return;

	}

	int initialHash = hash;

	do {

		if(container[hash].key == key){

			container[hash].data = "0";
			container[hash].key = "0";
			return;

		}

		//линейное пробирование
		hash = (hash + 1) % HASH_MAX_SIZE;
	} while (hash != initialHash);

	std::cout << "-> Key not found" << std::endl;

}

S HashTable_::get(HashTable* container, S key) {

	int key_ = simpleHash(key);

	if (key_ == -1) {

		return "-> Zero-length key";

	}

	int hash = key_ % HASH_MAX_SIZE;

	int initialHash = hash;

	do {

		if (container[hash].key == key) {

			std::cout << "-> " << container[hash].data << std::endl;
			return "";

		}

		//линейное пробирование
		hash = (hash + 1) % HASH_MAX_SIZE;
	} while (hash != initialHash);

	std::cout << "-> Key not found" << std::endl;
	return "";

}