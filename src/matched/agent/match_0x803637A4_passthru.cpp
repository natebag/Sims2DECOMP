/* operator<<(EStream&, EFontPage*) at 0x803637A4 (32B) */
// 0x803637A4 (32 bytes)
class EStream;
class EStorable {};
class EFontPage : public EStorable {};
extern EStream& operator<<(EStream& s, EStorable* obj);
EStream& operator<<(EStream& s, EFontPage* obj) {
    return operator<<(s, (EStorable*)obj);
}
