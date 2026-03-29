// 0x8022E16C (8 bytes)
class EIStaticModel {
public:
    void* operator new(unsigned int size, void* ptr);
};

void* EIStaticModel::operator new(unsigned int size, void* ptr) {
    return ptr;
}
