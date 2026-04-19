/* operator<<(EStream&, EFontCharacter*) at 0x803634C0 (32B) */
// 0x803634C0 (32 bytes)
class EStream;
class EStorable {};
class EFontCharacter : public EStorable {};
extern EStream& operator<<(EStream& s, EStorable* obj);
EStream& operator<<(EStream& s, EFontCharacter* obj) {
    return operator<<(s, (EStorable*)obj);
}
