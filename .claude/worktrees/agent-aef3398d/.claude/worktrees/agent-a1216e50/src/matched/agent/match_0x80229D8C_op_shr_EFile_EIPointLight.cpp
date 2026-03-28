/* operator>>(EFile &, EIPointLight *&) - 0x80229D8C (64 bytes) */

struct EStorable;

struct EFile {
    char pad[4];
};

EFile &operator_shr_EFile_EStorable(EFile &, EStorable *&);

struct EIPointLight;

EFile &operator_shr_EFile_EIPointLight(EFile &s, EIPointLight *&p)
{
    EStorable *tmp;
    operator_shr_EFile_EStorable(s, tmp);
    p = (EIPointLight *)tmp;
    return s;
}
