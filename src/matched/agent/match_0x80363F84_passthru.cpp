/* operator<<(EStream&, EFontData*) at 0x80363F84 (32B) */
// 0x80363F84 (32 bytes)
class EStream;
class EStorable {};
class EFontData : public EStorable {};
extern EStream& operator<<(EStream& s, EStorable* obj);
EStream& operator<<(EStream& s, EFontData* obj) {
    return operator<<(s, (EStorable*)obj);
}
