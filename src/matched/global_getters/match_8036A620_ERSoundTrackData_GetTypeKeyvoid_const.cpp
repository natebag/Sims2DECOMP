// 0x8036A620 (12 bytes)
class ERSoundTrackData {
public:
    const char* GetTypeKey() const;
};

extern char gERSoundTrackDataData[];

const char* ERSoundTrackData::GetTypeKey() const {
    return *(const char**)(gERSoundTrackDataData + 0);
}
