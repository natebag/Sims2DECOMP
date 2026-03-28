/* operator>>(EStream &, EInstance *&) - 0x80228210 (64 bytes) */

struct EStorable;

struct EStream {
    char pad[4];
};

EStream &operator_shr_EStream_EStorable(EStream &, EStorable *&);

struct EInstance;

EStream &operator_shr_EStream_EInstance(EStream &s, EInstance *&p)
{
    EStorable *tmp;
    operator_shr_EStream_EStorable(s, tmp);
    p = (EInstance *)tmp;
    return s;
}
