// 0x8036B16C (12 bytes)
class REffectsSequencer {
public:
    const char* GetTypeName() const;
};

extern char gREffectsSequencerData[];

const char* REffectsSequencer::GetTypeName() const {
    return *(const char**)(gREffectsSequencerData + 0);
}
