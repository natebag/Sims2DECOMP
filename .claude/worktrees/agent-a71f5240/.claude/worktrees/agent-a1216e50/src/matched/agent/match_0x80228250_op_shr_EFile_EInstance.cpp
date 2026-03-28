/* operator>>(EFile &, EInstance *&) - 0x80228250 (64 bytes) */

struct EStorable;

struct EFile {
    char pad[4];
};

EFile &operator_shr_EFile_EStorable(EFile &, EStorable *&);

struct EInstance;

EFile &operator_shr_EFile_EInstance(EFile &s, EInstance *&p)
{
    EStorable *tmp;
    operator_shr_EFile_EStorable(s, tmp);
    p = (EInstance *)tmp;
    return s;
}
