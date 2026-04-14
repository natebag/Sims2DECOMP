/* operator>>(EStream &, ISimsMultiTileObjectModel *&) at 0x80051A0C (64B) */

struct EStorable;
struct EStream;
struct ISimsMultiTileObjectModel;

EStream *operator_shr_EStream_EStorable(EStream *s, EStorable **out);

EStream *operator_shr_EStream_ISimsMultiTileObjectModel(EStream *s, ISimsMultiTileObjectModel **out) {
    EStorable *tmp;
    operator_shr_EStream_EStorable(s, &tmp);
    *out = (ISimsMultiTileObjectModel *)tmp;
    return s;
}
