/* operator>>(EFile &, ISimsCounterTopObject *&) at 0x8005206C (64B) */

struct EStorable;
struct EFile;
struct ISimsCounterTopObject;

EFile *operator_shr_EFile_EStorable(EFile *s, EStorable **out);

EFile *operator_shr_EFile_ISimsCounterTopObject(EFile *s, ISimsCounterTopObject **out) {
    EStorable *tmp;
    operator_shr_EFile_EStorable(s, &tmp);
    *out = (ISimsCounterTopObject *)tmp;
    return s;
}
