// 0x800567F8 (8 bytes)
class ISimInstance {
public:
    void* operator new(unsigned int size, void* ptr);
};

void* ISimInstance::operator new(unsigned int size, void* ptr) {
    return ptr;
}
