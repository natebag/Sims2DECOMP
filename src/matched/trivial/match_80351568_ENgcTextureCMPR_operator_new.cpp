// 0x80351568 (8 bytes)
class ENgcTextureCMPR {
public:
    void* operator new(unsigned int size, void* ptr);
};

void* ENgcTextureCMPR::operator new(unsigned int size, void* ptr) {
    return ptr;
}
