/* operator>>(EFile &, ERTexture *&) - 0x80320AE8 (64 bytes) */

struct EStorable;

struct EFile {
    char pad[4];
};

EFile &operator_shr_EFile_EStorable(EFile &, EStorable *&);

struct ERTexture;

EFile &operator_shr_EFile_ERTexture(EFile &s, ERTexture *&p)
{
    EStorable *tmp;
    operator_shr_EFile_EStorable(s, tmp);
    p = (ERTexture *)tmp;
    return s;
}
