#ifndef _LIBRARYSYSTEM_CPP_
#define _LIBRARYSYSTEM_CPP_

#include "LibrarySystem.h"
#include <unordered_map>

void LibrarySystem::run(){
    std::unordered_map<std::string, int> logInLogOutContainer(1);

    std::string adminOrClient;
    std::string enter_command;
    std::string filename;
    std::string commandSuffix;

    do{
        std::cout << "> ";
        std::getline(std::cin, enter_command, '\n');

        if(enter_command == "exit"){
            std::cout << "Exiting the program ..." << std::endl;
            break;
        }
        else{
            std::string command;

            for(char symbol : enter_command){
                if(symbol == ' '){
                    break;
                }
                command += symbol;
            }

            enter_command.erase(0, command.length());

            if(command == "close" || command == "save" || command == "help" || command == "login" || command == "logout"){
                try{
                    if(!enter_command.empty()){
                        throw std::invalid_argument("There is no other information after this command!");
                    }
                }
                catch(std::invalid_argument& e){
                    std::cout << e.what() << std::endl;
                    continue;
                }

                if(command == "close"){
                    commands.close(filename);
                }
                else if(command == "save"){
                    commands.save(filename);
                }
                else if(command == "help"){
                    commands.help();
                }
                else if(command == "login"){
                    adminOrClient = "";

                    std::cout << "admin or client? - ";
                    std::getline(std::cin, adminOrClient);

                    if(logInLogOutContainer.find(adminOrClient) != logInLogOutContainer.end()){
                        std::cout << "You are already logged in!" << std::endl;
                    }
                    else{
                        commands.login(adminOrClient);
                        logInLogOutContainer[adminOrClient]++;
                    }
                }
                else if(command == "logout"){
                    logInLogOutContainer.erase(adminOrClient);
                    std::cout << "You are logged out!" << std::endl;
                }
            }
            else if(command == "open" || command == "books" || command == "users"){
                filename = "";
                
                try{
                    if(enter_command.empty()){
                        throw std::invalid_argument("There is other information after this command!");
                    }
                }
                catch(std::invalid_argument& e){
                    std::cout << e.what() << std::endl;
                    continue;
                }

                if(command == "open"){

                    while(enter_command[0] == ' '){
                        enter_command.erase(0,1);
                    }

                    for(char symbol : enter_command){
                        if(symbol == ' '){
                            break;
                        }
                        filename += symbol;
                    }

                    enter_command.erase(0, filename.length());

                    commands.open(filename);
                }
                else if(command == "books"){
                    commandSuffix = "";

                    while(enter_command[0] == ' '){
                        enter_command.erase(0,1);
                    }

                    for(char symbol : enter_command){
                        if(symbol == ' '){
                            break;
                        }
                        commandSuffix += symbol;
                    }

                    enter_command.erase(0, commandSuffix.length());

                    try{
                        if(commandSuffix != "info" && commandSuffix != "find" && commandSuffix != "sort" &&
                            commandSuffix != "add" && commandSuffix != "remove"){
                            throw std::invalid_argument("There is no such suffix after \"books\" command");
                        }
                    }
                    catch(std::invalid_argument& e){
                        std::cout << e.what() << std::endl;
                        std::cout << "After \"books\" command you have to enter all, info, find, sort, add or remove suffix" << std::endl;
                        continue;
                    }
                    
                    if(commandSuffix == "info"){
                        try{
                            if(enter_command.empty()){
                                throw std::invalid_argument("There is other information after this command (isbn_value of the book)!");
                            }

                            if(logInLogOutContainer.find("client") == logInLogOutContainer.end()){
                                throw std::runtime_error("When you use this function you have to be a client!");
                            }
                        }
                        catch(std::invalid_argument& e){
                            std::cout << e.what() << std::endl;
                            continue;
                        }
                        catch(std::runtime_error& e){
                            std::cout << e.what() << std::endl;
                            std::cout << "You have to log out and after that you have to log in as a client, in order to use this function!" << std::endl;
                            continue;
                        }

                        while(enter_command[0] == ' '){
                            enter_command.erase(0,1);
                        }

                        std::string isbn_value;

                        for(char symbol : enter_command){
                            if(symbol == ' '){
                                break;
                            }
                            isbn_value += symbol;
                        }

                        enter_command.erase(0, isbn_value.length());

                        commands.booksInfo(isbn_value);
                    }
                    else if(commandSuffix == "find"){
                        try{
                            if(enter_command.empty()){
                                throw std::invalid_argument("There is other information after this command (given option and option string)!");
                            }

                            if(logInLogOutContainer.find("client") == logInLogOutContainer.end()){
                                throw std::runtime_error("When you use this function you have to be a client!");
                            }
                        }
                        catch(std::invalid_argument& e){
                            std::cout << e.what() << std::endl;
                            continue;
                        }
                        catch(std::runtime_error& e){
                            std::cout << e.what() << std::endl;
                            std::cout << "You have to log out and after that you have to log in as a client, in order to use this function!" << std::endl;
                            continue;
                        }

                        while(enter_command[0] == ' '){
                            enter_command.erase(0,1);
                        }

                        std::string option;

                        for(char symbol : enter_command){
                            if(symbol == ' '){
                                break;
                            }
                            option += symbol;
                        }

                        enter_command.erase(0, option.length());

                        try{
                            if(enter_command.empty()){
                                throw std::invalid_argument("There is other information after this command (option string)!");
                            }
                        }
                        catch(std::invalid_argument& e){
                            std::cout << e.what() << std::endl;
                            continue;
                        }

                        while(enter_command[0] == ' '){
                            enter_command.erase(0,1);
                        }

                        std::string option_string;

                        for(char symbol : enter_command){
                            option_string += symbol;
                        }

                        enter_command.erase(0, option_string.length());

                        commands.booksFind(option, option_string);
                    }
                    else if(commandSuffix == "sort"){
                        try{
                            if(enter_command.empty()){
                                throw std::invalid_argument("There is other information after this command (given option and order (ascending or descending))!");
                            }
                            if(logInLogOutContainer.find("client") == logInLogOutContainer.end()){
                                throw std::runtime_error("When you use this function you have to be a client!");
                            }
                        }
                        catch(std::invalid_argument& e){
                            std::cout << e.what() << std::endl;
                            continue;
                        }
                        catch(std::runtime_error& e){
                            std::cout << e.what() << std::endl;
                            std::cout << "You have to log out and after that you have to log in as a client, in order to use this function!" << std::endl;
                            continue;
                        }

                        while(enter_command[0] == ' '){
                            enter_command.erase(0,1);
                        }

                        std::string option;

                        for(char symbol : enter_command){
                            if(symbol == ' '){
                                break;
                            }
                            option += symbol;
                        }

                        enter_command.erase(0, option.length());

                        if(enter_command.empty()){
                            commands.booksSort(option, "asc");
                        }
                        else{
                            while(enter_command[0] == ' '){
                                enter_command.erase(0,1);
                            }

                            std::string ascOrDesc;

                            for(char symbol : enter_command){
                                if(symbol == ' '){
                                    break;
                                }
                                ascOrDesc += symbol;
                            }

                            enter_command.erase(0, ascOrDesc.length());

                            try{
                                commands.booksSort(option, ascOrDesc);
                            }
                            catch(std::invalid_argument& e){
                                std::cout << e.what() << std::endl;
                                continue;
                            }
                        }
                    }
                    else if(commandSuffix == "add"){
                        try{
                            if(enter_command.empty()){
                                throw std::invalid_argument("There is other information after this command (title)!");
                            }
                            if(logInLogOutContainer.find("admin") == logInLogOutContainer.end()){
                                throw std::runtime_error("When you use this function you have to be an admin!");
                            }
                        }
                        catch(std::invalid_argument& e){
                            std::cout << e.what() << std::endl;
                            continue;
                        }
                        catch(std::runtime_error& e){
                            std::cout << e.what() << std::endl;
                            std::cout << "You have to log out and after that you have to log in as an admin, in order to use this function!" << std::endl;
                            continue;
                        }

                        while(enter_command[0] == ' '){
                            enter_command.erase(0,1);
                        }

                        std::string title;

                        for(char symbol : enter_command){
                            title += symbol;
                        }

                        enter_command.erase(0, title.length());

                        commands.booksAdd(title);
                    }
                    else if(commandSuffix == "remove"){
                        try{
                            if(enter_command.empty()){
                                throw std::invalid_argument("There is other information after this command (title)!");
                            }
                            if(logInLogOutContainer.find("admin") == logInLogOutContainer.end()){
                                throw std::runtime_error("When you use this function you have to be an admin!");
                            }
                        }
                        catch(std::invalid_argument& e){
                            std::cout << e.what() << std::endl;
                            continue;
                        }
                        catch(std::runtime_error& e){
                            std::cout << e.what() << std::endl;
                            std::cout << "You have to log out and after that you have to log in as an admin, in order to use this function!" << std::endl;
                            continue;
                        }

                        while(enter_command[0] == ' '){
                            enter_command.erase(0,1);
                        }

                        std::string title;

                        for(char symbol : enter_command){
                            title += symbol;
                        }

                        enter_command.erase(0, title.length());

                        commands.booksRemove(title);
                    }
                }
                else if(command == "users"){
                    commandSuffix = "";

                    while(enter_command[0] == ' '){
                        enter_command.erase(0,1);
                    }

                    for(char symbol : enter_command){
                        if(symbol == ' '){
                            break;
                        }
                        commandSuffix += symbol;
                    }

                    enter_command.erase(0, commandSuffix.length());

                    try{
                        if(commandSuffix != "add" && commandSuffix != "remove"){
                            throw std::invalid_argument("There is no such suffix after \"users\" command");
                        }
                    }
                    catch(std::invalid_argument& e){
                        std::cout << e.what() << std::endl;
                        std::cout << "After \"users\" command you have to enter add or remove suffix" << std::endl;
                        continue;
                    }

                    if(commandSuffix == "add"){
                        try{
                            if(enter_command.empty()){
                                throw std::invalid_argument("There is other information after this command (username and password)!");
                            }
                        }
                        catch(std::invalid_argument& e){
                            std::cout << e.what() << std::endl;
                            continue;
                        }

                        while(enter_command[0] == ' '){
                            enter_command.erase(0,1);
                        }

                        std::string username;

                        for(char symbol : enter_command){
                            if(symbol == ' '){
                                break;
                            }
                            username += symbol;
                        }

                        enter_command.erase(0, username.length());

                        try{
                            if(enter_command.empty()){
                                throw std::invalid_argument("There is other information after this command (password)!");
                            }
                        }
                        catch(std::invalid_argument& e){
                            std::cout << e.what() << std::endl;
                            continue;
                        }

                        while(enter_command[0] == ' '){
                            enter_command.erase(0,1);
                        }

                        std::string password;

                        for(char symbol : enter_command){
                            if(symbol == ' '){
                                break;
                            }
                            password += symbol;
                        }

                        enter_command.erase(0, password.length());

                        commands.usersAdd(username, password);
                    }
                    else if(commandSuffix == "remove"){
                        try{
                            if(enter_command.empty()){
                                throw std::invalid_argument("There is other information after this command (username)!");
                            }
                            if(logInLogOutContainer.find("admin") == logInLogOutContainer.end()){
                                throw std::runtime_error("When you use this function you have to be an admin!");
                            }
                        }
                        catch(std::invalid_argument& e){
                            std::cout << e.what() << std::endl;
                            continue;
                        }
                        catch(std::runtime_error& e){
                            std::cout << e.what() << std::endl;
                            std::cout << "You have to log out and after that you have to log in as an admin, in order to use this function!" << std::endl;
                            continue;
                        }

                        while(enter_command[0] == ' '){
                            enter_command.erase(0,1);
                        }

                        std::string username;

                        for(char symbol : enter_command){
                            if(symbol == ' '){
                                break;
                            }
                            username += symbol;
                        }

                        enter_command.erase(0, username.length());

                        commands.usersRemove(username);
                    }
                }
            }
            else{
                std::cout << "The system does not support such an operation! Type \"help\" for to see the list of supported commands." << std::endl;
            }
        }
    }while(true);
}

#endif