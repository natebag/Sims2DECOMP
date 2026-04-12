// 0x8036A62C (12 bytes)
class ERSoundTrackData {
public:
    unsigned short GetTypeVersion() const;
};

extern unsigned short ERSoundTrackData_typeInfo_version[];

unsigned short ERSoundTrackData::GetTypeVersion() const {
    return ERSoundTrackData_typeInfo_version[0];
}
