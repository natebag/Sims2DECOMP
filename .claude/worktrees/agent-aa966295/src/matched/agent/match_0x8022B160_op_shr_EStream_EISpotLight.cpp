/* operator>>(EStream &, EISpotLight *&) - 0x8022B160 (64 bytes) */

struct EStorable;

struct EStream {
    char pad[4];
};

EStream &operator_shr_EStream_EStorable(EStream &, EStorable *&);

struct EISpotLight;

EStream &operator_shr_EStream_EISpotLight(EStream &s, EISpotLight *&p)
{
    EStorable *tmp;
    operator_shr_EStream_EStorable(s, tmp);
    p = (EISpotLight *)tmp;
    return s;
}
