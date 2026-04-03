// 0x80369F6C (12 bytes)
class ERSoundEvent {
public:
    short GetReadVersion() const;
};

extern char gERSoundEventData[];

short ERSoundEvent::GetReadVersion() const {
    return *(short*)(gERSoundEventData + 0);
}
