#include "include/ref.hh"

mem_allocator mallocator;

int main(int argc) {

    Object* a = mallocator.new_object();
    return 0;
}