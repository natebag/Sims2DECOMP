/* operator>>(EStream &, EFontData *&) - 0x80363FA4 (64 bytes) */

struct EStorable;

struct EStream {
    char pad[4];
};

EStream &operator_shr_EStream_EStorable(EStream &, EStorable *&);

struct EFontData;

EStream &operator_shr_EStream_EFontData(EStream &s, EFontData *&p)
{
    EStorable *tmp;
    operator_shr_EStream_EStorable(s, tmp);
    p = (EFontData *)tmp;
    return s;
}
