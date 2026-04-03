// 0x8036B178 (12 bytes)
class REffectsSequencer {
public:
    const char* GetTypeKey() const;
};

extern char gREffectsSequencerData[];

const char* REffectsSequencer::GetTypeKey() const {
    return *(const char**)(gREffectsSequencerData + 0);
}
