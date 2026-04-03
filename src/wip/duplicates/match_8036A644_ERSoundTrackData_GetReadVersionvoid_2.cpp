// 0x8036A644 (12 bytes)
class ERSoundTrackData {
public:
    short GetReadVersion() const;
};

extern char gERSoundTrackDataData[];

short ERSoundTrackData::GetReadVersion() const {
    return *(short*)(gERSoundTrackDataData + 0);
}
