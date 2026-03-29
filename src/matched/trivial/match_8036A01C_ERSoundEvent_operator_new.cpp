// 0x8036A01C (8 bytes)
class ERSoundEvent {
public:
    void* operator new(unsigned int size, void* ptr);
};

void* ERSoundEvent::operator new(unsigned int size, void* ptr) {
    return ptr;
}
