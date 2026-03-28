/* operator>>(EFile &, EIFenceWall *&) - 0x80029850 (64 bytes) */

struct EStorable;

struct EFile {
    char pad[4];
};

EFile &operator_shr_EFile_EStorable(EFile &, EStorable *&);

struct EIFenceWall;

EFile &operator_shr_EFile_EIFenceWall(EFile &s, EIFenceWall *&p)
{
    EStorable *tmp;
    operator_shr_EFile_EStorable(s, tmp);
    p = (EIFenceWall *)tmp;
    return s;
}
