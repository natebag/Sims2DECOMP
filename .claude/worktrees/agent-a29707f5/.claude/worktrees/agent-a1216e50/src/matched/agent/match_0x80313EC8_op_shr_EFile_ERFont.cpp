/* operator>>(EFile &, ERFont *&) - 0x80313EC8 (64 bytes) */

struct EStorable;

struct EFile {
    char pad[4];
};

EFile &operator_shr_EFile_EStorable(EFile &, EStorable *&);

struct ERFont;

EFile &operator_shr_EFile_ERFont(EFile &s, ERFont *&p)
{
    EStorable *tmp;
    operator_shr_EFile_EStorable(s, tmp);
    p = (ERFont *)tmp;
    return s;
}
