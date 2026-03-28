/* operator>>(EStream &, EFontPage *&) - 0x803637C4 (64 bytes) */

struct EStorable;

struct EStream {
    char pad[4];
};

EStream &operator_shr_EStream_EStorable(EStream &, EStorable *&);

struct EFontPage;

EStream &operator_shr_EStream_EFontPage(EStream &s, EFontPage *&p)
{
    EStorable *tmp;
    operator_shr_EStream_EStorable(s, tmp);
    p = (EFontPage *)tmp;
    return s;
}
