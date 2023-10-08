#pragma once

#include <string>
#include <iostream>

#define SET_MAX_SIZE 50

typedef std::string S;

namespace Set_ {

	struct Set {

		S key;
		S data;

	};

	unsigned int simpleHash(const std::string& str);

	void initialize(Set* container);

	void insert(Set* container, S new_key, S new_data);

	void remove(Set* container, S key);

	S get(Set* container, S key);

};