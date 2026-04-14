/* operator>>(EFile &, ISimsObjectModel *&) at 0x8004C4C0 (64B) */

struct EStorable;
struct EFile;
struct ISimsObjectModel;

EFile *operator_shr_EFile_EStorable(EFile *s, EStorable **out);

EFile *operator_shr_EFile_ISimsObjectModel(EFile *s, ISimsObjectModel **out) {
    EStorable *tmp;
    operator_shr_EFile_EStorable(s, &tmp);
    *out = (ISimsObjectModel *)tmp;
    return s;
}
