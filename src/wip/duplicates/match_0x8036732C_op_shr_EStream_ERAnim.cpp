/* operator>>(EStream &, ERAnim *&) - 0x8036732C (64 bytes) */

struct EStorable;

struct EStream {
    char pad[4];
};

EStream &operator_shr_EStream_EStorable(EStream &, EStorable *&);

struct ERAnim;

EStream &operator_shr_EStream_ERAnim(EStream &s, ERAnim *&p)
{
    EStorable *tmp;
    operator_shr_EStream_EStorable(s, tmp);
    p = (ERAnim *)tmp;
    return s;
}
