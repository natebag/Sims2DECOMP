/* operator>>(EFile &, EILight *&) - 0x80227944 (64 bytes) */

struct EStorable;

struct EFile {
    char pad[4];
};

EFile &operator_shr_EFile_EStorable(EFile &, EStorable *&);

struct EILight;

EFile &operator_shr_EFile_EILight(EFile &s, EILight *&p)
{
    EStorable *tmp;
    operator_shr_EFile_EStorable(s, tmp);
    p = (EILight *)tmp;
    return s;
}
