/* operator>>(EFile &, ERAnim *&) - 0x8036736C (64 bytes) */

struct EStorable;

struct EFile {
    char pad[4];
};

EFile &operator_shr_EFile_EStorable(EFile &, EStorable *&);

struct ERAnim;

EFile &operator_shr_EFile_ERAnim(EFile &s, ERAnim *&p)
{
    EStorable *tmp;
    operator_shr_EFile_EStorable(s, tmp);
    p = (ERAnim *)tmp;
    return s;
}
