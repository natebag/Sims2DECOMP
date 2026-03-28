void* AptAllocate(unsigned int size);

struct AptCharacterTextInst {
    void* operator new[](unsigned int size);
};

void* AptCharacterTextInst::operator new[](unsigned int size) {
    return AptAllocate(size);
}
