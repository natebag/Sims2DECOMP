/* operator<<(EStream&, ERBinary*) at 0x803681D8 (32B) */
// 0x803681D8 (32 bytes)
class EStream;
class EStorable {};
class ERBinary : public EStorable {};
extern EStream& operator<<(EStream& s, EStorable* obj);
EStream& operator<<(EStream& s, ERBinary* obj) {
    return operator<<(s, (EStorable*)obj);
}
