


#include "Set.h"



unsigned int Set_::simpleHash(const std::string& str) {

	unsigned int hash = 0;

	for (char element : str) {

		hash += static_cast<unsigned int>(element);

	}

	return hash;

}

void Set_::initialize(Set* container) {

	for (short i = 0; i < SET_MAX_SIZE; i++) {

		container[i].key = "0";
		container[i].data = "0";

	}

}

void Set_::insert(Set* container, S new_key, S new_data) {

	int new_key_ = simpleHash(new_key);

	if (container[new_key_ % SET_MAX_SIZE].data != "0") {

		return;

	}

	else {

		container[new_key_ % SET_MAX_SIZE].data = new_data;
		container[new_key_ % SET_MAX_SIZE].key = new_key;

	}
}

void Set_::remove(Set* container, S key) {

	int key_ = simpleHash(key);

	if (container[key_ % SET_MAX_SIZE].data == "0") {

		std::cout << "-> Set is empty" << std::endl;
		return;

	}

	else {

		container[key_ % SET_MAX_SIZE].data = "0";
		container[key_ % SET_MAX_SIZE].key = "0";

	}

}

S Set_::get(Set* container, S key) {

	int key_ = simpleHash(key);

	return container[key_ % SET_MAX_SIZE].data;

}