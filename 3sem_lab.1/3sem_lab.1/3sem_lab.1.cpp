


#include <iostream>
#include <string>
#include <vector>



#include "CommandsHandling.h"



int main() {

    std::vector<std::string> commands = { "SADD", "SREM", "SISMEMBER", "SPUSH", "SPOP", "QPUSH", "QPOP", "HSET", "HDEL", "HGET" };

    std::cout << "Enter ./dbms --help for options" << std::endl;

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
