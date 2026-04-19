/* REffectsSequencer::Construct(REffectsSequencer*) at 0x8036B0DC (32B) */
// 0x8036B0DC (32 bytes)
class REffectsSequencer {
public:
    REffectsSequencer();
    void Construct(REffectsSequencer* other);
};
static inline void* operator new(unsigned sz, void* p) { return p; }
void REffectsSequencer::Construct(REffectsSequencer*) {
    new(this) REffectsSequencer;
}
