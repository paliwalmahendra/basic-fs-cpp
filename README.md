Basic Command-Line Shell
The Basic Command-Line Shell is a simple shell-like program implemented in C++. It provides a basic interactive command-line interface that allows users to execute commands, change directories, and perform various file-related operations.

Features
Command Execution:

The shell allows users to execute various shell commands such as mkdir, cp, rm, touch, mv, cat, echo, and grep.
Change Directory (cd):

Users can change the current working directory using the cd command followed by the desired directory path.
Exit the Shell:

The shell provides a graceful exit option. Typing "exit" will terminate the program.
Getting Started
Compilation
To compile the program, use the following command:

bash
Copy code
g++ -o shell main.cpp
Running the Shell
After compilation, run the shell using the following command:

bash
Copy code
./shell
Usage
The Basic Command-Line Shell offers a simple interactive interface. Users can enter commands and interact with the shell using the following guidelines:

Executing Commands:

Enter any of the supported commands (e.g., mkdir, cp, rm, etc.) followed by relevant arguments.
Changing Directory (cd):

Change the current working directory using the cd command followed by the desired directory path.
Exiting the Shell:

To exit the shell, type "exit" and press Enter.
Example Commands
Create a Directory:

bash
Copy code
mkdir new_directory
Change Directory:

bash
Copy code
cd /path/to/directory
Copy a File:

bash
Copy code
cp source_file destination
Remove a File:

bash
Copy code
rm file_to_remove
Read File Content:

bash
Copy code
cat filename
Exit the Shell:

bash
Copy code
exit
