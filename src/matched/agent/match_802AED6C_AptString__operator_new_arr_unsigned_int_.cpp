void* AptAllocate(unsigned int size);

struct AptString {
    void* operator new[](unsigned int size);
};

void* AptString::operator new[](unsigned int size) {
    return AptAllocate(size);
}
