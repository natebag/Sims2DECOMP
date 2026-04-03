// 0x8036A050 (8 bytes)
class ERSoundEvent {
public:
    int GetEventType();
};

int ERSoundEvent::GetEventType() {
    return *(unsigned char*)((char*)this + 0x14);
}
