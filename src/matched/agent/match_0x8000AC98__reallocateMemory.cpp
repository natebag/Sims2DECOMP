void* ReallocImpl(void* ptr, int oldSize, int newSize);

void* _reallocateMemory(void* ptr, int oldSize, int newSize) {
    return ReallocImpl(ptr, oldSize, newSize);
}
