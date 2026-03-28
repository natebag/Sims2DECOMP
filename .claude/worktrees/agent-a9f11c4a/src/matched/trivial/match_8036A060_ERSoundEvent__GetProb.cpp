// 0x8036A060 (8 bytes)
class ERSoundEvent {
public:
    int GetProb();
};

int ERSoundEvent::GetProb() {
    return *(unsigned char*)((char*)this + 0x1A);
}
