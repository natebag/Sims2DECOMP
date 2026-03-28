/* operator>>(EStream &, EIPortalPointLight *&) - 0x8022A6A0 (64 bytes) */

struct EStorable;

struct EStream {
    char pad[4];
};

EStream &operator_shr_EStream_EStorable(EStream &, EStorable *&);

struct EIPortalPointLight;

EStream &operator_shr_EStream_EIPortalPointLight(EStream &s, EIPortalPointLight *&p)
{
    EStorable *tmp;
    operator_shr_EStream_EStorable(s, tmp);
    p = (EIPortalPointLight *)tmp;
    return s;
}
