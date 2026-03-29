// 0x803122FC (8 bytes)
class EResource {
public:
    void* operator new(unsigned int size, void* ptr);
};

void* EResource::operator new(unsigned int size, void* ptr) {
    return ptr;
}
