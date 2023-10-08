﻿


#include <iostream>
#include <string>
#include <vector>



#include "Stack.h"
#include "Queue.h"
#include "HashTable.h"
#include "Set.h"



void sadd(const std::vector<std::string>& args, Set_::Set* setContainer) {

    if (args.size() != 3) {
        std::cerr << "-> Invalid arguments for SADD" << std::endl;
    }
    else {

        Set_::insert(setContainer, args[1], args[2]);

    }

}

void srem(const std::vector<std::string>& args, Set_::Set* setContainer) {

    if (args.size() != 2) {
        std::cerr << "-> Invalid arguments for SREM" << std::endl;
    }
    else {

        Set_::remove(setContainer, args[1]);

    }

};

void sismember(const std::vector<std::string>& args, Set_::Set* setContainer) {

    if (args.size() != 3) {
        std::cerr << "-> Invalid arguments for SISMEMBER" << std::endl;
    }
    else {

        if (Set_::get(setContainer, args[1]) == args[2]) {

            std::cout << "-> The element is present in the set" << std::endl;

        }
        else {

            std::cout << "-> The element is not present in the set" << std::endl;

        }
    }

}

void spush(const std::vector<std::string>& args, Stack_::Stack& stackContainer) {

    if (args.size() != 2) {
        std::cerr << "-> Invalid arguments for SPUSH" << std::endl;
    }
    else {

        Stack_::push(args[1], &(stackContainer.head));

    }

}

void spop(const std::vector<std::string>& args, Stack_::Stack& stackContainer) {

    if (args.size() != 1) {
        std::cerr << "-> Invalid arguments for SPOP" << std::endl;
    }
    else {

        std::string result = Stack_::pop(&stackContainer.head);

        if (result == "Stack is empty") {

            std::cout << "-> " << result << std::endl;
            return;

        }

        std::cout << "-> Element " << result << " has been deleted" << std::endl;

    }

};

void qpush(const std::vector<std::string>& args, Queue_::Queue* queueContainer) {

    if (args.size() != 2) {
        std::cerr << "-> Invalid arguments for QPUSH" << std::endl;
    }
    else {

        Queue_::push(args[1], queueContainer);

    }

}

void qpop(const std::vector<std::string>& args, Queue_::Queue* queueContainer) {

    if (args.size() != 1) {
        std::cerr << "-> Invalid arguments for QPOP" << std::endl;
    }
    else {

        std::string result = Queue_::pop(queueContainer);

        if (result == "Queue is empty") {

            std::cout << "-> " << result << std::endl;
            return;

        }

        std::cout << "-> Element " << result << " has been deleted" << std::endl;

    }

}

void hset(const std::vector<std::string>& args, HashTable_::HashTable* hashTable) {

    if (args.size() != 3) {
        std::cerr << "-> Invalid arguments for HSET" << std::endl;
    }
    else {

        HashTable_::insert(hashTable, args[1], args[2]);

    }

};

void hdel(const std::vector<std::string>& args, HashTable_::HashTable* hashTable) {

    if (args.size() != 2) {
        std::cerr << "-> Invalid arguments for HDEL" << std::endl;
    }
    else {

        HashTable_::remove(hashTable, args[1]);

    }

};

void hget(const std::vector<std::string>& args, HashTable_::HashTable* hashTable) {

    if (args.size() != 2) {
        std::cerr << "-> Invalid arguments for HGET" << std::endl;
    }
    else {

        std::string result = HashTable_::get(hashTable, args[1]);

        if (result == "A collision has occurred, select another key") {

            std::cout << "-> " << result << std::endl;
            return;

        }

        else if (result == "0") {

            std::cout << "-> Hash table is empty" << std::endl;
            return;

        }

        std::cout << "-> " << result << std::endl;

    }

}

void commandParse(const std::string& command, Set_::Set* commands) {

    static Set_::Set setContainer[SET_MAX_SIZE];


    static HashTable_::HashTable hashTable[HASH_MAX_SIZE];

    static Stack_::Stack stackContainer;

    static Queue_::Queue queueContainer;

    static bool latch = false;
    if (latch == false) {
        Set_::initialize(setContainer);
        HashTable_::initialize(hashTable);
        Stack_::initialize(&stackContainer);
        Queue_::initialize(&queueContainer);
        latch = true;
    }
    std::vector<std::string> args;
    size_t pos = 0;
    std::string delimiter = " ";
    size_t start = 0;

    while ((pos = command.find(delimiter, start)) != std::string::npos) {
        args.push_back(command.substr(start, pos - start));
        start = pos + delimiter.length();
    }

    args.push_back(command.substr(start));

    if (args.size() < 2) {
        std::cerr << "-> Invalid command line arguments" << std::endl;
        return;
    }

    if (args[0] != "./dbms" || args[1] != "--query") {
        std::cerr << "-> Invalid command line arguments" << std::endl;
        return;
    }
    args.erase(args.begin(), args.begin() + 2);

    if (!args.empty()) {
        std::string argument = args[0];
        if (Set_::get(commands, argument) != "0") {

            if (argument == "SADD") {

                sadd(args, setContainer);

            }

            else if (argument == "SREM") {

                srem(args, setContainer);

            }
            else if (argument == "SISMEMBER") {

                sismember(args, setContainer);

            }
            else if (argument == "SPUSH") {

                spush(args, stackContainer);

            }
            else if (argument == "SPOP") {
            
                spop(args, stackContainer);;
            
            }
            else if (argument == "QPUSH") {

                qpush(args, &queueContainer);
            
            }
            else if (argument == "QPOP") {
            
                qpop(args, &queueContainer);
            
            }
            else if (argument == "HSET") {
            
                hset(args, hashTable);
            
            }
            else if (argument == "HDEL") {
            
                hdel(args, hashTable);
            
            }
            else if (argument == "HGET") {
            
                hget(args, hashTable);
            
            }

        }
        else {
            std::cerr << "Invalid command: " << command << std::endl;
        }
    }

}

void insertCommands(Set_::Set* commands) {

    Set_::insert(commands, "SADD", "1");
    Set_::insert(commands, "SREM", "2");
    Set_::insert(commands, "SISMEMBER", "3");
    Set_::insert(commands, "SPUSH", "4");
    Set_::insert(commands, "SPOP", "5");
    Set_::insert(commands, "QPUSH", "6");
    Set_::insert(commands, "QPOP", "7");
    Set_::insert(commands, "HSET", "8");
    Set_::insert(commands, "HDEL", "9");
    Set_::insert(commands, "HGET", "10");

}

int main() {

    Set_::Set commands[SET_MAX_SIZE];
    Set_::initialize(commands);
    insertCommands(commands);

    std::cout << "Enter ./dbms --help for options" << std::endl;

    static HashTable_::HashTable hashTable[HASH_MAX_SIZE];

    while (true) {

        std::string command;

        std::cout << "(@User) ";

        getline(std::cin, command);

        if (command == "./dbms --help") {

            std::cout << "--query:" << std::endl << '\t';
            std::cout << "SADD [KEY] [VALUE]" << std::endl << '\t';
            std::cout << "SREM [KEY]" << std::endl << '\t';
            std::cout << "SISMEMBER [KEY] [VALUE]" << std::endl << '\t';
            std::cout << "SPUSH [KEY]" << std::endl << '\t';
            std::cout << "SPOP [KEY]" << std::endl << '\t';
            std::cout << "QPUSH [KEY]" << std::endl << '\t';
            std::cout << "QPOP [KEY]" << std::endl << '\t';
            std::cout << "HSET [KEY] [VALUE]" << std::endl << '\t';
            std::cout << "HDEL [KEY]" << std::endl << '\t';
            std::cout << "HGET [KEY]" << std::endl << std::endl;
            continue;

        }

        commandParse(command, commands);

    }

}