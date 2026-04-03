/* operator>>(EStream &, EIWallPart *&) - 0x80029CAC (64 bytes) */

struct EStorable;

struct EStream {
    char pad[4];
};

EStream &operator_shr_EStream_EStorable(EStream &, EStorable *&);

struct EIWallPart;

EStream &operator_shr_EStream_EIWallPart(EStream &s, EIWallPart *&p)
{
    EStorable *tmp;
    operator_shr_EStream_EStorable(s, tmp);
    p = (EIWallPart *)tmp;
    return s;
}
