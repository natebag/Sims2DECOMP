/* operator>>(EFile &, EResource *&) - 0x80311D88 (64 bytes) */

struct EStorable;

struct EFile {
    char pad[4];
};

EFile &operator_shr_EFile_EStorable(EFile &, EStorable *&);

struct EResource;

EFile &operator_shr_EFile_EResource(EFile &s, EResource *&p)
{
    EStorable *tmp;
    operator_shr_EFile_EStorable(s, tmp);
    p = (EResource *)tmp;
    return s;
}
