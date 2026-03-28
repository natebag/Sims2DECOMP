void AptDeallocate(void* ptr);

struct AptString {
    void operator delete[](void* ptr);
};

void AptString::operator delete[](void* ptr) {
    AptDeallocate(ptr);
}
