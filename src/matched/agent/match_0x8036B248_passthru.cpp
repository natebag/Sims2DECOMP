/* operator<<(EStream&, RParticle*) at 0x8036B248 (32B) */
// 0x8036B248 (32 bytes)
class EStream;
class EStorable {};
class RParticle : public EStorable {};
extern EStream& operator<<(EStream& s, EStorable* obj);
EStream& operator<<(EStream& s, RParticle* obj) {
    return operator<<(s, (EStorable*)obj);
}
