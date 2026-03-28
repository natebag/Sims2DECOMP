/* operator>>(EStream &, EIFenceWall *&) - 0x80029810 (64 bytes) */

struct EStorable;

struct EStream {
    char pad[4];
};

EStream &operator_shr_EStream_EStorable(EStream &, EStorable *&);

struct EIFenceWall;

EStream &operator_shr_EStream_EIFenceWall(EStream &s, EIFenceWall *&p)
{
    EStorable *tmp;
    operator_shr_EStream_EStorable(s, tmp);
    p = (EIFenceWall *)tmp;
    return s;
}
