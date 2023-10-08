#pragma once

#include <string>
#include <iostream>

#define HASH_MAX_SIZE 50

typedef std::string S;

namespace HashTable_{

	struct HashTable {

		S key;
		S data;

	};

	unsigned int simpleHash(const std::string& str);

	void initialize(HashTable* container);

	void insert(HashTable* container, S new_key, S new_data);

	void remove(HashTable* container, S key);

	S get(HashTable* container, S key);

};