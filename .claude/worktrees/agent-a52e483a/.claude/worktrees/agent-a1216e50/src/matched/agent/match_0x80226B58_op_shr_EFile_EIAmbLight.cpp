/* operator>>(EFile &, EIAmbLight *&) - 0x80226B58 (64 bytes) */

struct EStorable;

struct EFile {
    char pad[4];
};

EFile &operator_shr_EFile_EStorable(EFile &, EStorable *&);

struct EIAmbLight;

EFile &operator_shr_EFile_EIAmbLight(EFile &s, EIAmbLight *&p)
{
    EStorable *tmp;
    operator_shr_EFile_EStorable(s, tmp);
    p = (EIAmbLight *)tmp;
    return s;
}
