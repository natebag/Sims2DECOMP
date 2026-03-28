/* operator>>(EFile &, ERShader *&) - 0x8031C69C (64 bytes) */

struct EStorable;

struct EFile {
    char pad[4];
};

EFile &operator_shr_EFile_EStorable(EFile &, EStorable *&);

struct ERShader;

EFile &operator_shr_EFile_ERShader(EFile &s, ERShader *&p)
{
    EStorable *tmp;
    operator_shr_EFile_EStorable(s, tmp);
    p = (ERShader *)tmp;
    return s;
}
