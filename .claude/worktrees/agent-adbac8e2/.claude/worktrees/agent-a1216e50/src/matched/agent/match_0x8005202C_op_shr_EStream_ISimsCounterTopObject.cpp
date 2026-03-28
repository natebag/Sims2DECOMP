/* operator>>(EStream &, ISimsCounterTopObject *&) - 0x8005202C (64 bytes) */

struct EStorable;

struct EStream {
    char pad[4];
};

EStream &operator_shr_EStream_EStorable(EStream &, EStorable *&);

struct ISimsCounterTopObject;

EStream &operator_shr_EStream_ISimsCounterTopObject(EStream &s, ISimsCounterTopObject *&p)
{
    EStorable *tmp;
    operator_shr_EStream_EStorable(s, tmp);
    p = (ISimsCounterTopObject *)tmp;
    return s;
}
