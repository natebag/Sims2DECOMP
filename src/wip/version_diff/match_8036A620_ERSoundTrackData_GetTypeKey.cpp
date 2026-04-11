/* ERSoundTrackData::GetTypeKey(void) const - 0x8036A620 (12 bytes) */
// TU: e_rsoundtrackdata

extern unsigned int ERSoundTrackData_typeInfo_key;

struct ERSoundTrackData {
    unsigned int GetTypeKey() const;
};

unsigned int ERSoundTrackData::GetTypeKey() const {
    return ERSoundTrackData_typeInfo_key;
}
