/* operator>>(EFile &, EISpotLight *&) - 0x8022B1A0 (64 bytes) */

struct EStorable;

struct EFile {
    char pad[4];
};

EFile &operator_shr_EFile_EStorable(EFile &, EStorable *&);

struct EISpotLight;

EFile &operator_shr_EFile_EISpotLight(EFile &s, EISpotLight *&p)
{
    EStorable *tmp;
    operator_shr_EFile_EStorable(s, tmp);
    p = (EISpotLight *)tmp;
    return s;
}
