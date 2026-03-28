/* operator>>(EFile &, IShrubObject *&) at 0x800525A4 (64B) */

struct EStorable;
struct EFile;
struct IShrubObject;

EFile *operator_shr_EFile_EStorable(EFile *s, EStorable **out);

EFile *operator_shr_EFile_IShrubObject(EFile *s, IShrubObject **out) {
    EStorable *tmp;
    operator_shr_EFile_EStorable(s, &tmp);
    *out = (IShrubObject *)tmp;
    return s;
}
