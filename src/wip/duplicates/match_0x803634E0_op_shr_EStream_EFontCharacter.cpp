/* operator>>(EStream &, EFontCharacter *&) - 0x803634E0 (64 bytes) */

struct EStorable;

struct EStream {
    char pad[4];
};

EStream &operator_shr_EStream_EStorable(EStream &, EStorable *&);

struct EFontCharacter;

EStream &operator_shr_EStream_EFontCharacter(EStream &s, EFontCharacter *&p)
{
    EStorable *tmp;
    operator_shr_EStream_EStorable(s, tmp);
    p = (EFontCharacter *)tmp;
    return s;
}
