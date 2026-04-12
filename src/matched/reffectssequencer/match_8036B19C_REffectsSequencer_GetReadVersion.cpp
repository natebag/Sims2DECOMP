// 0x8036B19C (12 bytes)
class REffectsSequencer {
public:
    unsigned short GetReadVersion() const;
};

extern unsigned short REffectsSequencer_readVersion[];

unsigned short REffectsSequencer::GetReadVersion() const {
    return REffectsSequencer_readVersion[0];
}
