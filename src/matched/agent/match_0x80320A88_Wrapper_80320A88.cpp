/* operator<<(EStream&, ERTexture*) at 0x80320A88 (32B) */
// 0x80320A88 (32 bytes)
class EStream;
class EStorable {};
class ERTexture : public EStorable {};
extern EStream& operator<<(EStream& s, EStorable* obj);
EStream& operator<<(EStream& s, ERTexture* obj) {
    return operator<<(s, (EStorable*)obj);
}
