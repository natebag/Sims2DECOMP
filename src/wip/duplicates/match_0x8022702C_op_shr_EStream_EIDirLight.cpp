/* operator>>(EStream &, EIDirLight *&) - 0x8022702C (64 bytes) */

struct EStorable;

struct EStream {
    char pad[4];
};

EStream &operator_shr_EStream_EStorable(EStream &, EStorable *&);

struct EIDirLight;

EStream &operator_shr_EStream_EIDirLight(EStream &s, EIDirLight *&p)
{
    EStorable *tmp;
    operator_shr_EStream_EStorable(s, tmp);
    p = (EIDirLight *)tmp;
    return s;
}
