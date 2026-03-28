typedef unsigned int uint;

struct EIFloor {
    void* operator new(uint size, void* ptr);
};

void* EIFloor::operator new(uint size, void* ptr) {
    return ptr;
}
