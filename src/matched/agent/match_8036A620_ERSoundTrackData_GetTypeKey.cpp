// 0x8036A620 match_8036A620_ERSoundTrackData_GetTypeKey (12b)
// 0x8036A620 ERSoundTrackData::GetTypeKey (12b)
// TU: e_rsoundtrackdata

struct TypeInfo {
    char pad[0x10];
    unsigned int m_key;
};

extern TypeInfo ERSoundTrackData_typeInfo;

struct ERSoundTrackData {
    unsigned int GetTypeKey() const;
};

unsigned int ERSoundTrackData::GetTypeKey() const {
    return ERSoundTrackData_typeInfo.m_key;
}
