/* operator<<(EStream&, EFontSize*) at 0x80363A88 (32B) */
// 0x80363A88 (32 bytes)
class EStream;
class EStorable {};
class EFontSize : public EStorable {};
extern EStream& operator<<(EStream& s, EStorable* obj);
EStream& operator<<(EStream& s, EFontSize* obj) {
    return operator<<(s, (EStorable*)obj);
}
