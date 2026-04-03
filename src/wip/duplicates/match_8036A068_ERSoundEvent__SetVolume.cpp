// 0x8036A068 (8 bytes)
class ERSoundEvent {
public:
    void SetVolume(int p);
};

void ERSoundEvent::SetVolume(int p) {
    *(short*)((char*)this + 0x18) = (short)p;
}
