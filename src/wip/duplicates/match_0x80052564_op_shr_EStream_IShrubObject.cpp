/* operator>>(EStream &, IShrubObject *&) - 0x80052564 (64 bytes) */

struct EStorable;

struct EStream {
    char pad[4];
};

EStream &operator_shr_EStream_EStorable(EStream &, EStorable *&);

struct IShrubObject;

EStream &operator_shr_EStream_IShrubObject(EStream &s, IShrubObject *&p)
{
    EStorable *tmp;
    operator_shr_EStream_EStorable(s, tmp);
    p = (IShrubObject *)tmp;
    return s;
}
