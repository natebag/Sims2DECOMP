/* operator>>(EFile &, ISimsWallObjectModel *&) at 0x80051130 (64B) */

struct EStorable;
struct EFile;
struct ISimsWallObjectModel;

EFile *operator_shr_EFile_EStorable(EFile *s, EStorable **out);

EFile *operator_shr_EFile_ISimsWallObjectModel(EFile *s, ISimsWallObjectModel **out) {
    EStorable *tmp;
    operator_shr_EFile_EStorable(s, &tmp);
    *out = (ISimsWallObjectModel *)tmp;
    return s;
}
