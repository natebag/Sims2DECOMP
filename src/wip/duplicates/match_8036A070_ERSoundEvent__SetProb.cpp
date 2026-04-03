// 0x8036A070 (8 bytes)
class ERSoundEvent {
public:
    void SetProb(int p);
};

void ERSoundEvent::SetProb(int p) {
    *(unsigned char*)((char*)this + 0x1A) = (unsigned char)p;
}
