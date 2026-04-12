// 0x8036A614 ERSoundTrackData::GetTypeName (12b)
// TU: e_rsoundtrackdata

struct TypeInfo {
    char pad[0x0C];
    const char* m_name;
};

extern TypeInfo ERSoundTrackData_typeInfo;

struct ERSoundTrackData {
    const char* GetTypeName() const;
};

const char* ERSoundTrackData::GetTypeName() const {
    return ERSoundTrackData_typeInfo.m_name;
}
