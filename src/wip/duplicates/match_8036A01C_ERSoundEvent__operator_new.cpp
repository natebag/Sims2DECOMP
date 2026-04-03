// 0x8036A01C (8 bytes) - ERSoundEvent::operator new(unsigned int, void *)
typedef unsigned int size_t;

void* operator_new_ERSoundEvent(size_t size, void* ptr) {
    return ptr;
}
