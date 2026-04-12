// 0x8036B16C REffectsSequencer::GetTypeName (12b)
// TU: reffects_sequencer

struct TypeInfo {
    char pad[0x0C];
    const char* m_name;
};

extern TypeInfo REffectsSequencer_typeInfo;

struct REffectsSequencer {
    const char* GetTypeName() const;
};

const char* REffectsSequencer::GetTypeName() const {
    return REffectsSequencer_typeInfo.m_name;
}
