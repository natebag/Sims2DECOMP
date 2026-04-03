/* operator>>(EFile &, EIWallPart *&) - 0x80029CEC (64 bytes) */

struct EStorable;

struct EFile {
    char pad[4];
};

EFile &operator_shr_EFile_EStorable(EFile &, EStorable *&);

struct EIWallPart;

EFile &operator_shr_EFile_EIWallPart(EFile &s, EIWallPart *&p)
{
    EStorable *tmp;
    operator_shr_EFile_EStorable(s, tmp);
    p = (EIWallPart *)tmp;
    return s;
}
