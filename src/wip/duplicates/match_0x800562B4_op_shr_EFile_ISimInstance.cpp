/* operator>>(EFile &, ISimInstance *&) - 0x800562B4 (64 bytes) */

struct EStorable;

struct EFile {
    char pad[4];
};

EFile &operator_shr_EFile_EStorable(EFile &, EStorable *&);

struct ISimInstance;

EFile &operator_shr_EFile_ISimInstance(EFile &s, ISimInstance *&p)
{
    EStorable *tmp;
    operator_shr_EFile_EStorable(s, tmp);
    p = (ISimInstance *)tmp;
    return s;
}
