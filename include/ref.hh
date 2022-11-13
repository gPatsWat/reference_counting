/* This file defines the concept of an Object. Version 1 contains two fields, the reference count, and 1 byte data */
/* The heap is a char array with '#' representing a free memory cell */
#include <iostream>
#include <exception>

#define MAX_SIZE 100

// global heap memory
char heap[MAX_SIZE] = {'#'};
// counter for allocator
volatile int i = 0;

class Object {
    public:
    volatile int r_count;

    //default
    Object (): r_count(0) {}
    //Copy constructor
    Object(volatile Object& o): r_count(o.r_count) {}

    private:

    int rc();
};

class Object_v1 : public Object {
    public:
    Object_v1(): Object() {}
    Object_v1(char* data): data(data) {}
    Object_v1(volatile Object_v1& o): Object(o), data(o.data) {}

    private:
    char* data;
};

class mem_allocator {
    public:

    Object* new_object();

    void write(Object* src, int i, Object* ref);

    private:

    //global heap allocator
    Object_v1* allocate();
};