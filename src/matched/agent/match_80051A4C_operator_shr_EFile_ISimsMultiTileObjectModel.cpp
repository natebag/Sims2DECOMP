/* operator>>(EFile &, ISimsMultiTileObjectModel *&) at 0x80051A4C (64B) */

struct EStorable;
struct EFile;
struct ISimsMultiTileObjectModel;

EFile *operator_shr_EFile_EStorable(EFile *s, EStorable **out);

EFile *operator_shr_EFile_ISimsMultiTileObjectModel(EFile *s, ISimsMultiTileObjectModel **out) {
    EStorable *tmp;
    operator_shr_EFile_EStorable(s, &tmp);
    *out = (ISimsMultiTileObjectModel *)tmp;
    return s;
}
