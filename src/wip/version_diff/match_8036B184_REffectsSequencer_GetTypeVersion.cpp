/* REffectsSequencer::GetTypeVersion(void) const - 0x8036B184 (12 bytes) */
// TU: reffects_sequencer

extern unsigned int REffectsSequencer_typeInfo_version;

struct REffectsSequencer {
    unsigned int GetTypeVersion() const;
};

unsigned int REffectsSequencer::GetTypeVersion() const {
    return REffectsSequencer_typeInfo_version;
}
