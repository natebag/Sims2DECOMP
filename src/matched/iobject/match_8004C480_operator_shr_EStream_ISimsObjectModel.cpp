/* operator>>(EStream &, ISimsObjectModel *&) at 0x8004C480 (64B) */

struct EStorable;
struct EStream;
struct ISimsObjectModel;

EStream *operator_shr_EStream_EStorable(EStream *s, EStorable **out);

EStream *operator_shr_EStream_ISimsObjectModel(EStream *s, ISimsObjectModel **out) {
    EStorable *tmp;
    operator_shr_EStream_EStorable(s, &tmp);
    *out = (ISimsObjectModel *)tmp;
    return s;
}
