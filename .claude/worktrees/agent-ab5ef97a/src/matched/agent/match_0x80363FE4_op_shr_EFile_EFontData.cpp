/* operator>>(EFile &, EFontData *&) - 0x80363FE4 (64 bytes) */

struct EStorable;

struct EFile {
    char pad[4];
};

EFile &operator_shr_EFile_EStorable(EFile &, EStorable *&);

struct EFontData;

EFile &operator_shr_EFile_EFontData(EFile &s, EFontData *&p)
{
    EStorable *tmp;
    operator_shr_EFile_EStorable(s, tmp);
    p = (EFontData *)tmp;
    return s;
}
