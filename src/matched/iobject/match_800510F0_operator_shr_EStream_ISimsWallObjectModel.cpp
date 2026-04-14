/* operator>>(EStream &, ISimsWallObjectModel *&) at 0x800510F0 (64B) */

struct EStorable;
struct EStream;
struct ISimsWallObjectModel;

EStream *operator_shr_EStream_EStorable(EStream *s, EStorable **out);

EStream *operator_shr_EStream_ISimsWallObjectModel(EStream *s, ISimsWallObjectModel **out) {
    EStorable *tmp;
    operator_shr_EStream_EStorable(s, &tmp);
    *out = (ISimsWallObjectModel *)tmp;
    return s;
}
