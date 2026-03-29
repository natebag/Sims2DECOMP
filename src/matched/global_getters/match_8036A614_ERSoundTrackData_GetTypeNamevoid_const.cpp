// 0x8036A614 (12 bytes)
class ERSoundTrackData {
public:
    const char* GetTypeName() const;
};

extern char gERSoundTrackDataData[];

const char* ERSoundTrackData::GetTypeName() const {
    return *(const char**)(gERSoundTrackDataData + 0);
}
