#ifndef _LIBRARYSYSTEM_H_
#define _LIBRARYSYSTEM_H_

#include "Commands.cpp"

struct LibrarySystem{
    private:
        Commands commands;

    public:
        void run();
};


#endif