/* operator>>(EStream &, ERLevel *&) - 0x802312C8 (64 bytes) */

struct EStorable;

struct EStream {
    char pad[4];
};

EStream &operator_shr_EStream_EStorable(EStream &, EStorable *&);

struct ERLevel;

EStream &operator_shr_EStream_ERLevel(EStream &s, ERLevel *&p)
{
    EStorable *tmp;
    operator_shr_EStream_EStorable(s, tmp);
    p = (ERLevel *)tmp;
    return s;
}
