/* operator>>(EFile &, EIFloor *&) - 0x800471F4 (64 bytes) */

struct EStorable;

struct EFile {
    char pad[4];
};

EFile &operator_shr_EFile_EStorable(EFile &, EStorable *&);

struct EIFloor;

EFile &operator_shr_EFile_EIFloor(EFile &s, EIFloor *&p)
{
    EStorable *tmp;
    operator_shr_EFile_EStorable(s, tmp);
    p = (EIFloor *)tmp;
    return s;
}
