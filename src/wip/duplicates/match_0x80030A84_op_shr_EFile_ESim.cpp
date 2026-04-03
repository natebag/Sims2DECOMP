/* operator>>(EFile &, ESim *&) - 0x80030A84 (64 bytes) */

struct EStorable;

struct EFile {
    char pad[4];
};

EFile &operator_shr_EFile_EStorable(EFile &, EStorable *&);

struct ESim;

EFile &operator_shr_EFile_ESim(EFile &s, ESim *&p)
{
    EStorable *tmp;
    operator_shr_EFile_EStorable(s, tmp);
    p = (ESim *)tmp;
    return s;
}
