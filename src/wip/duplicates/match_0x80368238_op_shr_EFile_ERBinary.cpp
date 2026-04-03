/* operator>>(EFile &, ERBinary *&) - 0x80368238 (64 bytes) */

struct EStorable;

struct EFile {
    char pad[4];
};

EFile &operator_shr_EFile_EStorable(EFile &, EStorable *&);

struct ERBinary;

EFile &operator_shr_EFile_ERBinary(EFile &s, ERBinary *&p)
{
    EStorable *tmp;
    operator_shr_EFile_EStorable(s, tmp);
    p = (ERBinary *)tmp;
    return s;
}
