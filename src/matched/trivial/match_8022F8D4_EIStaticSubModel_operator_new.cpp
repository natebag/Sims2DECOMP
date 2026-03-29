// 0x8022F8D4 (8 bytes)
class EIStaticSubModel {
public:
    void* operator new(unsigned int size, void* ptr);
};

void* EIStaticSubModel::operator new(unsigned int size, void* ptr) {
    return ptr;
}
