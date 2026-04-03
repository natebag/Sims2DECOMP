/* operator>>(EStream &, RParticle *&) - 0x8036B268 (64 bytes) */

struct EStorable;

struct EStream {
    char pad[4];
};

EStream &operator_shr_EStream_EStorable(EStream &, EStorable *&);

struct RParticle;

EStream &operator_shr_EStream_RParticle(EStream &s, RParticle *&p)
{
    EStorable *tmp;
    operator_shr_EStream_EStorable(s, tmp);
    p = (RParticle *)tmp;
    return s;
}
