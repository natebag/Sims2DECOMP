/* operator>>(EFile &, EIPointAmbLight *&) - 0x802297D0 (64 bytes) */

struct EStorable;

struct EFile {
    char pad[4];
};

EFile &operator_shr_EFile_EStorable(EFile &, EStorable *&);

struct EIPointAmbLight;

EFile &operator_shr_EFile_EIPointAmbLight(EFile &s, EIPointAmbLight *&p)
{
    EStorable *tmp;
    operator_shr_EFile_EStorable(s, tmp);
    p = (EIPointAmbLight *)tmp;
    return s;
}
