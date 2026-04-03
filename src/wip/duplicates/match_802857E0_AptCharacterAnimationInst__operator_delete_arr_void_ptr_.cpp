void AptDeallocate(void* ptr);

struct AptCharacterAnimationInst {
    void operator delete[](void* ptr);
};

void AptCharacterAnimationInst::operator delete[](void* ptr) {
    AptDeallocate(ptr);
}
