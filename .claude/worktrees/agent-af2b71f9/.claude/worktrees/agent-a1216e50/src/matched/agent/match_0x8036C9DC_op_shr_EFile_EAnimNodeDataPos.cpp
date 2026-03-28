/* operator>>(EFile &, EAnimNodeDataPos *&) - 0x8036C9DC (64 bytes) */

struct EStorable;

struct EFile {
    char pad[4];
};

EFile &operator_shr_EFile_EStorable(EFile &, EStorable *&);

struct EAnimNodeDataPos;

EFile &operator_shr_EFile_EAnimNodeDataPos(EFile &s, EAnimNodeDataPos *&p)
{
    EStorable *tmp;
    operator_shr_EFile_EStorable(s, tmp);
    p = (EAnimNodeDataPos *)tmp;
    return s;
}
