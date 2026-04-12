// 0x80369F6C (12 bytes)
class ERSoundEvent {
public:
    unsigned short GetReadVersion() const;
};

extern unsigned short ERSoundEvent_readVersion[];

unsigned short ERSoundEvent::GetReadVersion() const {
    return ERSoundEvent_readVersion[0];
}
