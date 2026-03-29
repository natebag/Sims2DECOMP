// 0x80320620 (8 bytes)
class ERShader {
public:
    void* operator new(unsigned int size, void* ptr);
};

void* ERShader::operator new(unsigned int size, void* ptr) {
    return ptr;
}
