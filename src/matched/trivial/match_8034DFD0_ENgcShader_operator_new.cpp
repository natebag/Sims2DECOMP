// 0x8034DFD0 (8 bytes)
class ENgcShader {
public:
    void* operator new(unsigned int size, void* ptr);
};

void* ENgcShader::operator new(unsigned int size, void* ptr) {
    return ptr;
}
