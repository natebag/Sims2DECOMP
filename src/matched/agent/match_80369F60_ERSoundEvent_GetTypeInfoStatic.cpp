/* ERSoundEvent::GetTypeInfoStatic(void) - 0x80369F60 (12 bytes) */
// TU: e_rsoundevent

struct TypeInfo;

extern TypeInfo ERSoundEvent_typeInfo;

struct ERSoundEvent {
    static const TypeInfo* GetTypeInfoStatic();
};

const TypeInfo* ERSoundEvent::GetTypeInfoStatic() {
    return &ERSoundEvent_typeInfo;
}
