/* operator>>(EFile &, ERAmbientScore *&) - 0x80366958 (64 bytes) */

struct EStorable;

struct EFile {
    char pad[4];
};

EFile &operator_shr_EFile_EStorable(EFile &, EStorable *&);

struct ERAmbientScore;

EFile &operator_shr_EFile_ERAmbientScore(EFile &s, ERAmbientScore *&p)
{
    EStorable *tmp;
    operator_shr_EFile_EStorable(s, tmp);
    p = (ERAmbientScore *)tmp;
    return s;
}
