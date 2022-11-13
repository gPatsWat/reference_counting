#include "include/ref.hh"

int Object::rc() {
    return this->r_count;
}

Object* mem_allocator::new_object() {
        Object* ref = allocate();
        if( ref == nullptr ) {
            throw std::runtime_error("Out of memory!");
        }
        return ref;
}

void mem_allocator::write(Object* src, int i, Object* ref) {

}

Object_v1* mem_allocator::allocate() {
        for(int i = 0;i < MAX_SIZE;i++) {
            if(heap[i] == '#')
                return new Object_v1(&(heap[i]));
        }
        return nullptr;
}