/* operator>>(EStream &, ERAmbientScore *&) - 0x80366918 (64 bytes) */

struct EStorable;

struct EStream {
    char pad[4];
};

EStream &operator_shr_EStream_EStorable(EStream &, EStorable *&);

struct ERAmbientScore;

EStream &operator_shr_EStream_ERAmbientScore(EStream &s, ERAmbientScore *&p)
{
    EStorable *tmp;
    operator_shr_EStream_EStorable(s, tmp);
    p = (ERAmbientScore *)tmp;
    return s;
}
