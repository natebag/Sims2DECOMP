/* operator>>(EFile &, ISimsCounterTopObject *&) - 0x8005206C (64 bytes) */

struct EStorable;

struct EFile {
    char pad[4];
};

EFile &operator_shr_EFile_EStorable(EFile &, EStorable *&);

struct ISimsCounterTopObject;

EFile &operator_shr_EFile_ISimsCounterTopObject(EFile &s, ISimsCounterTopObject *&p)
{
    EStorable *tmp;
    operator_shr_EFile_EStorable(s, tmp);
    p = (ISimsCounterTopObject *)tmp;
    return s;
}
