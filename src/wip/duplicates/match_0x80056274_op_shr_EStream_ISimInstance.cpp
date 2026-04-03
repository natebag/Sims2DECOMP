/* operator>>(EStream &, ISimInstance *&) - 0x80056274 (64 bytes) */

struct EStorable;

struct EStream {
    char pad[4];
};

EStream &operator_shr_EStream_EStorable(EStream &, EStorable *&);

struct ISimInstance;

EStream &operator_shr_EStream_ISimInstance(EStream &s, ISimInstance *&p)
{
    EStorable *tmp;
    operator_shr_EStream_EStorable(s, tmp);
    p = (ISimInstance *)tmp;
    return s;
}
