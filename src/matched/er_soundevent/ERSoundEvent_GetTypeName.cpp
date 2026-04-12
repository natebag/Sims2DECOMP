// 0x80369F3C ERSoundEvent::GetTypeName (12b)
// TU: e_rsoundevent

struct TypeInfo {
    char pad[0x0C];
    const char* m_name;
};

extern TypeInfo ERSoundEvent_typeInfo;

struct ERSoundEvent {
    const char* GetTypeName() const;
};

const char* ERSoundEvent::GetTypeName() const {
    return ERSoundEvent_typeInfo.m_name;
}
