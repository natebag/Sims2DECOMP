// FLAGS: -fno-schedule-insns
// 0x80369F48 ERSoundEvent::GetTypeKey (12b)
// TU: e_rsoundevent

struct TypeInfo {
    char pad[0x10];
    unsigned int m_key;
};

extern TypeInfo ERSoundEvent_typeInfo;

struct ERSoundEvent {
    unsigned int GetTypeKey() const;
};

unsigned int ERSoundEvent::GetTypeKey() const {
    return ERSoundEvent_typeInfo.m_key;
}
