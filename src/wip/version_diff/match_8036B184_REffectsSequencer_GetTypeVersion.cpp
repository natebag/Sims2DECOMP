// 0x8036B184 (12 bytes)
class REffectsSequencer {
public:
    unsigned short GetTypeVersion() const;
};

extern unsigned short REffectsSequencer_typeInfo_version[];

unsigned short REffectsSequencer::GetTypeVersion() const {
    return REffectsSequencer_typeInfo_version[0];
}
