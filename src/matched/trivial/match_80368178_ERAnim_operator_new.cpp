// 0x80368178 (8 bytes)
class ERAnim {
public:
    void* operator new(unsigned int size, void* ptr);
};

void* ERAnim::operator new(unsigned int size, void* ptr) {
    return ptr;
}
