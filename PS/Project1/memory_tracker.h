#pragma once
#include <iostream>

class MemoryTracker {
public:
    MemoryTracker();

    static MemoryTracker& get_instance();

    void* allocate(std::size_t size);

    void deallocate(void* ptr, std::size_t size);

    static void Report();

private:
    void report() const;
    std::size_t m_allocated;
    std::size_t m_freed;
};

void* operator new(std::size_t size);

void operator delete(void* ptr, std::size_t size);