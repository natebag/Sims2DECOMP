// 0x802B0000 (4 bytes)
class AptTextFormat {
public:
    void operator delete[](void* ptr);
};

void AptTextFormat::operator delete[](void* ptr) {
}
