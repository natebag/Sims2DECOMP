/* operator>>(EStream &, ESim *&) - 0x80030A44 (64 bytes) */

struct EStorable;

struct EStream {
    char pad[4];
};

EStream &operator_shr_EStream_EStorable(EStream &, EStorable *&);

struct ESim;

EStream &operator_shr_EStream_ESim(EStream &s, ESim *&p)
{
    EStorable *tmp;
    operator_shr_EStream_EStorable(s, tmp);
    p = (ESim *)tmp;
    return s;
}
