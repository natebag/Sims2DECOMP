/* operator>>(EStream &, ISimsCounterTopObject *&) at 0x8005202C (64B) */

struct EStorable;
struct EStream;
struct ISimsCounterTopObject;

EStream *operator_shr_EStream_EStorable(EStream *s, EStorable **out);

EStream *operator_shr_EStream_ISimsCounterTopObject(EStream *s, ISimsCounterTopObject **out) {
    EStorable *tmp;
    operator_shr_EStream_EStorable(s, &tmp);
    *out = (ISimsCounterTopObject *)tmp;
    return s;
}
