/* ERSoundEvent::GetTypeKey(void) const - 0x80369F48 (12 bytes) */
// TU: e_rsoundevent

extern unsigned int ERSoundEvent_typeInfo_key;

struct ERSoundEvent {
    unsigned int GetTypeKey() const;
};

unsigned int ERSoundEvent::GetTypeKey() const {
    return ERSoundEvent_typeInfo_key;
}
