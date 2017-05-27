#ifndef ALLOCATOR_H
#define ALLOCATOR_H
#include <iostream>

template <class T>
class FurnitureAllocator
{
public:
    typedef T value_type;
    typedef T* pointer;
    typedef const T* const_pointer;
    typedef T& reference;
    typedef const T& const_reference;
    typedef std::size_t size_type;
    typedef std::ptrdiff_t difference_type;

    template <class U>
    struct rebind{
        typedef FurnitureAllocator<U> other;
    };

    pointer address (reference value) const {
        return &value;
    }

    const_pointer address(const_reference value) const {
        return &value;
    }

    FurnitureAllocator() throw() {
    }
    FurnitureAllocator(const FurnitureAllocator&) throw() {
    }
    ~FurnitureAllocator() throw() {
    }

    template <class U>
    FurnitureAllocator (const FurnitureAllocator<U>&) throw() {
    }

    size_type max_size () const throw() {
        return std::numeric_limits<std::size_t>::max() / sizeof(T);
    }

    pointer allocate (size_type num, const void* = 0) {
        pointer ret = (pointer)(::operator new(num*sizeof(T)));
        return ret;
    }

    void construct (pointer p, const T& value) {
        new((void*)p)T(value);
    }

    void destroy (pointer p) {
        p->~T();
    }

    void deallocate (pointer p) {
        ::operator delete((void*)p);
    }

    template <class T1, class T2>
    bool operator== (const FurnitureAllocator<T1>&) noexcept {
        return true;
    }
    template <class T1, class T2>
    bool operator!= (const FurnitureAllocator<T1>&) noexcept {
        return false;
    }
};

#endif // ALLOCATOR_H
