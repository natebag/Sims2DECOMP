/* operator>>(EFile &, ISimInstance *&) at 0x800562B4 (64B) */

struct EStorable;
struct EFile;
struct ISimInstance;

EFile *operator_shr_EFile_EStorable(EFile *s, EStorable **out);

EFile *operator_shr_EFile_ISimInstance(EFile *s, ISimInstance **out) {
    EStorable *tmp;
    operator_shr_EFile_EStorable(s, &tmp);
    *out = (ISimInstance *)tmp;
    return s;
}
