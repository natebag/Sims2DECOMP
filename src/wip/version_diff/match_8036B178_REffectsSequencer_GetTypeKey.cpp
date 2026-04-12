// 0x8036B178 REffectsSequencer::GetTypeKey (12b)
// TU: reffects_sequencer

struct TypeInfo {
    char pad[0x10];
    unsigned int m_key;
};

extern TypeInfo REffectsSequencer_typeInfo;

struct REffectsSequencer {
    unsigned int GetTypeKey() const;
};

unsigned int REffectsSequencer::GetTypeKey() const {
    return REffectsSequencer_typeInfo.m_key;
}
