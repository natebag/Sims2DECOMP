void AptDeallocate(void* ptr);

struct AptCharacterTextInst {
    void operator delete[](void* ptr);
};

void AptCharacterTextInst::operator delete[](void* ptr) {
    AptDeallocate(ptr);
}
