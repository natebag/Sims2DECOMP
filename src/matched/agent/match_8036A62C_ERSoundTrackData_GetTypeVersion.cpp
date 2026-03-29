/* ERSoundTrackData::GetTypeVersion(void) const - 0x8036A62C (12 bytes) */
// TU: e_rsoundtrackdata

extern unsigned int ERSoundTrackData_typeInfo_version;

struct ERSoundTrackData {
    unsigned int GetTypeVersion() const;
};

unsigned int ERSoundTrackData::GetTypeVersion() const {
    return ERSoundTrackData_typeInfo_version;
}
