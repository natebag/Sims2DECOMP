/* operator<<(EStream&, ERAnim*) at 0x8036730C (32B) */
// 0x8036730C (32 bytes)
class EStream;
class EStorable {};
class ERAnim : public EStorable {};
extern EStream& operator<<(EStream& s, EStorable* obj);
EStream& operator<<(EStream& s, ERAnim* obj) {
    return operator<<(s, (EStorable*)obj);
}
