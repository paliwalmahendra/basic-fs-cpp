#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <unistd.h>

void executeCommand(const std::string& command) {
    int result = system(command.c_str());
    if (result != 0) {
        std::cerr << "Error executing command: " << command << std::endl;
    }
}

void cd(const std::string& directory) {
    int result = chdir(directory.c_str());
    if (result != 0) {
        std::cerr << "Error changing directory to: " << directory << std::endl;
    }
}

int main() {
    std::string input;
    
    while (true) {
        std::cout << "Enter a command (or 'exit' to quit): ";
        std::getline(std::cin, input);

        if (input == "exit") {
            break;
        }

        std::istringstream iss(input);
        std::string command;
        iss >> command;

        if (command == "cd") {
            std::string directory;
            iss >> directory;
            cd(directory);
        } else if (command == "mkdir" || command == "cp" || command == "rm" || command == "touch" || command == "mv" || command == "cat" || command == "echo" || command == "grep" || command == "ls") {
            executeCommand(input);
        } else {
            std::cerr << "Unknown command: " << command << std::endl;
        }
    }

    return 0;
}
