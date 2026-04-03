// 0x8036B19C (12 bytes)
class REffectsSequencer {
public:
    short GetReadVersion() const;
};

extern char gREffectsSequencerData[];

short REffectsSequencer::GetReadVersion() const {
    return *(short*)(gREffectsSequencerData + 0);
}
