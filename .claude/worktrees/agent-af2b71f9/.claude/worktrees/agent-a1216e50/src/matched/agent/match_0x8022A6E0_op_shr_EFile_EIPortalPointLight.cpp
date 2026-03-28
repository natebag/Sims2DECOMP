/* operator>>(EFile &, EIPortalPointLight *&) - 0x8022A6E0 (64 bytes) */

struct EStorable;

struct EFile {
    char pad[4];
};

EFile &operator_shr_EFile_EStorable(EFile &, EStorable *&);

struct EIPortalPointLight;

EFile &operator_shr_EFile_EIPortalPointLight(EFile &s, EIPortalPointLight *&p)
{
    EStorable *tmp;
    operator_shr_EFile_EStorable(s, tmp);
    p = (EIPortalPointLight *)tmp;
    return s;
}
