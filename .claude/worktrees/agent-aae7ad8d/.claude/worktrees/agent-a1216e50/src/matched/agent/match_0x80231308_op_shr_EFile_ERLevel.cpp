/* operator>>(EFile &, ERLevel *&) - 0x80231308 (64 bytes) */

struct EStorable;

struct EFile {
    char pad[4];
};

EFile &operator_shr_EFile_EStorable(EFile &, EStorable *&);

struct ERLevel;

EFile &operator_shr_EFile_ERLevel(EFile &s, ERLevel *&p)
{
    EStorable *tmp;
    operator_shr_EFile_EStorable(s, tmp);
    p = (ERLevel *)tmp;
    return s;
}
