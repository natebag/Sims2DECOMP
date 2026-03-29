/* ERSoundTrackData::GetReadVersion(void) - 0x8036A644 (12 bytes) */
// TU: e_rsoundtrackdata

extern unsigned int ERSoundTrackData_readVersion;

struct ERSoundTrackData {
    static unsigned int GetReadVersion();
};

unsigned int ERSoundTrackData::GetReadVersion() {
    return ERSoundTrackData_readVersion;
}
