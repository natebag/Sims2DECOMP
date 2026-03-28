/* operator>>(EFile &, EREdithTreeSet *&) - 0x8030F444 (64 bytes) */

struct EStorable;

struct EFile {
    char pad[4];
};

EFile &operator_shr_EFile_EStorable(EFile &, EStorable *&);

struct EREdithTreeSet;

EFile &operator_shr_EFile_EREdithTreeSet(EFile &s, EREdithTreeSet *&p)
{
    EStorable *tmp;
    operator_shr_EFile_EStorable(s, tmp);
    p = (EREdithTreeSet *)tmp;
    return s;
}
