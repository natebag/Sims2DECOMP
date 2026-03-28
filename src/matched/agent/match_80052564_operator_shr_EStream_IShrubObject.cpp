/* operator>>(EStream &, IShrubObject *&) at 0x80052564 (64B) */

struct EStorable;
struct EStream;
struct IShrubObject;

EStream *operator_shr_EStream_EStorable(EStream *s, EStorable **out);

EStream *operator_shr_EStream_IShrubObject(EStream *s, IShrubObject **out) {
    EStorable *tmp;
    operator_shr_EStream_EStorable(s, &tmp);
    *out = (IShrubObject *)tmp;
    return s;
}
