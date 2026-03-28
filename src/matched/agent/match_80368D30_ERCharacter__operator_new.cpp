// 0x80368D30 (8 bytes) - ERCharacter::operator new(unsigned int, void *)
typedef unsigned int size_t;

void* operator_new_ERCharacter(size_t size, void* ptr) {
    return ptr;
}
