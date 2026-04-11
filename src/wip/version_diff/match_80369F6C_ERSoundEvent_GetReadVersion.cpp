/* ERSoundEvent::GetReadVersion(void) - 0x80369F6C (12 bytes) */
// TU: e_rsoundevent

extern unsigned int ERSoundEvent_readVersion;

struct ERSoundEvent {
    static unsigned int GetReadVersion();
};

unsigned int ERSoundEvent::GetReadVersion() {
    return ERSoundEvent_readVersion;
}
