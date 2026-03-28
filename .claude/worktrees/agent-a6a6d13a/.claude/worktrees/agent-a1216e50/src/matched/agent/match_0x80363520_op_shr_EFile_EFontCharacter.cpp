/* operator>>(EFile &, EFontCharacter *&) - 0x80363520 (64 bytes) */

struct EStorable;

struct EFile {
    char pad[4];
};

EFile &operator_shr_EFile_EStorable(EFile &, EStorable *&);

struct EFontCharacter;

EFile &operator_shr_EFile_EFontCharacter(EFile &s, EFontCharacter *&p)
{
    EStorable *tmp;
    operator_shr_EFile_EStorable(s, tmp);
    p = (EFontCharacter *)tmp;
    return s;
}
