// 0x80369F54 (12 bytes)
class ERSoundEvent {
public:
    short GetTypeVersion() const;
};

extern char gERSoundEventData[];

short ERSoundEvent::GetTypeVersion() const {
    return *(short*)(gERSoundEventData + 0);
}
