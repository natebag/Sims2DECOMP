/* operator>>(EFile &, ISimsMultiTileObjectModel *&) - 0x80051A4C (64 bytes) */

struct EStorable;

struct EFile {
    char pad[4];
};

EFile &operator_shr_EFile_EStorable(EFile &, EStorable *&);

struct ISimsMultiTileObjectModel;

EFile &operator_shr_EFile_ISimsMultiTileObjectModel(EFile &s, ISimsMultiTileObjectModel *&p)
{
    EStorable *tmp;
    operator_shr_EFile_EStorable(s, tmp);
    p = (ISimsMultiTileObjectModel *)tmp;
    return s;
}
