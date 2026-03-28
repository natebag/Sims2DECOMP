/* operator>>(EFile &, EFontPage *&) - 0x80363804 (64 bytes) */

struct EStorable;

struct EFile {
    char pad[4];
};

EFile &operator_shr_EFile_EStorable(EFile &, EStorable *&);

struct EFontPage;

EFile &operator_shr_EFile_EFontPage(EFile &s, EFontPage *&p)
{
    EStorable *tmp;
    operator_shr_EFile_EStorable(s, tmp);
    p = (EFontPage *)tmp;
    return s;
}
