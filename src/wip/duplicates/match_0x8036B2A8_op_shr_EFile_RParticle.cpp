/* operator>>(EFile &, RParticle *&) - 0x8036B2A8 (64 bytes) */

struct EStorable;

struct EFile {
    char pad[4];
};

EFile &operator_shr_EFile_EStorable(EFile &, EStorable *&);

struct RParticle;

EFile &operator_shr_EFile_RParticle(EFile &s, RParticle *&p)
{
    EStorable *tmp;
    operator_shr_EFile_EStorable(s, tmp);
    p = (RParticle *)tmp;
    return s;
}
