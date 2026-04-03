// 0x80369F48 (12 bytes)
class ERSoundEvent {
public:
    const char* GetTypeKey() const;
};

extern char gERSoundEventData[];

const char* ERSoundEvent::GetTypeKey() const {
    return *(const char**)(gERSoundEventData + 0);
}
