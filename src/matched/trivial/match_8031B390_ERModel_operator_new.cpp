// 0x8031B390 (8 bytes)
class ERModel {
public:
    void* operator new(unsigned int size, void* ptr);
};

void* ERModel::operator new(unsigned int size, void* ptr) {
    return ptr;
}
