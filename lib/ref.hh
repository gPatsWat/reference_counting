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


    virtual Object* new_object() = 0;
    virtual Object write(Object* src, int i, Object* ref) = 0;

    private:
    virtual Object* allocate() = 0;

    int rc() {
        return this->r_count;
    }
};

class Object_v1 : Object {
    public:
    Object_v1(): Object() {}
    Object_v1(char* data): data(data) {}
    Object_v1(volatile Object_v1& o): Object(o), data(o.data) {}

    Object* new_object() {
        Object* ref = allocate();
        if( ref == nullptr ) {
            throw std::runtime_error("Out of memory!");
        }
        return ref;
    }

    Object write(Object* src, int i, Object* ref) {

    }

    private:
    char* data;

    //global heap allocator
    Object* allocate() {
        for(int i = 0;i < MAX_SIZE;i++) {
            if(heap[i] == '#')
                return new Object_v1(&heap[i]);
        }
        return nullptr;
    }
};