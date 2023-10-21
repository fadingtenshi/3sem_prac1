#pragma once



#include <iostream>
#include <string>
#include <vector>



#include "Stack.h"
#include "Queue.h"
#include "HashTable.h"
#include "Set.h"

void sadd(const std::vector<std::string>& args, Set_::Set* setContainer);

void srem(const std::vector<std::string>& args, Set_::Set* setContainer);

void sismember(const std::vector<std::string>& args, Set_::Set* setContainer);

void spush(const std::vector<std::string>& args, Stack_::Stack& stackContainer);

void spop(const std::vector<std::string>& args, Stack_::Stack& stackContainer);

void qpush(const std::vector<std::string>& args, Queue_::Queue* queueContainer);

void qpop(const std::vector<std::string>& args, Queue_::Queue* queueContainer);

void hset(const std::vector<std::string>& args, HashTable_::HashTable* hashTable);

void hdel(const std::vector<std::string>& args, HashTable_::HashTable* hashTable);

void hget(const std::vector<std::string>& args, HashTable_::HashTable* hashTable);

void commandParse(const std::string& command, const std::vector<std::string>& commands);