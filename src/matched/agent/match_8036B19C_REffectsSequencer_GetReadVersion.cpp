/* REffectsSequencer::GetReadVersion(void) - 0x8036B19C (12 bytes) */
// TU: reffects_sequencer

extern unsigned int REffectsSequencer_readVersion;

struct REffectsSequencer {
    static unsigned int GetReadVersion();
};

unsigned int REffectsSequencer::GetReadVersion() {
    return REffectsSequencer_readVersion;
}
