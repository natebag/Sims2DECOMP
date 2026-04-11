/* ERSoundEvent::GetTypeName(void) const - 0x80369F3C (12 bytes) */
// TU: e_rsoundevent

extern char ERSoundEvent_typeInfo_name;

struct ERSoundEvent {
    const char* GetTypeName() const;
};

const char* ERSoundEvent::GetTypeName() const {
    return &ERSoundEvent_typeInfo_name;
}
