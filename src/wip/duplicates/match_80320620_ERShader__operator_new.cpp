// 0x80320620 (8 bytes) - ERShader::operator new(unsigned int, void *)
typedef unsigned int size_t;

void* operator_new_ERShader(size_t size, void* ptr) {
    return ptr;
}
