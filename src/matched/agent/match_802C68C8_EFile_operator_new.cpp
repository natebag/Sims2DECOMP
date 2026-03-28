struct EFile_ON {
    static void* operator_new(unsigned int size, void* ptr);
};

void* EFile_ON::operator_new(unsigned int size, void* ptr) {
    return ptr;
}
