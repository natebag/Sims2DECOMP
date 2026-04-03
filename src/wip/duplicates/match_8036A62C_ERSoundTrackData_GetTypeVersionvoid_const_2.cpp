// 0x8036A62C (12 bytes)
class ERSoundTrackData {
public:
    short GetTypeVersion() const;
};

extern char gERSoundTrackDataData[];

short ERSoundTrackData::GetTypeVersion() const {
    return *(short*)(gERSoundTrackDataData + 0);
}
