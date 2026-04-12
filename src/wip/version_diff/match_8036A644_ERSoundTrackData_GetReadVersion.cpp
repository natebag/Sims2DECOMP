// 0x8036A644 (12 bytes)
class ERSoundTrackData {
public:
    unsigned short GetReadVersion() const;
};

extern unsigned short ERSoundTrackData_readVersion[];

unsigned short ERSoundTrackData::GetReadVersion() const {
    return ERSoundTrackData_readVersion[1];
}
