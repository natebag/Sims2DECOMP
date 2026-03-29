// 0x803382F4 (8 bytes)
class ERSampledata {
public:
    void* operator new(unsigned int size, void* ptr);
};

void* ERSampledata::operator new(unsigned int size, void* ptr) {
    return ptr;
}
