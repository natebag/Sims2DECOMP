/* operator>>(EStream &, EREdithTreeSet *&) - 0x8030F404 (64 bytes) */

struct EStorable;

struct EStream {
    char pad[4];
};

EStream &operator_shr_EStream_EStorable(EStream &, EStorable *&);

struct EREdithTreeSet;

EStream &operator_shr_EStream_EREdithTreeSet(EStream &s, EREdithTreeSet *&p)
{
    EStorable *tmp;
    operator_shr_EStream_EStorable(s, tmp);
    p = (EREdithTreeSet *)tmp;
    return s;
}
