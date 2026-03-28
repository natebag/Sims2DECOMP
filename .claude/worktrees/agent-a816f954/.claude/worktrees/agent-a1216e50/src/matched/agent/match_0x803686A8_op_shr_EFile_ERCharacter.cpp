/* operator>>(EFile &, ERCharacter *&) - 0x803686A8 (64 bytes) */

struct EStorable;

struct EFile {
    char pad[4];
};

EFile &operator_shr_EFile_EStorable(EFile &, EStorable *&);

struct ERCharacter;

EFile &operator_shr_EFile_ERCharacter(EFile &s, ERCharacter *&p)
{
    EStorable *tmp;
    operator_shr_EFile_EStorable(s, tmp);
    p = (ERCharacter *)tmp;
    return s;
}
