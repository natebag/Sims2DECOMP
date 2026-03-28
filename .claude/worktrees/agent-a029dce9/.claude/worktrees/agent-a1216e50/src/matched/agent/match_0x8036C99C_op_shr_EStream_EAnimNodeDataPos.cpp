/* operator>>(EStream &, EAnimNodeDataPos *&) - 0x8036C99C (64 bytes) */

struct EStorable;

struct EStream {
    char pad[4];
};

EStream &operator_shr_EStream_EStorable(EStream &, EStorable *&);

struct EAnimNodeDataPos;

EStream &operator_shr_EStream_EAnimNodeDataPos(EStream &s, EAnimNodeDataPos *&p)
{
    EStorable *tmp;
    operator_shr_EStream_EStorable(s, tmp);
    p = (EAnimNodeDataPos *)tmp;
    return s;
}
