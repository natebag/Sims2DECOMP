/* operator>>(EStream &, EIFloor *&) - 0x800471B4 (64 bytes) */

struct EStorable;

struct EStream {
    char pad[4];
};

EStream &operator_shr_EStream_EStorable(EStream &, EStorable *&);

struct EIFloor;

EStream &operator_shr_EStream_EIFloor(EStream &s, EIFloor *&p)
{
    EStorable *tmp;
    operator_shr_EStream_EStorable(s, tmp);
    p = (EIFloor *)tmp;
    return s;
}
