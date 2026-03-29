/* ERSoundTrackData::GetTypeInfoStatic(void) - 0x8036A638 (12 bytes) */
// TU: e_rsoundtrackdata

struct TypeInfo;

extern TypeInfo ERSoundTrackData_typeInfo;

struct ERSoundTrackData {
    static const TypeInfo* GetTypeInfoStatic();
};

const TypeInfo* ERSoundTrackData::GetTypeInfoStatic() {
    return &ERSoundTrackData_typeInfo;
}
