/* operator>>(EFile &, ISimsWallObjectModel *&) - 0x80051130 (64 bytes) */

struct EStorable;

struct EFile {
    char pad[4];
};

EFile &operator_shr_EFile_EStorable(EFile &, EStorable *&);

struct ISimsWallObjectModel;

EFile &operator_shr_EFile_ISimsWallObjectModel(EFile &s, ISimsWallObjectModel *&p)
{
    EStorable *tmp;
    operator_shr_EFile_EStorable(s, tmp);
    p = (ISimsWallObjectModel *)tmp;
    return s;
}
