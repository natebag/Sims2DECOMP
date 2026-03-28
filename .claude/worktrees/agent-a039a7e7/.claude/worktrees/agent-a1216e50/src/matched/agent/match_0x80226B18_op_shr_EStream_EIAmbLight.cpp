/* operator>>(EStream &, EIAmbLight *&) - 0x80226B18 (64 bytes) */

struct EStorable;

struct EStream {
    char pad[4];
};

EStream &operator_shr_EStream_EStorable(EStream &, EStorable *&);

struct EIAmbLight;

EStream &operator_shr_EStream_EIAmbLight(EStream &s, EIAmbLight *&p)
{
    EStorable *tmp;
    operator_shr_EStream_EStorable(s, tmp);
    p = (EIAmbLight *)tmp;
    return s;
}
