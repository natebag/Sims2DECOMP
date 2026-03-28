/* operator>>(EFile &, ERFlash *&) - 0x803133A0 (64 bytes) */

struct EStorable;

struct EFile {
    char pad[4];
};

EFile &operator_shr_EFile_EStorable(EFile &, EStorable *&);

struct ERFlash;

EFile &operator_shr_EFile_ERFlash(EFile &s, ERFlash *&p)
{
    EStorable *tmp;
    operator_shr_EFile_EStorable(s, tmp);
    p = (ERFlash *)tmp;
    return s;
}
