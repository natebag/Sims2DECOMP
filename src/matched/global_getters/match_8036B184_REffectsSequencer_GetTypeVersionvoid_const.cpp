// 0x8036B184 (12 bytes)
class REffectsSequencer {
public:
    short GetTypeVersion() const;
};

extern char gREffectsSequencerData[];

short REffectsSequencer::GetTypeVersion() const {
    return *(short*)(gREffectsSequencerData + 0);
}
