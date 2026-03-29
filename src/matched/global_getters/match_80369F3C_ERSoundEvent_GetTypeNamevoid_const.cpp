// 0x80369F3C (12 bytes)
class ERSoundEvent {
public:
    const char* GetTypeName() const;
};

extern char gERSoundEventData[];

const char* ERSoundEvent::GetTypeName() const {
    return *(const char**)(gERSoundEventData + 0);
}
