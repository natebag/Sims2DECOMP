void* AptAllocate(unsigned int size);

struct AptCharacterAnimationInst {
    void* operator new[](unsigned int size);
};

void* AptCharacterAnimationInst::operator new[](unsigned int size) {
    return AptAllocate(size);
}
