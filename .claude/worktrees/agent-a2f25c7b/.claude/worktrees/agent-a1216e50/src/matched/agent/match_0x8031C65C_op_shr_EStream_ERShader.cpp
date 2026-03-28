/* operator>>(EStream &, ERShader *&) - 0x8031C65C (64 bytes) */

struct EStorable;

struct EStream {
    char pad[4];
};

EStream &operator_shr_EStream_EStorable(EStream &, EStorable *&);

struct ERShader;

EStream &operator_shr_EStream_ERShader(EStream &s, ERShader *&p)
{
    EStorable *tmp;
    operator_shr_EStream_EStorable(s, tmp);
    p = (ERShader *)tmp;
    return s;
}
