/* operator>>(EStream &, EIPointLight *&) - 0x80229D4C (64 bytes) */

struct EStorable;

struct EStream {
    char pad[4];
};

EStream &operator_shr_EStream_EStorable(EStream &, EStorable *&);

struct EIPointLight;

EStream &operator_shr_EStream_EIPointLight(EStream &s, EIPointLight *&p)
{
    EStorable *tmp;
    operator_shr_EStream_EStorable(s, tmp);
    p = (EIPointLight *)tmp;
    return s;
}
