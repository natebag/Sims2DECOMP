/* operator>>(EStream &, EIPointAmbLight *&) - 0x80229790 (64 bytes) */

struct EStorable;

struct EStream {
    char pad[4];
};

EStream &operator_shr_EStream_EStorable(EStream &, EStorable *&);

struct EIPointAmbLight;

EStream &operator_shr_EStream_EIPointAmbLight(EStream &s, EIPointAmbLight *&p)
{
    EStorable *tmp;
    operator_shr_EStream_EStorable(s, tmp);
    p = (EIPointAmbLight *)tmp;
    return s;
}
