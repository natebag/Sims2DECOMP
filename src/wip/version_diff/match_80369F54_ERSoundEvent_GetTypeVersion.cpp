// 0x80369F54 (12 bytes)
class ERSoundEvent {
public:
    unsigned short GetTypeVersion() const;
};

extern unsigned short ERSoundEvent_typeInfo_version[];

unsigned short ERSoundEvent::GetTypeVersion() const {
    return ERSoundEvent_typeInfo_version[0];
}
