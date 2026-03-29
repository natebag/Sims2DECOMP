/* ERSoundTrackData::GetTypeInfo(void) const - 0x8036A608 (12 bytes) */
// TU: e_rsoundtrackdata

struct TypeInfo;

extern TypeInfo ERSoundTrackData_typeInfo;

struct ERSoundTrackData {
    const TypeInfo* GetTypeInfo() const;
};

const TypeInfo* ERSoundTrackData::GetTypeInfo() const {
    return &ERSoundTrackData_typeInfo;
}
