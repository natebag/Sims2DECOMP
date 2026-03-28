/* operator>>(EStream &, ISimInstance *&) at 0x80056274 (64B) */

struct EStorable;
struct EStream;
struct ISimInstance;

EStream *operator_shr_EStream_EStorable(EStream *s, EStorable **out);

EStream *operator_shr_EStream_ISimInstance(EStream *s, ISimInstance **out) {
    EStorable *tmp;
    operator_shr_EStream_EStorable(s, &tmp);
    *out = (ISimInstance *)tmp;
    return s;
}
