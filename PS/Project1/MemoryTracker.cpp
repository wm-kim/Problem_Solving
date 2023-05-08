#include "memory_tracker.h"

MemoryTracker::MemoryTracker() : m_allocated(0), m_freed(0) {}

void MemoryTracker::report() const {
    std::cout << "Memory tracker: allocated " << m_allocated << " bytes, freed " << m_freed << " bytes, currently allocated " << m_allocated - m_freed << " bytes." << std::endl;
}

MemoryTracker& MemoryTracker::get_instance() {
    static MemoryTracker instance;
    return instance;
}

void* MemoryTracker::allocate(std::size_t size) {
    m_allocated += size;
    return std::malloc(size);
}

void MemoryTracker::deallocate(void* ptr, std::size_t size) {
    m_freed += size;
    std::free(ptr);
}

void MemoryTracker::Report() {
    get_instance().report();
}

void* operator new(std::size_t size) {
    void* ptr = MemoryTracker::get_instance().allocate(size);
    return ptr;
}

void operator delete(void* ptr, std::size_t size) {
    MemoryTracker::get_instance().deallocate(ptr, size);
}