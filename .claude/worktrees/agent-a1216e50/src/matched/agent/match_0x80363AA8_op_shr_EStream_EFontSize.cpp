/* operator>>(EStream &, EFontSize *&) - 0x80363AA8 (64 bytes) */

struct EStorable;

struct EStream {
    char pad[4];
};

EStream &operator_shr_EStream_EStorable(EStream &, EStorable *&);

struct EFontSize;

EStream &operator_shr_EStream_EFontSize(EStream &s, EFontSize *&p)
{
    EStorable *tmp;
    operator_shr_EStream_EStorable(s, tmp);
    p = (EFontSize *)tmp;
    return s;
}
