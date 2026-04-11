/* ERSoundTrackData::GetTypeName(void) const - 0x8036A614 (12 bytes) */
// TU: e_rsoundtrackdata

extern char ERSoundTrackData_typeInfo_name;

struct ERSoundTrackData {
    const char* GetTypeName() const;
};

const char* ERSoundTrackData::GetTypeName() const {
    return &ERSoundTrackData_typeInfo_name;
}
