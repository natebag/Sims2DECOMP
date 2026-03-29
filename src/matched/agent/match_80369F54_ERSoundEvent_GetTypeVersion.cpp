/* ERSoundEvent::GetTypeVersion(void) const - 0x80369F54 (12 bytes) */
// TU: e_rsoundevent

extern unsigned int ERSoundEvent_typeInfo_version;

struct ERSoundEvent {
    unsigned int GetTypeVersion() const;
};

unsigned int ERSoundEvent::GetTypeVersion() const {
    return ERSoundEvent_typeInfo_version;
}
