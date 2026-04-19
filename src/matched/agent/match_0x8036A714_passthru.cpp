/* operator<<(EStream&, REffectsEmitter*) at 0x8036A714 (32B) */
// 0x8036A714 (32 bytes)
class EStream;
class EStorable {};
class REffectsEmitter : public EStorable {};
extern EStream& operator<<(EStream& s, EStorable* obj);
EStream& operator<<(EStream& s, REffectsEmitter* obj) {
    return operator<<(s, (EStorable*)obj);
}
