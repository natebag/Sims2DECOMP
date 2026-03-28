// clib_wrappers.cpp — C++ linkage wrappers for memcpy/memset with unsigned int size
// The decomp code declares these without extern "C", so the linker looks for
// C++ mangled versions with unsigned int (32-bit) size parameters.
// This file must be compiled with -fpermissive.

#include <cstring>

void* memcpy(void* d, const void* s, unsigned int n) {
    return std::memcpy(d, s, static_cast<std::size_t>(n));
}

void* memset(void* d, int c, unsigned int n) {
    return std::memset(d, c, static_cast<std::size_t>(n));
}

int memcmp(const void* a, const void* b, unsigned int n) {
    return std::memcmp(a, b, static_cast<std::size_t>(n));
}

// strlen return type can't differ from stdlib — skip wrapper

int strncmp(const char* a, const char* b, unsigned int n) {
    return std::strncmp(a, b, static_cast<std::size_t>(n));
}

char* strncpy(char* d, const char* s, unsigned int n) {
    return std::strncpy(d, s, static_cast<std::size_t>(n));
}
