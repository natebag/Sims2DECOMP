/* operator<<(EStream&, REffectsSequencer*) at 0x8036ADD0 (32B) */
// 0x8036ADD0 (32 bytes)
class EStream;
class EStorable {};
class REffectsSequencer : public EStorable {};
extern EStream& operator<<(EStream& s, EStorable* obj);
EStream& operator<<(EStream& s, REffectsSequencer* obj) {
    return operator<<(s, (EStorable*)obj);
}
