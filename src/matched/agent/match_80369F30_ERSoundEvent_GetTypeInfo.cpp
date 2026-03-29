/* ERSoundEvent::GetTypeInfo(void) const - 0x80369F30 (12 bytes) */
// TU: e_rsoundevent

struct TypeInfo;

extern TypeInfo ERSoundEvent_typeInfo;

struct ERSoundEvent {
    const TypeInfo* GetTypeInfo() const;
};

const TypeInfo* ERSoundEvent::GetTypeInfo() const {
    return &ERSoundEvent_typeInfo;
}
