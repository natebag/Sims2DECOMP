typedef unsigned int uint;

struct ISimInstance {
    void* operator new(uint size, void* ptr);
};

void* ISimInstance::operator new(uint size, void* ptr) {
    return ptr;
}
