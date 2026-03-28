/* operator>>(EFile &, EFontSize *&) - 0x80363AE8 (64 bytes) */

struct EStorable;

struct EFile {
    char pad[4];
};

EFile &operator_shr_EFile_EStorable(EFile &, EStorable *&);

struct EFontSize;

EFile &operator_shr_EFile_EFontSize(EFile &s, EFontSize *&p)
{
    EStorable *tmp;
    operator_shr_EFile_EStorable(s, tmp);
    p = (EFontSize *)tmp;
    return s;
}
